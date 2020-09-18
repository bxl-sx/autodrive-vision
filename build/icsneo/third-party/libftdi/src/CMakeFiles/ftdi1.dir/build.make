# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xl/projects/autodrive/autodrive-vision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xl/projects/autodrive/autodrive-vision/build

# Include any dependencies generated for this target.
include icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/depend.make

# Include the progress variables for this target.
include icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/progress.make

# Include the compile flags for this target's objects.
include icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/flags.make

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi.c.o: icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/flags.make
icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi.c.o: /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xl/projects/autodrive/autodrive-vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi.c.o"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ftdi1.dir/ftdi.c.o -c /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi.c

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ftdi1.dir/ftdi.c.i"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi.c > CMakeFiles/ftdi1.dir/ftdi.c.i

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ftdi1.dir/ftdi.c.s"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi.c -o CMakeFiles/ftdi1.dir/ftdi.c.s

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi_stream.c.o: icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/flags.make
icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi_stream.c.o: /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi_stream.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xl/projects/autodrive/autodrive-vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi_stream.c.o"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ftdi1.dir/ftdi_stream.c.o -c /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi_stream.c

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi_stream.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ftdi1.dir/ftdi_stream.c.i"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi_stream.c > CMakeFiles/ftdi1.dir/ftdi_stream.c.i

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi_stream.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ftdi1.dir/ftdi_stream.c.s"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src/ftdi_stream.c -o CMakeFiles/ftdi1.dir/ftdi_stream.c.s

# Object files for target ftdi1
ftdi1_OBJECTS = \
"CMakeFiles/ftdi1.dir/ftdi.c.o" \
"CMakeFiles/ftdi1.dir/ftdi_stream.c.o"

# External object files for target ftdi1
ftdi1_EXTERNAL_OBJECTS =

icsneo/third-party/libftdi/src/libftdi1.so.2.4.0: icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi.c.o
icsneo/third-party/libftdi/src/libftdi1.so.2.4.0: icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/ftdi_stream.c.o
icsneo/third-party/libftdi/src/libftdi1.so.2.4.0: icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/build.make
icsneo/third-party/libftdi/src/libftdi1.so.2.4.0: /usr/lib/x86_64-linux-gnu/libusb-1.0.so
icsneo/third-party/libftdi/src/libftdi1.so.2.4.0: icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xl/projects/autodrive/autodrive-vision/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library libftdi1.so"
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ftdi1.dir/link.txt --verbose=$(VERBOSE)
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && $(CMAKE_COMMAND) -E cmake_symlink_library libftdi1.so.2.4.0 libftdi1.so.2 libftdi1.so

icsneo/third-party/libftdi/src/libftdi1.so.2: icsneo/third-party/libftdi/src/libftdi1.so.2.4.0
	@$(CMAKE_COMMAND) -E touch_nocreate icsneo/third-party/libftdi/src/libftdi1.so.2

icsneo/third-party/libftdi/src/libftdi1.so: icsneo/third-party/libftdi/src/libftdi1.so.2.4.0
	@$(CMAKE_COMMAND) -E touch_nocreate icsneo/third-party/libftdi/src/libftdi1.so

# Rule to build all files generated by this target.
icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/build: icsneo/third-party/libftdi/src/libftdi1.so

.PHONY : icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/build

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/clean:
	cd /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src && $(CMAKE_COMMAND) -P CMakeFiles/ftdi1.dir/cmake_clean.cmake
.PHONY : icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/clean

icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/depend:
	cd /home/xl/projects/autodrive/autodrive-vision/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xl/projects/autodrive/autodrive-vision /home/xl/projects/autodrive/thirdparty/libicsneo/third-party/libftdi/src /home/xl/projects/autodrive/autodrive-vision/build /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src /home/xl/projects/autodrive/autodrive-vision/build/icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : icsneo/third-party/libftdi/src/CMakeFiles/ftdi1.dir/depend
