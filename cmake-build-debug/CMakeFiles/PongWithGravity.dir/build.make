# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /home/felix/Downloads/CLion-2024.1.2/clion-2024.1.2/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/felix/Downloads/CLion-2024.1.2/clion-2024.1.2/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felix/gravity-pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/gravity-pong/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PongWithGravity.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PongWithGravity.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PongWithGravity.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PongWithGravity.dir/flags.make

CMakeFiles/PongWithGravity.dir/src/main.c.o: CMakeFiles/PongWithGravity.dir/flags.make
CMakeFiles/PongWithGravity.dir/src/main.c.o: /home/felix/gravity-pong/src/main.c
CMakeFiles/PongWithGravity.dir/src/main.c.o: CMakeFiles/PongWithGravity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/felix/gravity-pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PongWithGravity.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PongWithGravity.dir/src/main.c.o -MF CMakeFiles/PongWithGravity.dir/src/main.c.o.d -o CMakeFiles/PongWithGravity.dir/src/main.c.o -c /home/felix/gravity-pong/src/main.c

CMakeFiles/PongWithGravity.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/PongWithGravity.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/felix/gravity-pong/src/main.c > CMakeFiles/PongWithGravity.dir/src/main.c.i

CMakeFiles/PongWithGravity.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/PongWithGravity.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/felix/gravity-pong/src/main.c -o CMakeFiles/PongWithGravity.dir/src/main.c.s

CMakeFiles/PongWithGravity.dir/src/game.c.o: CMakeFiles/PongWithGravity.dir/flags.make
CMakeFiles/PongWithGravity.dir/src/game.c.o: /home/felix/gravity-pong/src/game.c
CMakeFiles/PongWithGravity.dir/src/game.c.o: CMakeFiles/PongWithGravity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/felix/gravity-pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/PongWithGravity.dir/src/game.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PongWithGravity.dir/src/game.c.o -MF CMakeFiles/PongWithGravity.dir/src/game.c.o.d -o CMakeFiles/PongWithGravity.dir/src/game.c.o -c /home/felix/gravity-pong/src/game.c

CMakeFiles/PongWithGravity.dir/src/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/PongWithGravity.dir/src/game.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/felix/gravity-pong/src/game.c > CMakeFiles/PongWithGravity.dir/src/game.c.i

CMakeFiles/PongWithGravity.dir/src/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/PongWithGravity.dir/src/game.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/felix/gravity-pong/src/game.c -o CMakeFiles/PongWithGravity.dir/src/game.c.s

CMakeFiles/PongWithGravity.dir/src/graphics.c.o: CMakeFiles/PongWithGravity.dir/flags.make
CMakeFiles/PongWithGravity.dir/src/graphics.c.o: /home/felix/gravity-pong/src/graphics.c
CMakeFiles/PongWithGravity.dir/src/graphics.c.o: CMakeFiles/PongWithGravity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/felix/gravity-pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/PongWithGravity.dir/src/graphics.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PongWithGravity.dir/src/graphics.c.o -MF CMakeFiles/PongWithGravity.dir/src/graphics.c.o.d -o CMakeFiles/PongWithGravity.dir/src/graphics.c.o -c /home/felix/gravity-pong/src/graphics.c

CMakeFiles/PongWithGravity.dir/src/graphics.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/PongWithGravity.dir/src/graphics.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/felix/gravity-pong/src/graphics.c > CMakeFiles/PongWithGravity.dir/src/graphics.c.i

CMakeFiles/PongWithGravity.dir/src/graphics.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/PongWithGravity.dir/src/graphics.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/felix/gravity-pong/src/graphics.c -o CMakeFiles/PongWithGravity.dir/src/graphics.c.s

CMakeFiles/PongWithGravity.dir/src/input.c.o: CMakeFiles/PongWithGravity.dir/flags.make
CMakeFiles/PongWithGravity.dir/src/input.c.o: /home/felix/gravity-pong/src/input.c
CMakeFiles/PongWithGravity.dir/src/input.c.o: CMakeFiles/PongWithGravity.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/felix/gravity-pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/PongWithGravity.dir/src/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/PongWithGravity.dir/src/input.c.o -MF CMakeFiles/PongWithGravity.dir/src/input.c.o.d -o CMakeFiles/PongWithGravity.dir/src/input.c.o -c /home/felix/gravity-pong/src/input.c

CMakeFiles/PongWithGravity.dir/src/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/PongWithGravity.dir/src/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/felix/gravity-pong/src/input.c > CMakeFiles/PongWithGravity.dir/src/input.c.i

CMakeFiles/PongWithGravity.dir/src/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/PongWithGravity.dir/src/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/felix/gravity-pong/src/input.c -o CMakeFiles/PongWithGravity.dir/src/input.c.s

# Object files for target PongWithGravity
PongWithGravity_OBJECTS = \
"CMakeFiles/PongWithGravity.dir/src/main.c.o" \
"CMakeFiles/PongWithGravity.dir/src/game.c.o" \
"CMakeFiles/PongWithGravity.dir/src/graphics.c.o" \
"CMakeFiles/PongWithGravity.dir/src/input.c.o"

# External object files for target PongWithGravity
PongWithGravity_EXTERNAL_OBJECTS =

PongWithGravity: CMakeFiles/PongWithGravity.dir/src/main.c.o
PongWithGravity: CMakeFiles/PongWithGravity.dir/src/game.c.o
PongWithGravity: CMakeFiles/PongWithGravity.dir/src/graphics.c.o
PongWithGravity: CMakeFiles/PongWithGravity.dir/src/input.c.o
PongWithGravity: CMakeFiles/PongWithGravity.dir/build.make
PongWithGravity: /usr/lib/x86_64-linux-gnu/libSDL2.so
PongWithGravity: CMakeFiles/PongWithGravity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/felix/gravity-pong/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable PongWithGravity"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PongWithGravity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PongWithGravity.dir/build: PongWithGravity
.PHONY : CMakeFiles/PongWithGravity.dir/build

CMakeFiles/PongWithGravity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PongWithGravity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PongWithGravity.dir/clean

CMakeFiles/PongWithGravity.dir/depend:
	cd /home/felix/gravity-pong/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/gravity-pong /home/felix/gravity-pong /home/felix/gravity-pong/cmake-build-debug /home/felix/gravity-pong/cmake-build-debug /home/felix/gravity-pong/cmake-build-debug/CMakeFiles/PongWithGravity.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/PongWithGravity.dir/depend

