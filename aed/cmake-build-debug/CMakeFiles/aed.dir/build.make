# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/aed.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/aed.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/aed.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aed.dir/flags.make

CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj: aed_autogen/mocs_compilation.cpp
CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\aed.dir\aed_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\aed.dir\aed_autogen\mocs_compilation.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\aed_autogen\mocs_compilation.cpp

CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\aed_autogen\mocs_compilation.cpp > CMakeFiles\aed.dir\aed_autogen\mocs_compilation.cpp.i

CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\aed_autogen\mocs_compilation.cpp -o CMakeFiles\aed.dir\aed_autogen\mocs_compilation.cpp.s

CMakeFiles/aed.dir/main.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/main.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/main.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/main.cpp
CMakeFiles/aed.dir/main.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/aed.dir/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/main.cpp.obj -MF CMakeFiles\aed.dir\main.cpp.obj.d -o CMakeFiles\aed.dir\main.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\main.cpp

CMakeFiles/aed.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\main.cpp > CMakeFiles\aed.dir\main.cpp.i

CMakeFiles/aed.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\main.cpp -o CMakeFiles\aed.dir\main.cpp.s

CMakeFiles/aed.dir/mainwindow.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/mainwindow.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/mainwindow.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/mainwindow.cpp
CMakeFiles/aed.dir/mainwindow.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/aed.dir/mainwindow.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/mainwindow.cpp.obj -MF CMakeFiles\aed.dir\mainwindow.cpp.obj.d -o CMakeFiles\aed.dir\mainwindow.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\mainwindow.cpp

CMakeFiles/aed.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/mainwindow.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\mainwindow.cpp > CMakeFiles\aed.dir\mainwindow.cpp.i

CMakeFiles/aed.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/mainwindow.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\mainwindow.cpp -o CMakeFiles\aed.dir\mainwindow.cpp.s

CMakeFiles/aed.dir/model/aed/AED.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/aed/AED.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/aed/AED.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/aed/AED.cpp
CMakeFiles/aed.dir/model/aed/AED.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/aed.dir/model/aed/AED.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/aed/AED.cpp.obj -MF CMakeFiles\aed.dir\model\aed\AED.cpp.obj.d -o CMakeFiles\aed.dir\model\aed\AED.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\AED.cpp

CMakeFiles/aed.dir/model/aed/AED.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/aed/AED.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\AED.cpp > CMakeFiles\aed.dir\model\aed\AED.cpp.i

CMakeFiles/aed.dir/model/aed/AED.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/aed/AED.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\AED.cpp -o CMakeFiles\aed.dir\model\aed\AED.cpp.s

CMakeFiles/aed.dir/model/Rescuer.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/Rescuer.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/Rescuer.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/Rescuer.cpp
CMakeFiles/aed.dir/model/Rescuer.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/aed.dir/model/Rescuer.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/Rescuer.cpp.obj -MF CMakeFiles\aed.dir\model\Rescuer.cpp.obj.d -o CMakeFiles\aed.dir\model\Rescuer.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\Rescuer.cpp

CMakeFiles/aed.dir/model/Rescuer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/Rescuer.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\Rescuer.cpp > CMakeFiles\aed.dir\model\Rescuer.cpp.i

CMakeFiles/aed.dir/model/Rescuer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/Rescuer.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\Rescuer.cpp -o CMakeFiles\aed.dir\model\Rescuer.cpp.s

CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/patient/heart/Heart.cpp
CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj -MF CMakeFiles\aed.dir\model\patient\heart\Heart.cpp.obj.d -o CMakeFiles\aed.dir\model\patient\heart\Heart.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\heart\Heart.cpp

CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\heart\Heart.cpp > CMakeFiles\aed.dir\model\patient\heart\Heart.cpp.i

CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\heart\Heart.cpp -o CMakeFiles\aed.dir\model\patient\heart\Heart.cpp.s

CMakeFiles/aed.dir/model/patient/Patient.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/patient/Patient.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/patient/Patient.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/patient/Patient.cpp
CMakeFiles/aed.dir/model/patient/Patient.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/aed.dir/model/patient/Patient.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/patient/Patient.cpp.obj -MF CMakeFiles\aed.dir\model\patient\Patient.cpp.obj.d -o CMakeFiles\aed.dir\model\patient\Patient.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\Patient.cpp

