# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangjiani/wjn/Code/Leetcode-cpp/21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/21.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/21.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/21.dir/flags.make

CMakeFiles/21.dir/main.cpp.o: CMakeFiles/21.dir/flags.make
CMakeFiles/21.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/21.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/21.dir/main.cpp.o -c /Users/wangjiani/wjn/Code/Leetcode-cpp/21/main.cpp

CMakeFiles/21.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/21.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangjiani/wjn/Code/Leetcode-cpp/21/main.cpp > CMakeFiles/21.dir/main.cpp.i

CMakeFiles/21.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/21.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangjiani/wjn/Code/Leetcode-cpp/21/main.cpp -o CMakeFiles/21.dir/main.cpp.s

# Object files for target 21
21_OBJECTS = \
"CMakeFiles/21.dir/main.cpp.o"

# External object files for target 21
21_EXTERNAL_OBJECTS =

21: CMakeFiles/21.dir/main.cpp.o
21: CMakeFiles/21.dir/build.make
21: CMakeFiles/21.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 21"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/21.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/21.dir/build: 21

.PHONY : CMakeFiles/21.dir/build

CMakeFiles/21.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/21.dir/cmake_clean.cmake
.PHONY : CMakeFiles/21.dir/clean

CMakeFiles/21.dir/depend:
	cd /Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangjiani/wjn/Code/Leetcode-cpp/21 /Users/wangjiani/wjn/Code/Leetcode-cpp/21 /Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug /Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug /Users/wangjiani/wjn/Code/Leetcode-cpp/21/cmake-build-debug/CMakeFiles/21.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/21.dir/depend

