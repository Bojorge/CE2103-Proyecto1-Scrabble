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
CMAKE_SOURCE_DIR = /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cliente.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cliente.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cliente.dir/flags.make

CMakeFiles/cliente.dir/main.cpp.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cliente.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/main.cpp.o -c /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/main.cpp

CMakeFiles/cliente.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/main.cpp > CMakeFiles/cliente.dir/main.cpp.i

CMakeFiles/cliente.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/main.cpp -o CMakeFiles/cliente.dir/main.cpp.s

CMakeFiles/cliente.dir/TCPclient.cpp.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/TCPclient.cpp.o: ../TCPclient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cliente.dir/TCPclient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/TCPclient.cpp.o -c /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/TCPclient.cpp

CMakeFiles/cliente.dir/TCPclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/TCPclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/TCPclient.cpp > CMakeFiles/cliente.dir/TCPclient.cpp.i

CMakeFiles/cliente.dir/TCPclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/TCPclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/TCPclient.cpp -o CMakeFiles/cliente.dir/TCPclient.cpp.s

CMakeFiles/cliente.dir/Serial.cpp.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/Serial.cpp.o: ../Serial.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cliente.dir/Serial.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/Serial.cpp.o -c /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/Serial.cpp

CMakeFiles/cliente.dir/Serial.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/Serial.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/Serial.cpp > CMakeFiles/cliente.dir/Serial.cpp.i

CMakeFiles/cliente.dir/Serial.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/Serial.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/Serial.cpp -o CMakeFiles/cliente.dir/Serial.cpp.s

CMakeFiles/cliente.dir/ArchivoTexto.cpp.o: CMakeFiles/cliente.dir/flags.make
CMakeFiles/cliente.dir/ArchivoTexto.cpp.o: ../ArchivoTexto.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cliente.dir/ArchivoTexto.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cliente.dir/ArchivoTexto.cpp.o -c /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/ArchivoTexto.cpp

CMakeFiles/cliente.dir/ArchivoTexto.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cliente.dir/ArchivoTexto.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/ArchivoTexto.cpp > CMakeFiles/cliente.dir/ArchivoTexto.cpp.i

CMakeFiles/cliente.dir/ArchivoTexto.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cliente.dir/ArchivoTexto.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/ArchivoTexto.cpp -o CMakeFiles/cliente.dir/ArchivoTexto.cpp.s

# Object files for target cliente
cliente_OBJECTS = \
"CMakeFiles/cliente.dir/main.cpp.o" \
"CMakeFiles/cliente.dir/TCPclient.cpp.o" \
"CMakeFiles/cliente.dir/Serial.cpp.o" \
"CMakeFiles/cliente.dir/ArchivoTexto.cpp.o"

# External object files for target cliente
cliente_EXTERNAL_OBJECTS =

cliente: CMakeFiles/cliente.dir/main.cpp.o
cliente: CMakeFiles/cliente.dir/TCPclient.cpp.o
cliente: CMakeFiles/cliente.dir/Serial.cpp.o
cliente: CMakeFiles/cliente.dir/ArchivoTexto.cpp.o
cliente: CMakeFiles/cliente.dir/build.make
cliente: CMakeFiles/cliente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable cliente"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cliente.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cliente.dir/build: cliente

.PHONY : CMakeFiles/cliente.dir/build

CMakeFiles/cliente.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cliente.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cliente.dir/clean

CMakeFiles/cliente.dir/depend:
	cd /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug /home/manuel/CLionProjects/CE2103-Proyecto1-Scrabble/cliente/cmake-build-debug/CMakeFiles/cliente.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cliente.dir/depend

