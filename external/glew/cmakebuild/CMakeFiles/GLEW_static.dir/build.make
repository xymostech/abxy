# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xymostech/Random/testcompile/glew

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xymostech/Random/testcompile/glew/cmakebuild

# Include any dependencies generated for this target.
include CMakeFiles/GLEW_static.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GLEW_static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GLEW_static.dir/flags.make

CMakeFiles/GLEW_static.dir/src/glew.c.o: CMakeFiles/GLEW_static.dir/flags.make
CMakeFiles/GLEW_static.dir/src/glew.c.o: ../src/glew.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/xymostech/Random/testcompile/glew/cmakebuild/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/GLEW_static.dir/src/glew.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -DGLEW_STATIC -o CMakeFiles/GLEW_static.dir/src/glew.c.o   -c /home/xymostech/Random/testcompile/glew/src/glew.c

CMakeFiles/GLEW_static.dir/src/glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW_static.dir/src/glew.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -DGLEW_STATIC -E /home/xymostech/Random/testcompile/glew/src/glew.c > CMakeFiles/GLEW_static.dir/src/glew.c.i

CMakeFiles/GLEW_static.dir/src/glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW_static.dir/src/glew.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -DGLEW_STATIC -S /home/xymostech/Random/testcompile/glew/src/glew.c -o CMakeFiles/GLEW_static.dir/src/glew.c.s

CMakeFiles/GLEW_static.dir/src/glew.c.o.requires:
.PHONY : CMakeFiles/GLEW_static.dir/src/glew.c.o.requires

CMakeFiles/GLEW_static.dir/src/glew.c.o.provides: CMakeFiles/GLEW_static.dir/src/glew.c.o.requires
	$(MAKE) -f CMakeFiles/GLEW_static.dir/build.make CMakeFiles/GLEW_static.dir/src/glew.c.o.provides.build
.PHONY : CMakeFiles/GLEW_static.dir/src/glew.c.o.provides

CMakeFiles/GLEW_static.dir/src/glew.c.o.provides.build: CMakeFiles/GLEW_static.dir/src/glew.c.o

# Object files for target GLEW_static
GLEW_static_OBJECTS = \
"CMakeFiles/GLEW_static.dir/src/glew.c.o"

# External object files for target GLEW_static
GLEW_static_EXTERNAL_OBJECTS =

lib/libGLEW_static.a: CMakeFiles/GLEW_static.dir/src/glew.c.o
lib/libGLEW_static.a: CMakeFiles/GLEW_static.dir/build.make
lib/libGLEW_static.a: CMakeFiles/GLEW_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library lib/libGLEW_static.a"
	$(CMAKE_COMMAND) -P CMakeFiles/GLEW_static.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GLEW_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GLEW_static.dir/build: lib/libGLEW_static.a
.PHONY : CMakeFiles/GLEW_static.dir/build

CMakeFiles/GLEW_static.dir/requires: CMakeFiles/GLEW_static.dir/src/glew.c.o.requires
.PHONY : CMakeFiles/GLEW_static.dir/requires

CMakeFiles/GLEW_static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GLEW_static.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GLEW_static.dir/clean

CMakeFiles/GLEW_static.dir/depend:
	cd /home/xymostech/Random/testcompile/glew/cmakebuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xymostech/Random/testcompile/glew /home/xymostech/Random/testcompile/glew /home/xymostech/Random/testcompile/glew/cmakebuild /home/xymostech/Random/testcompile/glew/cmakebuild /home/xymostech/Random/testcompile/glew/cmakebuild/CMakeFiles/GLEW_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GLEW_static.dir/depend
