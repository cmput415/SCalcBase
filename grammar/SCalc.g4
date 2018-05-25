grammar SCalc;

file: .*? EOF;

// Skip whitespace
WS : [ \t\r\n]+ -> skip ;