CMakeFiles/aed.dir/model/patient/Patient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/patient/Patient.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\Patient.cpp > CMakeFiles\aed.dir\model\patient\Patient.cpp.i

CMakeFiles/aed.dir/model/patient/Patient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/patient/Patient.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\Patient.cpp -o CMakeFiles\aed.dir\model\patient\Patient.cpp.s

CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/patient/heart/pulse/Pulse.cpp
CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj -MF CMakeFiles\aed.dir\model\patient\heart\pulse\Pulse.cpp.obj.d -o CMakeFiles\aed.dir\model\patient\heart\pulse\Pulse.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\heart\pulse\Pulse.cpp

CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\heart\pulse\Pulse.cpp > CMakeFiles\aed.dir\model\patient\heart\pulse\Pulse.cpp.i

CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\patient\heart\pulse\Pulse.cpp -o CMakeFiles\aed.dir\model\patient\heart\pulse\Pulse.cpp.s

CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/aed/step/action/Action.cpp
CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj -MF CMakeFiles\aed.dir\model\aed\step\action\Action.cpp.obj.d -o CMakeFiles\aed.dir\model\aed\step\action\Action.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\step\action\Action.cpp

CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\step\action\Action.cpp > CMakeFiles\aed.dir\model\aed\step\action\Action.cpp.i

CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\step\action\Action.cpp -o CMakeFiles\aed.dir\model\aed\step\action\Action.cpp.s

CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj: CMakeFiles/aed.dir/flags.make
CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj: CMakeFiles/aed.dir/includes_CXX.rsp
CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj: C:/Users/abdul/OneDrive/Desktop/3004/AEDSimulator/aed/model/aed/step/Step.cpp
CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj: CMakeFiles/aed.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj -MF CMakeFiles\aed.dir\model\aed\step\Step.cpp.obj.d -o CMakeFiles\aed.dir\model\aed\step\Step.cpp.obj -c C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\step\Step.cpp

CMakeFiles/aed.dir/model/aed/step/Step.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/aed.dir/model/aed/step/Step.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\step\Step.cpp > CMakeFiles\aed.dir\model\aed\step\Step.cpp.i

CMakeFiles/aed.dir/model/aed/step/Step.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/aed.dir/model/aed/step/Step.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\model\aed\step\Step.cpp -o CMakeFiles\aed.dir\model\aed\step\Step.cpp.s

# Object files for target aed
aed_OBJECTS = \
"CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/aed.dir/main.cpp.obj" \
"CMakeFiles/aed.dir/mainwindow.cpp.obj" \
"CMakeFiles/aed.dir/model/aed/AED.cpp.obj" \
"CMakeFiles/aed.dir/model/Rescuer.cpp.obj" \
"CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj" \
"CMakeFiles/aed.dir/model/patient/Patient.cpp.obj" \
"CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj" \
"CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj" \
"CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj"

# External object files for target aed
aed_EXTERNAL_OBJECTS =

aed.exe: CMakeFiles/aed.dir/aed_autogen/mocs_compilation.cpp.obj
aed.exe: CMakeFiles/aed.dir/main.cpp.obj
aed.exe: CMakeFiles/aed.dir/mainwindow.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/aed/AED.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/Rescuer.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/patient/heart/Heart.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/patient/Patient.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/patient/heart/pulse/Pulse.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/aed/step/action/Action.cpp.obj
aed.exe: CMakeFiles/aed.dir/model/aed/step/Step.cpp.obj
aed.exe: CMakeFiles/aed.dir/build.make
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6Widgets.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6Quick.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6QmlModels.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6Qml.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6Network.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6OpenGL.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6Gui.a
aed.exe: C:/Qt/6.6.1/mingw_64/lib/libQt6Core.a
aed.exe: CMakeFiles/aed.dir/linkLibs.rsp
aed.exe: CMakeFiles/aed.dir/objects1.rsp
aed.exe: CMakeFiles/aed.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable aed.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\aed.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aed.dir/build: aed.exe
.PHONY : CMakeFiles/aed.dir/build

CMakeFiles/aed.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\aed.dir\cmake_clean.cmake
.PHONY : CMakeFiles/aed.dir/clean

CMakeFiles/aed.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug C:\Users\abdul\OneDrive\Desktop\3004\AEDSimulator\aed\cmake-build-debug\CMakeFiles\aed.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/aed.dir/depend
