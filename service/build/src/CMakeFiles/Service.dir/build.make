# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build"

# Include any dependencies generated for this target.
include src/CMakeFiles/Service.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/Service.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Service.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Service.dir/flags.make

src/CMakeFiles/Service.dir/Api/Endpoint.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Api/Endpoint.cpp.o: ../src/Api/Endpoint.cpp
src/CMakeFiles/Service.dir/Api/Endpoint.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Service.dir/Api/Endpoint.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Api/Endpoint.cpp.o -MF CMakeFiles/Service.dir/Api/Endpoint.cpp.o.d -o CMakeFiles/Service.dir/Api/Endpoint.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Api/Endpoint.cpp"

src/CMakeFiles/Service.dir/Api/Endpoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Api/Endpoint.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Api/Endpoint.cpp" > CMakeFiles/Service.dir/Api/Endpoint.cpp.i

src/CMakeFiles/Service.dir/Api/Endpoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Api/Endpoint.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Api/Endpoint.cpp" -o CMakeFiles/Service.dir/Api/Endpoint.cpp.s

src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o: ../src/Api/Parser/JsonParser.cpp
src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o -MF CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o.d -o CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Api/Parser/JsonParser.cpp"

src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Api/Parser/JsonParser.cpp" > CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.i

src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Api/Parser/JsonParser.cpp" -o CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.s

src/CMakeFiles/Service.dir/Core/Manager.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Core/Manager.cpp.o: ../src/Core/Manager.cpp
src/CMakeFiles/Service.dir/Core/Manager.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Service.dir/Core/Manager.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Core/Manager.cpp.o -MF CMakeFiles/Service.dir/Core/Manager.cpp.o.d -o CMakeFiles/Service.dir/Core/Manager.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Manager.cpp"

src/CMakeFiles/Service.dir/Core/Manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Core/Manager.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Manager.cpp" > CMakeFiles/Service.dir/Core/Manager.cpp.i

src/CMakeFiles/Service.dir/Core/Manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Core/Manager.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Manager.cpp" -o CMakeFiles/Service.dir/Core/Manager.cpp.s

src/CMakeFiles/Service.dir/Core/Model/App.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Core/Model/App.cpp.o: ../src/Core/Model/App.cpp
src/CMakeFiles/Service.dir/Core/Model/App.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/Service.dir/Core/Model/App.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Core/Model/App.cpp.o -MF CMakeFiles/Service.dir/Core/Model/App.cpp.o.d -o CMakeFiles/Service.dir/Core/Model/App.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/App.cpp"

src/CMakeFiles/Service.dir/Core/Model/App.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Core/Model/App.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/App.cpp" > CMakeFiles/Service.dir/Core/Model/App.cpp.i

src/CMakeFiles/Service.dir/Core/Model/App.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Core/Model/App.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/App.cpp" -o CMakeFiles/Service.dir/Core/Model/App.cpp.s

src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o: ../src/Core/Model/Reminder.cpp
src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o -MF CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o.d -o CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/Reminder.cpp"

src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Core/Model/Reminder.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/Reminder.cpp" > CMakeFiles/Service.dir/Core/Model/Reminder.cpp.i

src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Core/Model/Reminder.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/Reminder.cpp" -o CMakeFiles/Service.dir/Core/Model/Reminder.cpp.s

src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o: ../src/Core/Model/ReminderList.cpp
src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o -MF CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o.d -o CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/ReminderList.cpp"

src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/ReminderList.cpp" > CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.i

src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Core/Model/ReminderList.cpp" -o CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.s

src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o: ../src/Repository/SQLiteRepository.cpp
src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o -MF CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o.d -o CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Repository/SQLiteRepository.cpp"

src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Repository/SQLiteRepository.cpp" > CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.i

src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Repository/SQLiteRepository.cpp" -o CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.s

src/CMakeFiles/Service.dir/Service.cpp.o: src/CMakeFiles/Service.dir/flags.make
src/CMakeFiles/Service.dir/Service.cpp.o: ../src/Service.cpp
src/CMakeFiles/Service.dir/Service.cpp.o: src/CMakeFiles/Service.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/Service.dir/Service.cpp.o"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/Service.dir/Service.cpp.o -MF CMakeFiles/Service.dir/Service.cpp.o.d -o CMakeFiles/Service.dir/Service.cpp.o -c "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Service.cpp"

src/CMakeFiles/Service.dir/Service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Service.dir/Service.cpp.i"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Service.cpp" > CMakeFiles/Service.dir/Service.cpp.i

src/CMakeFiles/Service.dir/Service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Service.dir/Service.cpp.s"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src/Service.cpp" -o CMakeFiles/Service.dir/Service.cpp.s

# Object files for target Service
Service_OBJECTS = \
"CMakeFiles/Service.dir/Api/Endpoint.cpp.o" \
"CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o" \
"CMakeFiles/Service.dir/Core/Manager.cpp.o" \
"CMakeFiles/Service.dir/Core/Model/App.cpp.o" \
"CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o" \
"CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o" \
"CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o" \
"CMakeFiles/Service.dir/Service.cpp.o"

# External object files for target Service
Service_EXTERNAL_OBJECTS =

Service: src/CMakeFiles/Service.dir/Api/Endpoint.cpp.o
Service: src/CMakeFiles/Service.dir/Api/Parser/JsonParser.cpp.o
Service: src/CMakeFiles/Service.dir/Core/Manager.cpp.o
Service: src/CMakeFiles/Service.dir/Core/Model/App.cpp.o
Service: src/CMakeFiles/Service.dir/Core/Model/Reminder.cpp.o
Service: src/CMakeFiles/Service.dir/Core/Model/ReminderList.cpp.o
Service: src/CMakeFiles/Service.dir/Repository/SQLiteRepository.cpp.o
Service: src/CMakeFiles/Service.dir/Service.cpp.o
Service: src/CMakeFiles/Service.dir/build.make
Service: extern/sqlite/libsqlite3.a
Service: /usr/local/lib/libboost_system-mt.a
Service: /usr/local/lib/libboost_thread-mt.a
Service: src/CMakeFiles/Service.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable ../Service"
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Service.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Service.dir/build: Service
.PHONY : src/CMakeFiles/Service.dir/build

src/CMakeFiles/Service.dir/clean:
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" && $(CMAKE_COMMAND) -P CMakeFiles/Service.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Service.dir/clean

src/CMakeFiles/Service.dir/depend:
	cd "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service" "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/src" "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build" "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src" "/Users/johannesGehring 1/Documents/Informatik/Programmieren III/portfolio-ws2021-gruppe-8/service/build/src/CMakeFiles/Service.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/CMakeFiles/Service.dir/depend
