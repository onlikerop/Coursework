# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = Q:\Progs\C++\University\Practice\Coursework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Coursework.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Coursework.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Coursework.dir\flags.make

CMakeFiles\Coursework.dir\main.cpp.obj: CMakeFiles\Coursework.dir\flags.make
CMakeFiles\Coursework.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Coursework.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Coursework.dir\main.cpp.obj /FdCMakeFiles\Coursework.dir\ /FS -c Q:\Progs\C++\University\Practice\Coursework\main.cpp
<<

CMakeFiles\Coursework.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Coursework.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Coursework.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Q:\Progs\C++\University\Practice\Coursework\main.cpp
<<

CMakeFiles\Coursework.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Coursework.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Coursework.dir\main.cpp.s /c Q:\Progs\C++\University\Practice\Coursework\main.cpp
<<

CMakeFiles\Coursework.dir\CWLib.cpp.obj: CMakeFiles\Coursework.dir\flags.make
CMakeFiles\Coursework.dir\CWLib.cpp.obj: ..\CWLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Coursework.dir/CWLib.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Coursework.dir\CWLib.cpp.obj /FdCMakeFiles\Coursework.dir\ /FS -c Q:\Progs\C++\University\Practice\Coursework\CWLib.cpp
<<

CMakeFiles\Coursework.dir\CWLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Coursework.dir/CWLib.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Coursework.dir\CWLib.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Q:\Progs\C++\University\Practice\Coursework\CWLib.cpp
<<

CMakeFiles\Coursework.dir\CWLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Coursework.dir/CWLib.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Coursework.dir\CWLib.cpp.s /c Q:\Progs\C++\University\Practice\Coursework\CWLib.cpp
<<

CMakeFiles\Coursework.dir\Student.cpp.obj: CMakeFiles\Coursework.dir\flags.make
CMakeFiles\Coursework.dir\Student.cpp.obj: ..\Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Coursework.dir/Student.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Coursework.dir\Student.cpp.obj /FdCMakeFiles\Coursework.dir\ /FS -c Q:\Progs\C++\University\Practice\Coursework\Student.cpp
<<

CMakeFiles\Coursework.dir\Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Coursework.dir/Student.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Coursework.dir\Student.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Q:\Progs\C++\University\Practice\Coursework\Student.cpp
<<

CMakeFiles\Coursework.dir\Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Coursework.dir/Student.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Coursework.dir\Student.cpp.s /c Q:\Progs\C++\University\Practice\Coursework\Student.cpp
<<

CMakeFiles\Coursework.dir\Subject.cpp.obj: CMakeFiles\Coursework.dir\flags.make
CMakeFiles\Coursework.dir\Subject.cpp.obj: ..\Subject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Coursework.dir/Subject.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Coursework.dir\Subject.cpp.obj /FdCMakeFiles\Coursework.dir\ /FS -c Q:\Progs\C++\University\Practice\Coursework\Subject.cpp
<<

CMakeFiles\Coursework.dir\Subject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Coursework.dir/Subject.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Coursework.dir\Subject.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Q:\Progs\C++\University\Practice\Coursework\Subject.cpp
<<

CMakeFiles\Coursework.dir\Subject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Coursework.dir/Subject.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Coursework.dir\Subject.cpp.s /c Q:\Progs\C++\University\Practice\Coursework\Subject.cpp
<<

CMakeFiles\Coursework.dir\Semester.cpp.obj: CMakeFiles\Coursework.dir\flags.make
CMakeFiles\Coursework.dir\Semester.cpp.obj: ..\Semester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Coursework.dir/Semester.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Coursework.dir\Semester.cpp.obj /FdCMakeFiles\Coursework.dir\ /FS -c Q:\Progs\C++\University\Practice\Coursework\Semester.cpp
<<

CMakeFiles\Coursework.dir\Semester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Coursework.dir/Semester.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Coursework.dir\Semester.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Q:\Progs\C++\University\Practice\Coursework\Semester.cpp
<<

CMakeFiles\Coursework.dir\Semester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Coursework.dir/Semester.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Coursework.dir\Semester.cpp.s /c Q:\Progs\C++\University\Practice\Coursework\Semester.cpp
<<

CMakeFiles\Coursework.dir\Active.cpp.obj: CMakeFiles\Coursework.dir\flags.make
CMakeFiles\Coursework.dir\Active.cpp.obj: ..\Active.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Coursework.dir/Active.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Coursework.dir\Active.cpp.obj /FdCMakeFiles\Coursework.dir\ /FS -c Q:\Progs\C++\University\Practice\Coursework\Active.cpp
<<

CMakeFiles\Coursework.dir\Active.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Coursework.dir/Active.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\Coursework.dir\Active.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Q:\Progs\C++\University\Practice\Coursework\Active.cpp
<<

CMakeFiles\Coursework.dir\Active.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Coursework.dir/Active.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Coursework.dir\Active.cpp.s /c Q:\Progs\C++\University\Practice\Coursework\Active.cpp
<<

# Object files for target Coursework
Coursework_OBJECTS = \
"CMakeFiles\Coursework.dir\main.cpp.obj" \
"CMakeFiles\Coursework.dir\CWLib.cpp.obj" \
"CMakeFiles\Coursework.dir\Student.cpp.obj" \
"CMakeFiles\Coursework.dir\Subject.cpp.obj" \
"CMakeFiles\Coursework.dir\Semester.cpp.obj" \
"CMakeFiles\Coursework.dir\Active.cpp.obj"

# External object files for target Coursework
Coursework_EXTERNAL_OBJECTS =

Coursework.exe: CMakeFiles\Coursework.dir\main.cpp.obj
Coursework.exe: CMakeFiles\Coursework.dir\CWLib.cpp.obj
Coursework.exe: CMakeFiles\Coursework.dir\Student.cpp.obj
Coursework.exe: CMakeFiles\Coursework.dir\Subject.cpp.obj
Coursework.exe: CMakeFiles\Coursework.dir\Semester.cpp.obj
Coursework.exe: CMakeFiles\Coursework.dir\Active.cpp.obj
Coursework.exe: CMakeFiles\Coursework.dir\build.make
Coursework.exe: CMakeFiles\Coursework.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Coursework.exe"
	"D:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Coursework.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Coursework.dir\objects1.rsp @<<
 /out:Coursework.exe /implib:Coursework.lib /pdb:Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\Coursework.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Coursework.dir\build: Coursework.exe

.PHONY : CMakeFiles\Coursework.dir\build

CMakeFiles\Coursework.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Coursework.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Coursework.dir\clean

CMakeFiles\Coursework.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" Q:\Progs\C++\University\Practice\Coursework Q:\Progs\C++\University\Practice\Coursework Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug Q:\Progs\C++\University\Practice\Coursework\cmake-build-debug\CMakeFiles\Coursework.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Coursework.dir\depend

