# Gather our source files in this directory.
set(
  scalc_src_files
    "${CMAKE_CURRENT_SOURCE_DIR}/placeholder.cpp"
)

# Build our executable from the source files.
add_executable(scalc ${scalc_src_files})
target_include_directories(scalc PUBLIC ${ANTLR_GEN_DIR})

# Ensure that the antlr4-runtime is available.
add_dependencies(scalc antlr)

# Add the antlr runtime and parser as libraries to link.
target_link_libraries(scalc parser antlr4-runtime)

# Symbolic link our executable to the base directory so we don't have to go searching for it.
symlink_to_bin("scalc")
