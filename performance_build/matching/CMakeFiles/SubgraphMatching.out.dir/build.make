# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /snap/cmake/1288/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1288/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhiwei/SubgraphMatching_Spectral

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhiwei/SubgraphMatching_Spectral/performance_build

# Include any dependencies generated for this target.
include matching/CMakeFiles/SubgraphMatching.out.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.make

# Include the progress variables for this target.
include matching/CMakeFiles/SubgraphMatching.out.dir/progress.make

# Include the compile flags for this target's objects.
include matching/CMakeFiles/SubgraphMatching.out.dir/flags.make

matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/KF/spectra.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/KF/spectra.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/KF/spectra.cpp > CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/KF/spectra.cpp -o CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/Experiments.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/Experiments.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/Experiments.cpp > CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/Experiments.cpp -o CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/IO.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/IO.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/IO.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/IO.cpp > CMakeFiles/SubgraphMatching.out.dir/IO.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/IO.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/IO.cpp -o CMakeFiles/SubgraphMatching.out.dir/IO.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/eigenHelper.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/eigenHelper.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/eigenHelper.cpp > CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/eigenHelper.cpp -o CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/matchingcommand.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/matchingcommand.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/matchingcommand.cpp > CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/matchingcommand.cpp -o CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/FilterVertices.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/FilterVertices.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/FilterVertices.cpp > CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/FilterVertices.cpp -o CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/BuildTable.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/BuildTable.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/BuildTable.cpp > CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/BuildTable.cpp -o CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateQueryPlan.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateQueryPlan.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateQueryPlan.cpp > CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateQueryPlan.cpp -o CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/EvaluateQuery.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/EvaluateQuery.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/EvaluateQuery.cpp > CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/EvaluateQuery.cpp -o CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateFilteringPlan.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateFilteringPlan.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateFilteringPlan.cpp > CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/GenerateFilteringPlan.cpp -o CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/StudyPerformance.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/StudyPerformance.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/StudyPerformance.cpp > CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/StudyPerformance.cpp -o CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.s

matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/flags.make
matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.o: /home/zhiwei/SubgraphMatching_Spectral/matching/main.cpp
matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.o: matching/CMakeFiles/SubgraphMatching.out.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.o"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.o -MF CMakeFiles/SubgraphMatching.out.dir/main.cpp.o.d -o CMakeFiles/SubgraphMatching.out.dir/main.cpp.o -c /home/zhiwei/SubgraphMatching_Spectral/matching/main.cpp

matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SubgraphMatching.out.dir/main.cpp.i"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhiwei/SubgraphMatching_Spectral/matching/main.cpp > CMakeFiles/SubgraphMatching.out.dir/main.cpp.i

matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SubgraphMatching.out.dir/main.cpp.s"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhiwei/SubgraphMatching_Spectral/matching/main.cpp -o CMakeFiles/SubgraphMatching.out.dir/main.cpp.s

# Object files for target SubgraphMatching.out
SubgraphMatching_out_OBJECTS = \
"CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o" \
"CMakeFiles/SubgraphMatching.out.dir/main.cpp.o"

# External object files for target SubgraphMatching.out
SubgraphMatching_out_EXTERNAL_OBJECTS =

matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/KF/spectra.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/Experiments.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/IO.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/eigenHelper.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/matchingcommand.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/FilterVertices.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/BuildTable.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/GenerateQueryPlan.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/EvaluateQuery.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/GenerateFilteringPlan.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/StudyPerformance.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/main.cpp.o
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/build.make
matching/SubgraphMatching.out: graph/libgraph.so
matching/SubgraphMatching.out: utility/libutility.so
matching/SubgraphMatching.out: matching/CMakeFiles/SubgraphMatching.out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhiwei/SubgraphMatching_Spectral/performance_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable SubgraphMatching.out"
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SubgraphMatching.out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
matching/CMakeFiles/SubgraphMatching.out.dir/build: matching/SubgraphMatching.out
.PHONY : matching/CMakeFiles/SubgraphMatching.out.dir/build

matching/CMakeFiles/SubgraphMatching.out.dir/clean:
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching && $(CMAKE_COMMAND) -P CMakeFiles/SubgraphMatching.out.dir/cmake_clean.cmake
.PHONY : matching/CMakeFiles/SubgraphMatching.out.dir/clean

matching/CMakeFiles/SubgraphMatching.out.dir/depend:
	cd /home/zhiwei/SubgraphMatching_Spectral/performance_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhiwei/SubgraphMatching_Spectral /home/zhiwei/SubgraphMatching_Spectral/matching /home/zhiwei/SubgraphMatching_Spectral/performance_build /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching /home/zhiwei/SubgraphMatching_Spectral/performance_build/matching/CMakeFiles/SubgraphMatching.out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : matching/CMakeFiles/SubgraphMatching.out.dir/depend

