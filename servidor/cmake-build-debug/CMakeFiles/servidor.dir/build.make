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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/servidor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/servidor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/servidor.dir/flags.make

CMakeFiles/servidor.dir/main.cpp.o: CMakeFiles/servidor.dir/flags.make
CMakeFiles/servidor.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/servidor.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/main.cpp.o -c /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/main.cpp

CMakeFiles/servidor.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/main.cpp > CMakeFiles/servidor.dir/main.cpp.i

CMakeFiles/servidor.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/main.cpp -o CMakeFiles/servidor.dir/main.cpp.s

CMakeFiles/servidor.dir/ArchivoTexto.cpp.o: CMakeFiles/servidor.dir/flags.make
CMakeFiles/servidor.dir/ArchivoTexto.cpp.o: ../ArchivoTexto.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/servidor.dir/ArchivoTexto.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servidor.dir/ArchivoTexto.cpp.o -c /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/ArchivoTexto.cpp

CMakeFiles/servidor.dir/ArchivoTexto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servidor.dir/ArchivoTexto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/ArchivoTexto.cpp > CMakeFiles/servidor.dir/ArchivoTexto.cpp.i

CMakeFiles/servidor.dir/ArchivoTexto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servidor.dir/ArchivoTexto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/ArchivoTexto.cpp -o CMakeFiles/servidor.dir/ArchivoTexto.cpp.s

# Object files for target servidor
servidor_OBJECTS = \
"CMakeFiles/servidor.dir/main.cpp.o" \
"CMakeFiles/servidor.dir/ArchivoTexto.cpp.o"

# External object files for target servidor
servidor_EXTERNAL_OBJECTS =

servidor: CMakeFiles/servidor.dir/main.cpp.o
servidor: CMakeFiles/servidor.dir/ArchivoTexto.cpp.o
servidor: CMakeFiles/servidor.dir/build.make
servidor: CMakeFiles/servidor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable servidor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servidor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/servidor.dir/build: servidor

.PHONY : CMakeFiles/servidor.dir/build

CMakeFiles/servidor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/servidor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/servidor.dir/clean

CMakeFiles/servidor.dir/depend:
	cd /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/servidor/cmake-build-debug/CMakeFiles/servidor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/servidor.dir/depend

