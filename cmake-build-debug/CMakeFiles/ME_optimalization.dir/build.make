# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\JF\repozytoria\ME_optimalization

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\JF\repozytoria\ME_optimalization\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ME_optimalization.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ME_optimalization.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ME_optimalization.dir/flags.make

CMakeFiles/ME_optimalization.dir/metalsheet.cpp.obj: CMakeFiles/ME_optimalization.dir/flags.make
CMakeFiles/ME_optimalization.dir/metalsheet.cpp.obj: ../metalsheet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\JF\repozytoria\ME_optimalization\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ME_optimalization.dir/metalsheet.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ME_optimalization.dir\metalsheet.cpp.obj -c C:\Users\JF\repozytoria\ME_optimalization\metalsheet.cpp

CMakeFiles/ME_optimalization.dir/metalsheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ME_optimalization.dir/metalsheet.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\JF\repozytoria\ME_optimalization\metalsheet.cpp > CMakeFiles\ME_optimalization.dir\metalsheet.cpp.i

CMakeFiles/ME_optimalization.dir/metalsheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ME_optimalization.dir/metalsheet.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\JF\repozytoria\ME_optimalization\metalsheet.cpp -o CMakeFiles\ME_optimalization.dir\metalsheet.cpp.s

# Object files for target ME_optimalization
ME_optimalization_OBJECTS = \
"CMakeFiles/ME_optimalization.dir/metalsheet.cpp.obj"

# External object files for target ME_optimalization
ME_optimalization_EXTERNAL_OBJECTS =

ME_optimalization.exe: CMakeFiles/ME_optimalization.dir/metalsheet.cpp.obj
ME_optimalization.exe: CMakeFiles/ME_optimalization.dir/build.make
ME_optimalization.exe: CMakeFiles/ME_optimalization.dir/linklibs.rsp
ME_optimalization.exe: CMakeFiles/ME_optimalization.dir/objects1.rsp
ME_optimalization.exe: CMakeFiles/ME_optimalization.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\JF\repozytoria\ME_optimalization\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ME_optimalization.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ME_optimalization.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ME_optimalization.dir/build: ME_optimalization.exe

.PHONY : CMakeFiles/ME_optimalization.dir/build

CMakeFiles/ME_optimalization.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ME_optimalization.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ME_optimalization.dir/clean

CMakeFiles/ME_optimalization.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\JF\repozytoria\ME_optimalization C:\Users\JF\repozytoria\ME_optimalization C:\Users\JF\repozytoria\ME_optimalization\cmake-build-debug C:\Users\JF\repozytoria\ME_optimalization\cmake-build-debug C:\Users\JF\repozytoria\ME_optimalization\cmake-build-debug\CMakeFiles\ME_optimalization.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ME_optimalization.dir/depend

