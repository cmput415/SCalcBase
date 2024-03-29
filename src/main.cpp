#include "SCalcLexer.h"
#include "SCalcParser.h"

#include "ANTLRFileStream.h"
#include "CommonTokenStream.h"
#include "tree/ParseTree.h"
#include "tree/ParseTreeWalker.h"

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  if (argc < 4) {
    std::cout << "Missing required argument.\n"
              << "Required arguments: <mode> <input file path> <output file path>\n";
    return 1;
  }

  // Open the file then parse and lex it.
  antlr4::ANTLRFileStream afs;
  afs.loadFromFile(argv[2]);
  scalc::SCalcLexer lexer(&afs);
  antlr4::CommonTokenStream tokens(&lexer);
  scalc::SCalcParser parser(&tokens);

  // Get the root of the parse tree. Use your base rule name.
  antlr4::tree::ParseTree *tree = parser.file();

  // HOW TO USE A LISTENER
  // Make the listener
  // MyListener listener;
  // Walk the tree
  // antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

  // HOW TO USE A VISITOR
  // Make the visitor
  // MyVisitor visitor;
  // Visit the tree
  // visitor.visit(tree);

  // HOW TO WRITE OUT.
  // std::ofstream out(argv[3]);
  // out << "This is out...\n";

  return 0;
}
