# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/ilya/Documents/ClassProg/CppSampl/AVLtree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/Documents/ClassProg/CppSampl/AVLtree/build

# Include any dependencies generated for this target.
include CMakeFiles/tree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tree.dir/flags.make

CMakeFiles/tree.dir/main.cpp.o: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Documents/ClassProg/CppSampl/AVLtree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tree.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tree.dir/main.cpp.o -c /home/ilya/Documents/ClassProg/CppSampl/AVLtree/main.cpp

CMakeFiles/tree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Documents/ClassProg/CppSampl/AVLtree/main.cpp > CMakeFiles/tree.dir/main.cpp.i

CMakeFiles/tree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Documents/ClassProg/CppSampl/AVLtree/main.cpp -o CMakeFiles/tree.dir/main.cpp.s

CMakeFiles/tree.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/tree.dir/main.cpp.o.requires

CMakeFiles/tree.dir/main.cpp.o.provides: CMakeFiles/tree.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/tree.dir/build.make CMakeFiles/tree.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/tree.dir/main.cpp.o.provides

CMakeFiles/tree.dir/main.cpp.o.provides.build: CMakeFiles/tree.dir/main.cpp.o


CMakeFiles/tree.dir/AVLtree.cpp.o: CMakeFiles/tree.dir/flags.make
CMakeFiles/tree.dir/AVLtree.cpp.o: ../AVLtree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/Documents/ClassProg/CppSampl/AVLtree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tree.dir/AVLtree.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tree.dir/AVLtree.cpp.o -c /home/ilya/Documents/ClassProg/CppSampl/AVLtree/AVLtree.cpp

CMakeFiles/tree.dir/AVLtree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tree.dir/AVLtree.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ilya/Documents/ClassProg/CppSampl/AVLtree/AVLtree.cpp > CMakeFiles/tree.dir/AVLtree.cpp.i

CMakeFiles/tree.dir/AVLtree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tree.dir/AVLtree.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ilya/Documents/ClassProg/CppSampl/AVLtree/AVLtree.cpp -o CMakeFiles/tree.dir/AVLtree.cpp.s

CMakeFiles/tree.dir/AVLtree.cpp.o.requires:

.PHONY : CMakeFiles/tree.dir/AVLtree.cpp.o.requires

CMakeFiles/tree.dir/AVLtree.cpp.o.provides: CMakeFiles/tree.dir/AVLtree.cpp.o.requires
	$(MAKE) -f CMakeFiles/tree.dir/build.make CMakeFiles/tree.dir/AVLtree.cpp.o.provides.build
.PHONY : CMakeFiles/tree.dir/AVLtree.cpp.o.provides

CMakeFiles/tree.dir/AVLtree.cpp.o.provides.build: CMakeFiles/tree.dir/AVLtree.cpp.o


# Object files for target tree
tree_OBJECTS = \
"CMakeFiles/tree.dir/main.cpp.o" \
"CMakeFiles/tree.dir/AVLtree.cpp.o"

# External object files for target tree
tree_EXTERNAL_OBJECTS =

tree: CMakeFiles/tree.dir/main.cpp.o
tree: CMakeFiles/tree.dir/AVLtree.cpp.o
tree: CMakeFiles/tree.dir/build.make
tree: CMakeFiles/tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/Documents/ClassProg/CppSampl/AVLtree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tree.dir/build: tree

.PHONY : CMakeFiles/tree.dir/build

CMakeFiles/tree.dir/requires: CMakeFiles/tree.dir/main.cpp.o.requires
CMakeFiles/tree.dir/requires: CMakeFiles/tree.dir/AVLtree.cpp.o.requires

.PHONY : CMakeFiles/tree.dir/requires

CMakeFiles/tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tree.dir/clean

CMakeFiles/tree.dir/depend:
	cd /home/ilya/Documents/ClassProg/CppSampl/AVLtree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/Documents/ClassProg/CppSampl/AVLtree /home/ilya/Documents/ClassProg/CppSampl/AVLtree /home/ilya/Documents/ClassProg/CppSampl/AVLtree/build /home/ilya/Documents/ClassProg/CppSampl/AVLtree/build /home/ilya/Documents/ClassProg/CppSampl/AVLtree/build/CMakeFiles/tree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tree.dir/depend

