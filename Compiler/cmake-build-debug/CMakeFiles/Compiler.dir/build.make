# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Informatica/University/Compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Informatica/University/Compiler/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Compiler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compiler.dir/flags.make

CMakeFiles/Compiler.dir/main.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Informatica/University/Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Compiler.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/main.cpp.o -c /mnt/d/Informatica/University/Compiler/main.cpp

CMakeFiles/Compiler.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Informatica/University/Compiler/main.cpp > CMakeFiles/Compiler.dir/main.cpp.i

CMakeFiles/Compiler.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Informatica/University/Compiler/main.cpp -o CMakeFiles/Compiler.dir/main.cpp.s

CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.o: ../SymbolTable/RedBlackTree/RedBlackTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Informatica/University/Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.o -c /mnt/d/Informatica/University/Compiler/SymbolTable/RedBlackTree/RedBlackTree.cpp

CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Informatica/University/Compiler/SymbolTable/RedBlackTree/RedBlackTree.cpp > CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.i

CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Informatica/University/Compiler/SymbolTable/RedBlackTree/RedBlackTree.cpp -o CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.s

CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.o: ../SymbolTable/RedBlackTree/rbt_testing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Informatica/University/Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.o -c /mnt/d/Informatica/University/Compiler/SymbolTable/RedBlackTree/rbt_testing.cpp

CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Informatica/University/Compiler/SymbolTable/RedBlackTree/rbt_testing.cpp > CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.i

CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Informatica/University/Compiler/SymbolTable/RedBlackTree/rbt_testing.cpp -o CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.s

CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.o: ../SymbolTable/SymbolTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Informatica/University/Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.o -c /mnt/d/Informatica/University/Compiler/SymbolTable/SymbolTable.cpp

CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Informatica/University/Compiler/SymbolTable/SymbolTable.cpp > CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.i

CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Informatica/University/Compiler/SymbolTable/SymbolTable.cpp -o CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.s

# Object files for target Compiler
Compiler_OBJECTS = \
"CMakeFiles/Compiler.dir/main.cpp.o" \
"CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.o" \
"CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.o" \
"CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.o"

# External object files for target Compiler
Compiler_EXTERNAL_OBJECTS =

Compiler: CMakeFiles/Compiler.dir/main.cpp.o
Compiler: CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/RedBlackTree.cpp.o
Compiler: CMakeFiles/Compiler.dir/SymbolTable/RedBlackTree/rbt_testing.cpp.o
Compiler: CMakeFiles/Compiler.dir/SymbolTable/SymbolTable.cpp.o
Compiler: CMakeFiles/Compiler.dir/build.make
Compiler: CMakeFiles/Compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Informatica/University/Compiler/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compiler.dir/build: Compiler

.PHONY : CMakeFiles/Compiler.dir/build

CMakeFiles/Compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Compiler.dir/clean

CMakeFiles/Compiler.dir/depend:
	cd /mnt/d/Informatica/University/Compiler/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Informatica/University/Compiler /mnt/d/Informatica/University/Compiler /mnt/d/Informatica/University/Compiler/cmake-build-debug /mnt/d/Informatica/University/Compiler/cmake-build-debug /mnt/d/Informatica/University/Compiler/cmake-build-debug/CMakeFiles/Compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compiler.dir/depend

