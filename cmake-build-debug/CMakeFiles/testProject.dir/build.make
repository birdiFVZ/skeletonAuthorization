# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /home/birdi/Programme/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/birdi/Programme/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/birdi/CLionProjects/skeletonAuthorization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/testProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testProject.dir/flags.make

CMakeFiles/testProject.dir/main.cpp.o: CMakeFiles/testProject.dir/flags.make
CMakeFiles/testProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testProject.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testProject.dir/main.cpp.o -c /home/birdi/CLionProjects/skeletonAuthorization/main.cpp

CMakeFiles/testProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testProject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/birdi/CLionProjects/skeletonAuthorization/main.cpp > CMakeFiles/testProject.dir/main.cpp.i

CMakeFiles/testProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testProject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/birdi/CLionProjects/skeletonAuthorization/main.cpp -o CMakeFiles/testProject.dir/main.cpp.s

CMakeFiles/testProject.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/testProject.dir/main.cpp.o.requires

CMakeFiles/testProject.dir/main.cpp.o.provides: CMakeFiles/testProject.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/testProject.dir/build.make CMakeFiles/testProject.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/testProject.dir/main.cpp.o.provides

CMakeFiles/testProject.dir/main.cpp.o.provides.build: CMakeFiles/testProject.dir/main.cpp.o


CMakeFiles/testProject.dir/functions.cpp.o: CMakeFiles/testProject.dir/flags.make
CMakeFiles/testProject.dir/functions.cpp.o: ../functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testProject.dir/functions.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testProject.dir/functions.cpp.o -c /home/birdi/CLionProjects/skeletonAuthorization/functions.cpp

CMakeFiles/testProject.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testProject.dir/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/birdi/CLionProjects/skeletonAuthorization/functions.cpp > CMakeFiles/testProject.dir/functions.cpp.i

CMakeFiles/testProject.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testProject.dir/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/birdi/CLionProjects/skeletonAuthorization/functions.cpp -o CMakeFiles/testProject.dir/functions.cpp.s

CMakeFiles/testProject.dir/functions.cpp.o.requires:

.PHONY : CMakeFiles/testProject.dir/functions.cpp.o.requires

CMakeFiles/testProject.dir/functions.cpp.o.provides: CMakeFiles/testProject.dir/functions.cpp.o.requires
	$(MAKE) -f CMakeFiles/testProject.dir/build.make CMakeFiles/testProject.dir/functions.cpp.o.provides.build
.PHONY : CMakeFiles/testProject.dir/functions.cpp.o.provides

CMakeFiles/testProject.dir/functions.cpp.o.provides.build: CMakeFiles/testProject.dir/functions.cpp.o


# Object files for target testProject
testProject_OBJECTS = \
"CMakeFiles/testProject.dir/main.cpp.o" \
"CMakeFiles/testProject.dir/functions.cpp.o"

# External object files for target testProject
testProject_EXTERNAL_OBJECTS =

testProject: CMakeFiles/testProject.dir/main.cpp.o
testProject: CMakeFiles/testProject.dir/functions.cpp.o
testProject: CMakeFiles/testProject.dir/build.make
testProject: CMakeFiles/testProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable testProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testProject.dir/build: testProject

.PHONY : CMakeFiles/testProject.dir/build

CMakeFiles/testProject.dir/requires: CMakeFiles/testProject.dir/main.cpp.o.requires
CMakeFiles/testProject.dir/requires: CMakeFiles/testProject.dir/functions.cpp.o.requires

.PHONY : CMakeFiles/testProject.dir/requires

CMakeFiles/testProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testProject.dir/clean

CMakeFiles/testProject.dir/depend:
	cd /home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/birdi/CLionProjects/skeletonAuthorization /home/birdi/CLionProjects/skeletonAuthorization /home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug /home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug /home/birdi/CLionProjects/skeletonAuthorization/cmake-build-debug/CMakeFiles/testProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testProject.dir/depend

