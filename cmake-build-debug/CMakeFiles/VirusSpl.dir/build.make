# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spl211/CLionProjects/VirusSpl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spl211/CLionProjects/VirusSpl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VirusSpl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VirusSpl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VirusSpl.dir/flags.make

CMakeFiles/VirusSpl.dir/main.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VirusSpl.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/main.cpp.o -c /home/spl211/CLionProjects/VirusSpl/main.cpp

CMakeFiles/VirusSpl.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/main.cpp > CMakeFiles/VirusSpl.dir/main.cpp.i

CMakeFiles/VirusSpl.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/main.cpp -o CMakeFiles/VirusSpl.dir/main.cpp.s

CMakeFiles/VirusSpl.dir/Session.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/Session.cpp.o: ../Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VirusSpl.dir/Session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/Session.cpp.o -c /home/spl211/CLionProjects/VirusSpl/Session.cpp

CMakeFiles/VirusSpl.dir/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/Session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/Session.cpp > CMakeFiles/VirusSpl.dir/Session.cpp.i

CMakeFiles/VirusSpl.dir/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/Session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/Session.cpp -o CMakeFiles/VirusSpl.dir/Session.cpp.s

CMakeFiles/VirusSpl.dir/Agent.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/Agent.cpp.o: ../Agent.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VirusSpl.dir/Agent.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/Agent.cpp.o -c /home/spl211/CLionProjects/VirusSpl/Agent.cpp

CMakeFiles/VirusSpl.dir/Agent.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/Agent.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/Agent.cpp > CMakeFiles/VirusSpl.dir/Agent.cpp.i

CMakeFiles/VirusSpl.dir/Agent.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/Agent.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/Agent.cpp -o CMakeFiles/VirusSpl.dir/Agent.cpp.s

CMakeFiles/VirusSpl.dir/Virus.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/Virus.cpp.o: ../Virus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VirusSpl.dir/Virus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/Virus.cpp.o -c /home/spl211/CLionProjects/VirusSpl/Virus.cpp

CMakeFiles/VirusSpl.dir/Virus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/Virus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/Virus.cpp > CMakeFiles/VirusSpl.dir/Virus.cpp.i

CMakeFiles/VirusSpl.dir/Virus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/Virus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/Virus.cpp -o CMakeFiles/VirusSpl.dir/Virus.cpp.s

CMakeFiles/VirusSpl.dir/Graph.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VirusSpl.dir/Graph.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/Graph.cpp.o -c /home/spl211/CLionProjects/VirusSpl/Graph.cpp

CMakeFiles/VirusSpl.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/Graph.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/Graph.cpp > CMakeFiles/VirusSpl.dir/Graph.cpp.i

CMakeFiles/VirusSpl.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/Graph.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/Graph.cpp -o CMakeFiles/VirusSpl.dir/Graph.cpp.s

CMakeFiles/VirusSpl.dir/Tree.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/Tree.cpp.o: ../Tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VirusSpl.dir/Tree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/Tree.cpp.o -c /home/spl211/CLionProjects/VirusSpl/Tree.cpp

CMakeFiles/VirusSpl.dir/Tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/Tree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/Tree.cpp > CMakeFiles/VirusSpl.dir/Tree.cpp.i

CMakeFiles/VirusSpl.dir/Tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/Tree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/Tree.cpp -o CMakeFiles/VirusSpl.dir/Tree.cpp.s

CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o: ../MaxRankTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o -c /home/spl211/CLionProjects/VirusSpl/MaxRankTree.cpp

CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/MaxRankTree.cpp > CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.i

CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/MaxRankTree.cpp -o CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.s

CMakeFiles/VirusSpl.dir/CycleTree.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/CycleTree.cpp.o: ../CycleTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/VirusSpl.dir/CycleTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/CycleTree.cpp.o -c /home/spl211/CLionProjects/VirusSpl/CycleTree.cpp

