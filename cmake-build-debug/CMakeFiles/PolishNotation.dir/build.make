# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\program\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\program\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\dz\PolishNotation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\dz\PolishNotation\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PolishNotation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PolishNotation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PolishNotation.dir/flags.make

CMakeFiles/PolishNotation.dir/main.cpp.obj: CMakeFiles/PolishNotation.dir/flags.make
CMakeFiles/PolishNotation.dir/main.cpp.obj: CMakeFiles/PolishNotation.dir/includes_CXX.rsp
CMakeFiles/PolishNotation.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\dz\PolishNotation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PolishNotation.dir/main.cpp.obj"
	D:\program\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PolishNotation.dir\main.cpp.obj -c D:\dz\PolishNotation\main.cpp

CMakeFiles/PolishNotation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PolishNotation.dir/main.cpp.i"
	D:\program\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\dz\PolishNotation\main.cpp > CMakeFiles\PolishNotation.dir\main.cpp.i

CMakeFiles/PolishNotation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PolishNotation.dir/main.cpp.s"
	D:\program\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\dz\PolishNotation\main.cpp -o CMakeFiles\PolishNotation.dir\main.cpp.s

# Object files for target PolishNotation
PolishNotation_OBJECTS = \
"CMakeFiles/PolishNotation.dir/main.cpp.obj"

# External object files for target PolishNotation
PolishNotation_EXTERNAL_OBJECTS =

PolishNotation.exe: CMakeFiles/PolishNotation.dir/main.cpp.obj
PolishNotation.exe: CMakeFiles/PolishNotation.dir/build.make
PolishNotation.exe: lib/libgtestd.a
PolishNotation.exe: lib/libgtest_maind.a
PolishNotation.exe: lib/libgtestd.a
PolishNotation.exe: CMakeFiles/PolishNotation.dir/linklibs.rsp
PolishNotation.exe: CMakeFiles/PolishNotation.dir/objects1.rsp
PolishNotation.exe: CMakeFiles/PolishNotation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\dz\PolishNotation\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PolishNotation.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PolishNotation.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PolishNotation.dir/build: PolishNotation.exe

.PHONY : CMakeFiles/PolishNotation.dir/build

CMakeFiles/PolishNotation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PolishNotation.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PolishNotation.dir/clean

CMakeFiles/PolishNotation.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\dz\PolishNotation D:\dz\PolishNotation D:\dz\PolishNotation\cmake-build-debug D:\dz\PolishNotation\cmake-build-debug D:\dz\PolishNotation\cmake-build-debug\CMakeFiles\PolishNotation.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PolishNotation.dir/depend

