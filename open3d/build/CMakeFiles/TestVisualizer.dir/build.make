# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/iqlect/Downloads/cmake-3.13.2-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/iqlect/Downloads/cmake-3.13.2-Linux-x86_64/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/iqlect/Downloads/open3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/iqlect/Downloads/open3d/build

# Include any dependencies generated for this target.
include CMakeFiles/TestVisualizer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TestVisualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TestVisualizer.dir/flags.make

CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.o: CMakeFiles/TestVisualizer.dir/flags.make
CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.o: ../TestVisualizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/iqlect/Downloads/open3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.o -c /home/iqlect/Downloads/open3d/TestVisualizer.cpp

CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/iqlect/Downloads/open3d/TestVisualizer.cpp > CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.i

CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/iqlect/Downloads/open3d/TestVisualizer.cpp -o CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.s

# Object files for target TestVisualizer
TestVisualizer_OBJECTS = \
"CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.o"

# External object files for target TestVisualizer
TestVisualizer_EXTERNAL_OBJECTS =

TestVisualizer: CMakeFiles/TestVisualizer.dir/TestVisualizer.cpp.o
TestVisualizer: CMakeFiles/TestVisualizer.dir/build.make
TestVisualizer: /usr/lib/x86_64-linux-gnu/libGL.so
TestVisualizer: CMakeFiles/TestVisualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/iqlect/Downloads/open3d/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TestVisualizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestVisualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TestVisualizer.dir/build: TestVisualizer

.PHONY : CMakeFiles/TestVisualizer.dir/build

CMakeFiles/TestVisualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TestVisualizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TestVisualizer.dir/clean

CMakeFiles/TestVisualizer.dir/depend:
	cd /home/iqlect/Downloads/open3d/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/iqlect/Downloads/open3d /home/iqlect/Downloads/open3d /home/iqlect/Downloads/open3d/build /home/iqlect/Downloads/open3d/build /home/iqlect/Downloads/open3d/build/CMakeFiles/TestVisualizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TestVisualizer.dir/depend
