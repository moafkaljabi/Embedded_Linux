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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build

# Include any dependencies generated for this target.
include CMakeFiles/HttpServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HttpServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HttpServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HttpServer.dir/flags.make

CMakeFiles/HttpServer.dir/main.cpp.o: CMakeFiles/HttpServer.dir/flags.make
CMakeFiles/HttpServer.dir/main.cpp.o: /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/main.cpp
CMakeFiles/HttpServer.dir/main.cpp.o: CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HttpServer.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HttpServer.dir/main.cpp.o -MF CMakeFiles/HttpServer.dir/main.cpp.o.d -o CMakeFiles/HttpServer.dir/main.cpp.o -c /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/main.cpp

CMakeFiles/HttpServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/main.cpp > CMakeFiles/HttpServer.dir/main.cpp.i

CMakeFiles/HttpServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/main.cpp -o CMakeFiles/HttpServer.dir/main.cpp.s

CMakeFiles/HttpServer.dir/request.cpp.o: CMakeFiles/HttpServer.dir/flags.make
CMakeFiles/HttpServer.dir/request.cpp.o: /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/request.cpp
CMakeFiles/HttpServer.dir/request.cpp.o: CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HttpServer.dir/request.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HttpServer.dir/request.cpp.o -MF CMakeFiles/HttpServer.dir/request.cpp.o.d -o CMakeFiles/HttpServer.dir/request.cpp.o -c /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/request.cpp

CMakeFiles/HttpServer.dir/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/request.cpp > CMakeFiles/HttpServer.dir/request.cpp.i

CMakeFiles/HttpServer.dir/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/request.cpp -o CMakeFiles/HttpServer.dir/request.cpp.s

CMakeFiles/HttpServer.dir/response.cpp.o: CMakeFiles/HttpServer.dir/flags.make
CMakeFiles/HttpServer.dir/response.cpp.o: /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/response.cpp
CMakeFiles/HttpServer.dir/response.cpp.o: CMakeFiles/HttpServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/HttpServer.dir/response.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HttpServer.dir/response.cpp.o -MF CMakeFiles/HttpServer.dir/response.cpp.o.d -o CMakeFiles/HttpServer.dir/response.cpp.o -c /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/response.cpp

CMakeFiles/HttpServer.dir/response.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/HttpServer.dir/response.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/response.cpp > CMakeFiles/HttpServer.dir/response.cpp.i

CMakeFiles/HttpServer.dir/response.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/HttpServer.dir/response.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/response.cpp -o CMakeFiles/HttpServer.dir/response.cpp.s

# Object files for target HttpServer
HttpServer_OBJECTS = \
"CMakeFiles/HttpServer.dir/main.cpp.o" \
"CMakeFiles/HttpServer.dir/request.cpp.o" \
"CMakeFiles/HttpServer.dir/response.cpp.o"

# External object files for target HttpServer
HttpServer_EXTERNAL_OBJECTS =

HttpServer: CMakeFiles/HttpServer.dir/main.cpp.o
HttpServer: CMakeFiles/HttpServer.dir/request.cpp.o
HttpServer: CMakeFiles/HttpServer.dir/response.cpp.o
HttpServer: CMakeFiles/HttpServer.dir/build.make
HttpServer: CMakeFiles/HttpServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable HttpServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HttpServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HttpServer.dir/build: HttpServer
.PHONY : CMakeFiles/HttpServer.dir/build

CMakeFiles/HttpServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HttpServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HttpServer.dir/clean

CMakeFiles/HttpServer.dir/depend:
	cd /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build /home/moafk/Documents/Embedded_Linux/c++/backend/networking/httpServer/src/build/CMakeFiles/HttpServer.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HttpServer.dir/depend

