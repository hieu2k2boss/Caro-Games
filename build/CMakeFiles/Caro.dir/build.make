# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = H:/Download/FPT/TaiLieu/BaiTap/CARO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = H:/Download/FPT/TaiLieu/BaiTap/CARO/build

# Include any dependencies generated for this target.
include CMakeFiles/Caro.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Caro.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Caro.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Caro.dir/flags.make

CMakeFiles/Caro.dir/src/Board/Board.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/Board/Board.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/Board/Board.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Board/Board.cpp
CMakeFiles/Caro.dir/src/Board/Board.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Caro.dir/src/Board/Board.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/Board/Board.cpp.obj -MF CMakeFiles/Caro.dir/src/Board/Board.cpp.obj.d -o CMakeFiles/Caro.dir/src/Board/Board.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Board/Board.cpp

CMakeFiles/Caro.dir/src/Board/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/Board/Board.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Board/Board.cpp > CMakeFiles/Caro.dir/src/Board/Board.cpp.i

CMakeFiles/Caro.dir/src/Board/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/Board/Board.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Board/Board.cpp -o CMakeFiles/Caro.dir/src/Board/Board.cpp.s

CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Bot/Bot.cpp
CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj -MF CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj.d -o CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Bot/Bot.cpp

CMakeFiles/Caro.dir/src/Bot/Bot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/Bot/Bot.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Bot/Bot.cpp > CMakeFiles/Caro.dir/src/Bot/Bot.cpp.i

CMakeFiles/Caro.dir/src/Bot/Bot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/Bot/Bot.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Bot/Bot.cpp -o CMakeFiles/Caro.dir/src/Bot/Bot.cpp.s

CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/FileManager/FileManager.cpp
CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj -MF CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj.d -o CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/FileManager/FileManager.cpp

CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/FileManager/FileManager.cpp > CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.i

CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/FileManager/FileManager.cpp -o CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.s

CMakeFiles/Caro.dir/src/Game/Game.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/Game/Game.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/Game/Game.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Game/Game.cpp
CMakeFiles/Caro.dir/src/Game/Game.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Caro.dir/src/Game/Game.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/Game/Game.cpp.obj -MF CMakeFiles/Caro.dir/src/Game/Game.cpp.obj.d -o CMakeFiles/Caro.dir/src/Game/Game.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Game/Game.cpp

CMakeFiles/Caro.dir/src/Game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/Game/Game.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Game/Game.cpp > CMakeFiles/Caro.dir/src/Game/Game.cpp.i

CMakeFiles/Caro.dir/src/Game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/Game/Game.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Game/Game.cpp -o CMakeFiles/Caro.dir/src/Game/Game.cpp.s

CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Menu/Menu.cpp
CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj -MF CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj.d -o CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Menu/Menu.cpp

CMakeFiles/Caro.dir/src/Menu/Menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/Menu/Menu.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Menu/Menu.cpp > CMakeFiles/Caro.dir/src/Menu/Menu.cpp.i

CMakeFiles/Caro.dir/src/Menu/Menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/Menu/Menu.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Menu/Menu.cpp -o CMakeFiles/Caro.dir/src/Menu/Menu.cpp.s

CMakeFiles/Caro.dir/src/Player/Player.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/Player/Player.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/Player/Player.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Player/Player.cpp
CMakeFiles/Caro.dir/src/Player/Player.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Caro.dir/src/Player/Player.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/Player/Player.cpp.obj -MF CMakeFiles/Caro.dir/src/Player/Player.cpp.obj.d -o CMakeFiles/Caro.dir/src/Player/Player.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Player/Player.cpp

CMakeFiles/Caro.dir/src/Player/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/Player/Player.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Player/Player.cpp > CMakeFiles/Caro.dir/src/Player/Player.cpp.i

CMakeFiles/Caro.dir/src/Player/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/Player/Player.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/Player/Player.cpp -o CMakeFiles/Caro.dir/src/Player/Player.cpp.s

CMakeFiles/Caro.dir/src/main.cpp.obj: CMakeFiles/Caro.dir/flags.make
CMakeFiles/Caro.dir/src/main.cpp.obj: CMakeFiles/Caro.dir/includes_CXX.rsp
CMakeFiles/Caro.dir/src/main.cpp.obj: H:/Download/FPT/TaiLieu/BaiTap/CARO/src/main.cpp
CMakeFiles/Caro.dir/src/main.cpp.obj: CMakeFiles/Caro.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Caro.dir/src/main.cpp.obj"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Caro.dir/src/main.cpp.obj -MF CMakeFiles/Caro.dir/src/main.cpp.obj.d -o CMakeFiles/Caro.dir/src/main.cpp.obj -c H:/Download/FPT/TaiLieu/BaiTap/CARO/src/main.cpp

CMakeFiles/Caro.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Caro.dir/src/main.cpp.i"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E H:/Download/FPT/TaiLieu/BaiTap/CARO/src/main.cpp > CMakeFiles/Caro.dir/src/main.cpp.i

CMakeFiles/Caro.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Caro.dir/src/main.cpp.s"
	C:/mingw64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S H:/Download/FPT/TaiLieu/BaiTap/CARO/src/main.cpp -o CMakeFiles/Caro.dir/src/main.cpp.s

# Object files for target Caro
Caro_OBJECTS = \
"CMakeFiles/Caro.dir/src/Board/Board.cpp.obj" \
"CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj" \
"CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj" \
"CMakeFiles/Caro.dir/src/Game/Game.cpp.obj" \
"CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj" \
"CMakeFiles/Caro.dir/src/Player/Player.cpp.obj" \
"CMakeFiles/Caro.dir/src/main.cpp.obj"

# External object files for target Caro
Caro_EXTERNAL_OBJECTS =

Caro.exe: CMakeFiles/Caro.dir/src/Board/Board.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/src/Bot/Bot.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/src/FileManager/FileManager.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/src/Game/Game.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/src/Menu/Menu.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/src/Player/Player.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/src/main.cpp.obj
Caro.exe: CMakeFiles/Caro.dir/build.make
Caro.exe: CMakeFiles/Caro.dir/linkLibs.rsp
Caro.exe: CMakeFiles/Caro.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Caro.exe"
	"C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/Caro.dir/objects.a
	C:/mingw64/bin/ar.exe qc CMakeFiles/Caro.dir/objects.a @CMakeFiles/Caro.dir/objects1.rsp
	C:/mingw64/bin/c++.exe -g -Wl,--whole-archive CMakeFiles/Caro.dir/objects.a -Wl,--no-whole-archive -o Caro.exe -Wl,--out-implib,libCaro.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/Caro.dir/linkLibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/Caro.dir/build: Caro.exe
.PHONY : CMakeFiles/Caro.dir/build

CMakeFiles/Caro.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Caro.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Caro.dir/clean

CMakeFiles/Caro.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" H:/Download/FPT/TaiLieu/BaiTap/CARO H:/Download/FPT/TaiLieu/BaiTap/CARO H:/Download/FPT/TaiLieu/BaiTap/CARO/build H:/Download/FPT/TaiLieu/BaiTap/CARO/build H:/Download/FPT/TaiLieu/BaiTap/CARO/build/CMakeFiles/Caro.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Caro.dir/depend