CMakeFiles/VirusSpl.dir/CycleTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/CycleTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/CycleTree.cpp > CMakeFiles/VirusSpl.dir/CycleTree.cpp.i

CMakeFiles/VirusSpl.dir/CycleTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/CycleTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/CycleTree.cpp -o CMakeFiles/VirusSpl.dir/CycleTree.cpp.s

CMakeFiles/VirusSpl.dir/RootTree.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/RootTree.cpp.o: ../RootTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/VirusSpl.dir/RootTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/RootTree.cpp.o -c /home/spl211/CLionProjects/VirusSpl/RootTree.cpp

CMakeFiles/VirusSpl.dir/RootTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/RootTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/RootTree.cpp > CMakeFiles/VirusSpl.dir/RootTree.cpp.i

CMakeFiles/VirusSpl.dir/RootTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/RootTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/RootTree.cpp -o CMakeFiles/VirusSpl.dir/RootTree.cpp.s

CMakeFiles/VirusSpl.dir/ContactTracer.cpp.o: CMakeFiles/VirusSpl.dir/flags.make
CMakeFiles/VirusSpl.dir/ContactTracer.cpp.o: ../ContactTracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/VirusSpl.dir/ContactTracer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VirusSpl.dir/ContactTracer.cpp.o -c /home/spl211/CLionProjects/VirusSpl/ContactTracer.cpp

CMakeFiles/VirusSpl.dir/ContactTracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VirusSpl.dir/ContactTracer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/spl211/CLionProjects/VirusSpl/ContactTracer.cpp > CMakeFiles/VirusSpl.dir/ContactTracer.cpp.i

CMakeFiles/VirusSpl.dir/ContactTracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VirusSpl.dir/ContactTracer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/spl211/CLionProjects/VirusSpl/ContactTracer.cpp -o CMakeFiles/VirusSpl.dir/ContactTracer.cpp.s

# Object files for target VirusSpl
VirusSpl_OBJECTS = \
"CMakeFiles/VirusSpl.dir/main.cpp.o" \
"CMakeFiles/VirusSpl.dir/Session.cpp.o" \
"CMakeFiles/VirusSpl.dir/Agent.cpp.o" \
"CMakeFiles/VirusSpl.dir/Virus.cpp.o" \
"CMakeFiles/VirusSpl.dir/Graph.cpp.o" \
"CMakeFiles/VirusSpl.dir/Tree.cpp.o" \
"CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o" \
"CMakeFiles/VirusSpl.dir/CycleTree.cpp.o" \
"CMakeFiles/VirusSpl.dir/RootTree.cpp.o" \
"CMakeFiles/VirusSpl.dir/ContactTracer.cpp.o"

# External object files for target VirusSpl
VirusSpl_EXTERNAL_OBJECTS =

VirusSpl: CMakeFiles/VirusSpl.dir/main.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/Session.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/Agent.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/Virus.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/Graph.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/Tree.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/MaxRankTree.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/CycleTree.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/RootTree.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/ContactTracer.cpp.o
VirusSpl: CMakeFiles/VirusSpl.dir/build.make
VirusSpl: CMakeFiles/VirusSpl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable VirusSpl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VirusSpl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VirusSpl.dir/build: VirusSpl

.PHONY : CMakeFiles/VirusSpl.dir/build

CMakeFiles/VirusSpl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VirusSpl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VirusSpl.dir/clean

CMakeFiles/VirusSpl.dir/depend:
	cd /home/spl211/CLionProjects/VirusSpl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spl211/CLionProjects/VirusSpl /home/spl211/CLionProjects/VirusSpl /home/spl211/CLionProjects/VirusSpl/cmake-build-debug /home/spl211/CLionProjects/VirusSpl/cmake-build-debug /home/spl211/CLionProjects/VirusSpl/cmake-build-debug/CMakeFiles/VirusSpl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VirusSpl.dir/depend

