# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jordan/Documents/SvarogGameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jordan/Documents/SvarogGameEngine

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jordan/Documents/SvarogGameEngine/CMakeFiles /home/jordan/Documents/SvarogGameEngine/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/jordan/Documents/SvarogGameEngine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named SvarogGameEngine

# Build rule for target.
SvarogGameEngine: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 SvarogGameEngine
.PHONY : SvarogGameEngine

# fast build rule for target.
SvarogGameEngine/fast:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/build
.PHONY : SvarogGameEngine/fast

core/String.o: core/String.cpp.o

.PHONY : core/String.o

# target to build an object file
core/String.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/String.cpp.o
.PHONY : core/String.cpp.o

core/String.i: core/String.cpp.i

.PHONY : core/String.i

# target to preprocess a source file
core/String.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/String.cpp.i
.PHONY : core/String.cpp.i

core/String.s: core/String.cpp.s

.PHONY : core/String.s

# target to generate assembly for a file
core/String.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/String.cpp.s
.PHONY : core/String.cpp.s

core/ds-classes/ArrayList.o: core/ds-classes/ArrayList.cpp.o

.PHONY : core/ds-classes/ArrayList.o

# target to build an object file
core/ds-classes/ArrayList.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/ds-classes/ArrayList.cpp.o
.PHONY : core/ds-classes/ArrayList.cpp.o

core/ds-classes/ArrayList.i: core/ds-classes/ArrayList.cpp.i

.PHONY : core/ds-classes/ArrayList.i

# target to preprocess a source file
core/ds-classes/ArrayList.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/ds-classes/ArrayList.cpp.i
.PHONY : core/ds-classes/ArrayList.cpp.i

core/ds-classes/ArrayList.s: core/ds-classes/ArrayList.cpp.s

.PHONY : core/ds-classes/ArrayList.s

# target to generate assembly for a file
core/ds-classes/ArrayList.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/ds-classes/ArrayList.cpp.s
.PHONY : core/ds-classes/ArrayList.cpp.s

core/ds-classes/LinkedList.o: core/ds-classes/LinkedList.cpp.o

.PHONY : core/ds-classes/LinkedList.o

# target to build an object file
core/ds-classes/LinkedList.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/ds-classes/LinkedList.cpp.o
.PHONY : core/ds-classes/LinkedList.cpp.o

core/ds-classes/LinkedList.i: core/ds-classes/LinkedList.cpp.i

.PHONY : core/ds-classes/LinkedList.i

# target to preprocess a source file
core/ds-classes/LinkedList.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/ds-classes/LinkedList.cpp.i
.PHONY : core/ds-classes/LinkedList.cpp.i

core/ds-classes/LinkedList.s: core/ds-classes/LinkedList.cpp.s

.PHONY : core/ds-classes/LinkedList.s

# target to generate assembly for a file
core/ds-classes/LinkedList.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/ds-classes/LinkedList.cpp.s
.PHONY : core/ds-classes/LinkedList.cpp.s

core/events/Event.o: core/events/Event.cpp.o

.PHONY : core/events/Event.o

# target to build an object file
core/events/Event.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/Event.cpp.o
.PHONY : core/events/Event.cpp.o

core/events/Event.i: core/events/Event.cpp.i

.PHONY : core/events/Event.i

# target to preprocess a source file
core/events/Event.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/Event.cpp.i
.PHONY : core/events/Event.cpp.i

core/events/Event.s: core/events/Event.cpp.s

.PHONY : core/events/Event.s

# target to generate assembly for a file
core/events/Event.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/Event.cpp.s
.PHONY : core/events/Event.cpp.s

core/events/EventDispatch.o: core/events/EventDispatch.cpp.o

.PHONY : core/events/EventDispatch.o

# target to build an object file
core/events/EventDispatch.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/EventDispatch.cpp.o
.PHONY : core/events/EventDispatch.cpp.o

core/events/EventDispatch.i: core/events/EventDispatch.cpp.i

.PHONY : core/events/EventDispatch.i

# target to preprocess a source file
core/events/EventDispatch.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/EventDispatch.cpp.i
.PHONY : core/events/EventDispatch.cpp.i

core/events/EventDispatch.s: core/events/EventDispatch.cpp.s

.PHONY : core/events/EventDispatch.s

# target to generate assembly for a file
core/events/EventDispatch.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/EventDispatch.cpp.s
.PHONY : core/events/EventDispatch.cpp.s

core/events/EventListener.o: core/events/EventListener.cpp.o

.PHONY : core/events/EventListener.o

# target to build an object file
core/events/EventListener.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/EventListener.cpp.o
.PHONY : core/events/EventListener.cpp.o

core/events/EventListener.i: core/events/EventListener.cpp.i

.PHONY : core/events/EventListener.i

# target to preprocess a source file
core/events/EventListener.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/EventListener.cpp.i
.PHONY : core/events/EventListener.cpp.i

core/events/EventListener.s: core/events/EventListener.cpp.s

.PHONY : core/events/EventListener.s

# target to generate assembly for a file
core/events/EventListener.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/EventListener.cpp.s
.PHONY : core/events/EventListener.cpp.s

core/events/InputEvent.o: core/events/InputEvent.cpp.o

.PHONY : core/events/InputEvent.o

# target to build an object file
core/events/InputEvent.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/InputEvent.cpp.o
.PHONY : core/events/InputEvent.cpp.o

core/events/InputEvent.i: core/events/InputEvent.cpp.i

.PHONY : core/events/InputEvent.i

# target to preprocess a source file
core/events/InputEvent.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/InputEvent.cpp.i
.PHONY : core/events/InputEvent.cpp.i

core/events/InputEvent.s: core/events/InputEvent.cpp.s

.PHONY : core/events/InputEvent.s

# target to generate assembly for a file
core/events/InputEvent.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/InputEvent.cpp.s
.PHONY : core/events/InputEvent.cpp.s

core/events/event-types/keyevent.o: core/events/event-types/keyevent.cpp.o

.PHONY : core/events/event-types/keyevent.o

# target to build an object file
core/events/event-types/keyevent.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/event-types/keyevent.cpp.o
.PHONY : core/events/event-types/keyevent.cpp.o

core/events/event-types/keyevent.i: core/events/event-types/keyevent.cpp.i

.PHONY : core/events/event-types/keyevent.i

# target to preprocess a source file
core/events/event-types/keyevent.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/event-types/keyevent.cpp.i
.PHONY : core/events/event-types/keyevent.cpp.i

core/events/event-types/keyevent.s: core/events/event-types/keyevent.cpp.s

.PHONY : core/events/event-types/keyevent.s

# target to generate assembly for a file
core/events/event-types/keyevent.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/event-types/keyevent.cpp.s
.PHONY : core/events/event-types/keyevent.cpp.s

core/events/event-types/mousevent.o: core/events/event-types/mousevent.cpp.o

.PHONY : core/events/event-types/mousevent.o

# target to build an object file
core/events/event-types/mousevent.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/event-types/mousevent.cpp.o
.PHONY : core/events/event-types/mousevent.cpp.o

core/events/event-types/mousevent.i: core/events/event-types/mousevent.cpp.i

.PHONY : core/events/event-types/mousevent.i

# target to preprocess a source file
core/events/event-types/mousevent.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/event-types/mousevent.cpp.i
.PHONY : core/events/event-types/mousevent.cpp.i

core/events/event-types/mousevent.s: core/events/event-types/mousevent.cpp.s

.PHONY : core/events/event-types/mousevent.s

# target to generate assembly for a file
core/events/event-types/mousevent.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/core/events/event-types/mousevent.cpp.s
.PHONY : core/events/event-types/mousevent.cpp.s

debugger/logger.o: debugger/logger.cpp.o

.PHONY : debugger/logger.o

# target to build an object file
debugger/logger.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/debugger/logger.cpp.o
.PHONY : debugger/logger.cpp.o

debugger/logger.i: debugger/logger.cpp.i

.PHONY : debugger/logger.i

# target to preprocess a source file
debugger/logger.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/debugger/logger.cpp.i
.PHONY : debugger/logger.cpp.i

debugger/logger.s: debugger/logger.cpp.s

.PHONY : debugger/logger.s

# target to generate assembly for a file
debugger/logger.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/debugger/logger.cpp.s
.PHONY : debugger/logger.cpp.s

glad/glad.o: glad/glad.c.o

.PHONY : glad/glad.o

# target to build an object file
glad/glad.c.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/glad/glad.c.o
.PHONY : glad/glad.c.o

glad/glad.i: glad/glad.c.i

.PHONY : glad/glad.i

# target to preprocess a source file
glad/glad.c.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/glad/glad.c.i
.PHONY : glad/glad.c.i

glad/glad.s: glad/glad.c.s

.PHONY : glad/glad.s

# target to generate assembly for a file
glad/glad.c.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/glad/glad.c.s
.PHONY : glad/glad.c.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main.cpp.s
.PHONY : main.cpp.s

main/camera/camera.o: main/camera/camera.cpp.o

.PHONY : main/camera/camera.o

# target to build an object file
main/camera/camera.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/camera/camera.cpp.o
.PHONY : main/camera/camera.cpp.o

main/camera/camera.i: main/camera/camera.cpp.i

.PHONY : main/camera/camera.i

# target to preprocess a source file
main/camera/camera.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/camera/camera.cpp.i
.PHONY : main/camera/camera.cpp.i

main/camera/camera.s: main/camera/camera.cpp.s

.PHONY : main/camera/camera.s

# target to generate assembly for a file
main/camera/camera.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/camera/camera.cpp.s
.PHONY : main/camera/camera.cpp.s

main/color/Color.o: main/color/Color.cpp.o

.PHONY : main/color/Color.o

# target to build an object file
main/color/Color.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/Color.cpp.o
.PHONY : main/color/Color.cpp.o

main/color/Color.i: main/color/Color.cpp.i

.PHONY : main/color/Color.i

# target to preprocess a source file
main/color/Color.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/Color.cpp.i
.PHONY : main/color/Color.cpp.i

main/color/Color.s: main/color/Color.cpp.s

.PHONY : main/color/Color.s

# target to generate assembly for a file
main/color/Color.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/Color.cpp.s
.PHONY : main/color/Color.cpp.s

main/color/HSV.o: main/color/HSV.cpp.o

.PHONY : main/color/HSV.o

# target to build an object file
main/color/HSV.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/HSV.cpp.o
.PHONY : main/color/HSV.cpp.o

main/color/HSV.i: main/color/HSV.cpp.i

.PHONY : main/color/HSV.i

# target to preprocess a source file
main/color/HSV.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/HSV.cpp.i
.PHONY : main/color/HSV.cpp.i

main/color/HSV.s: main/color/HSV.cpp.s

.PHONY : main/color/HSV.s

# target to generate assembly for a file
main/color/HSV.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/HSV.cpp.s
.PHONY : main/color/HSV.cpp.s

main/color/cmyk.o: main/color/cmyk.cpp.o

.PHONY : main/color/cmyk.o

# target to build an object file
main/color/cmyk.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/cmyk.cpp.o
.PHONY : main/color/cmyk.cpp.o

main/color/cmyk.i: main/color/cmyk.cpp.i

.PHONY : main/color/cmyk.i

# target to preprocess a source file
main/color/cmyk.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/cmyk.cpp.i
.PHONY : main/color/cmyk.cpp.i

main/color/cmyk.s: main/color/cmyk.cpp.s

.PHONY : main/color/cmyk.s

# target to generate assembly for a file
main/color/cmyk.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/cmyk.cpp.s
.PHONY : main/color/cmyk.cpp.s

main/color/hsl.o: main/color/hsl.cpp.o

.PHONY : main/color/hsl.o

# target to build an object file
main/color/hsl.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/hsl.cpp.o
.PHONY : main/color/hsl.cpp.o

main/color/hsl.i: main/color/hsl.cpp.i

.PHONY : main/color/hsl.i

# target to preprocess a source file
main/color/hsl.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/hsl.cpp.i
.PHONY : main/color/hsl.cpp.i

main/color/hsl.s: main/color/hsl.cpp.s

.PHONY : main/color/hsl.s

# target to generate assembly for a file
main/color/hsl.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/hsl.cpp.s
.PHONY : main/color/hsl.cpp.s

main/color/htmlcolors.o: main/color/htmlcolors.cpp.o

.PHONY : main/color/htmlcolors.o

# target to build an object file
main/color/htmlcolors.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/htmlcolors.cpp.o
.PHONY : main/color/htmlcolors.cpp.o

main/color/htmlcolors.i: main/color/htmlcolors.cpp.i

.PHONY : main/color/htmlcolors.i

# target to preprocess a source file
main/color/htmlcolors.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/htmlcolors.cpp.i
.PHONY : main/color/htmlcolors.cpp.i

main/color/htmlcolors.s: main/color/htmlcolors.cpp.s

.PHONY : main/color/htmlcolors.s

# target to generate assembly for a file
main/color/htmlcolors.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/color/htmlcolors.cpp.s
.PHONY : main/color/htmlcolors.cpp.s

main/enginewindow/enginewindow.o: main/enginewindow/enginewindow.cpp.o

.PHONY : main/enginewindow/enginewindow.o

# target to build an object file
main/enginewindow/enginewindow.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/enginewindow/enginewindow.cpp.o
.PHONY : main/enginewindow/enginewindow.cpp.o

main/enginewindow/enginewindow.i: main/enginewindow/enginewindow.cpp.i

.PHONY : main/enginewindow/enginewindow.i

# target to preprocess a source file
main/enginewindow/enginewindow.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/enginewindow/enginewindow.cpp.i
.PHONY : main/enginewindow/enginewindow.cpp.i

main/enginewindow/enginewindow.s: main/enginewindow/enginewindow.cpp.s

.PHONY : main/enginewindow/enginewindow.s

# target to generate assembly for a file
main/enginewindow/enginewindow.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/enginewindow/enginewindow.cpp.s
.PHONY : main/enginewindow/enginewindow.cpp.s

main/materials/shadergen.o: main/materials/shadergen.cpp.o

.PHONY : main/materials/shadergen.o

# target to build an object file
main/materials/shadergen.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/materials/shadergen.cpp.o
.PHONY : main/materials/shadergen.cpp.o

main/materials/shadergen.i: main/materials/shadergen.cpp.i

.PHONY : main/materials/shadergen.i

# target to preprocess a source file
main/materials/shadergen.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/materials/shadergen.cpp.i
.PHONY : main/materials/shadergen.cpp.i

main/materials/shadergen.s: main/materials/shadergen.cpp.s

.PHONY : main/materials/shadergen.s

# target to generate assembly for a file
main/materials/shadergen.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/materials/shadergen.cpp.s
.PHONY : main/materials/shadergen.cpp.s

main/shapes/shape.o: main/shapes/shape.cpp.o

.PHONY : main/shapes/shape.o

# target to build an object file
main/shapes/shape.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/shapes/shape.cpp.o
.PHONY : main/shapes/shape.cpp.o

main/shapes/shape.i: main/shapes/shape.cpp.i

.PHONY : main/shapes/shape.i

# target to preprocess a source file
main/shapes/shape.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/shapes/shape.cpp.i
.PHONY : main/shapes/shape.cpp.i

main/shapes/shape.s: main/shapes/shape.cpp.s

.PHONY : main/shapes/shape.s

# target to generate assembly for a file
main/shapes/shape.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/shapes/shape.cpp.s
.PHONY : main/shapes/shape.cpp.s

main/svarogengine/svarogengine.o: main/svarogengine/svarogengine.cpp.o

.PHONY : main/svarogengine/svarogengine.o

# target to build an object file
main/svarogengine/svarogengine.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/svarogengine/svarogengine.cpp.o
.PHONY : main/svarogengine/svarogengine.cpp.o

main/svarogengine/svarogengine.i: main/svarogengine/svarogengine.cpp.i

.PHONY : main/svarogengine/svarogengine.i

# target to preprocess a source file
main/svarogengine/svarogengine.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/svarogengine/svarogengine.cpp.i
.PHONY : main/svarogengine/svarogengine.cpp.i

main/svarogengine/svarogengine.s: main/svarogengine/svarogengine.cpp.s

.PHONY : main/svarogengine/svarogengine.s

# target to generate assembly for a file
main/svarogengine/svarogengine.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/svarogengine/svarogengine.cpp.s
.PHONY : main/svarogengine/svarogengine.cpp.s

main/terrian/noisemap.o: main/terrian/noisemap.cpp.o

.PHONY : main/terrian/noisemap.o

# target to build an object file
main/terrian/noisemap.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/terrian/noisemap.cpp.o
.PHONY : main/terrian/noisemap.cpp.o

main/terrian/noisemap.i: main/terrian/noisemap.cpp.i

.PHONY : main/terrian/noisemap.i

# target to preprocess a source file
main/terrian/noisemap.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/terrian/noisemap.cpp.i
.PHONY : main/terrian/noisemap.cpp.i

main/terrian/noisemap.s: main/terrian/noisemap.cpp.s

.PHONY : main/terrian/noisemap.s

# target to generate assembly for a file
main/terrian/noisemap.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/terrian/noisemap.cpp.s
.PHONY : main/terrian/noisemap.cpp.s

main/terrian/perlin.o: main/terrian/perlin.cpp.o

.PHONY : main/terrian/perlin.o

# target to build an object file
main/terrian/perlin.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/terrian/perlin.cpp.o
.PHONY : main/terrian/perlin.cpp.o

main/terrian/perlin.i: main/terrian/perlin.cpp.i

.PHONY : main/terrian/perlin.i

# target to preprocess a source file
main/terrian/perlin.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/terrian/perlin.cpp.i
.PHONY : main/terrian/perlin.cpp.i

main/terrian/perlin.s: main/terrian/perlin.cpp.s

.PHONY : main/terrian/perlin.s

# target to generate assembly for a file
main/terrian/perlin.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/terrian/perlin.cpp.s
.PHONY : main/terrian/perlin.cpp.s

main/window/window.o: main/window/window.cpp.o

.PHONY : main/window/window.o

# target to build an object file
main/window/window.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/window/window.cpp.o
.PHONY : main/window/window.cpp.o

main/window/window.i: main/window/window.cpp.i

.PHONY : main/window/window.i

# target to preprocess a source file
main/window/window.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/window/window.cpp.i
.PHONY : main/window/window.cpp.i

main/window/window.s: main/window/window.cpp.s

.PHONY : main/window/window.s

# target to generate assembly for a file
main/window/window.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/main/window/window.cpp.s
.PHONY : main/window/window.cpp.s

math/camera_matrix.o: math/camera_matrix.cpp.o

.PHONY : math/camera_matrix.o

# target to build an object file
math/camera_matrix.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/camera_matrix.cpp.o
.PHONY : math/camera_matrix.cpp.o

math/camera_matrix.i: math/camera_matrix.cpp.i

.PHONY : math/camera_matrix.i

# target to preprocess a source file
math/camera_matrix.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/camera_matrix.cpp.i
.PHONY : math/camera_matrix.cpp.i

math/camera_matrix.s: math/camera_matrix.cpp.s

.PHONY : math/camera_matrix.s

# target to generate assembly for a file
math/camera_matrix.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/camera_matrix.cpp.s
.PHONY : math/camera_matrix.cpp.s

math/euler_angles.o: math/euler_angles.cpp.o

.PHONY : math/euler_angles.o

# target to build an object file
math/euler_angles.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/euler_angles.cpp.o
.PHONY : math/euler_angles.cpp.o

math/euler_angles.i: math/euler_angles.cpp.i

.PHONY : math/euler_angles.i

# target to preprocess a source file
math/euler_angles.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/euler_angles.cpp.i
.PHONY : math/euler_angles.cpp.i

math/euler_angles.s: math/euler_angles.cpp.s

.PHONY : math/euler_angles.s

# target to generate assembly for a file
math/euler_angles.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/euler_angles.cpp.s
.PHONY : math/euler_angles.cpp.s

math/matrix.o: math/matrix.cpp.o

.PHONY : math/matrix.o

# target to build an object file
math/matrix.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/matrix.cpp.o
.PHONY : math/matrix.cpp.o

math/matrix.i: math/matrix.cpp.i

.PHONY : math/matrix.i

# target to preprocess a source file
math/matrix.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/matrix.cpp.i
.PHONY : math/matrix.cpp.i

math/matrix.s: math/matrix.cpp.s

.PHONY : math/matrix.s

# target to generate assembly for a file
math/matrix.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/matrix.cpp.s
.PHONY : math/matrix.cpp.s

math/vec2.o: math/vec2.cpp.o

.PHONY : math/vec2.o

# target to build an object file
math/vec2.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/vec2.cpp.o
.PHONY : math/vec2.cpp.o

math/vec2.i: math/vec2.cpp.i

.PHONY : math/vec2.i

# target to preprocess a source file
math/vec2.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/vec2.cpp.i
.PHONY : math/vec2.cpp.i

math/vec2.s: math/vec2.cpp.s

.PHONY : math/vec2.s

# target to generate assembly for a file
math/vec2.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/vec2.cpp.s
.PHONY : math/vec2.cpp.s

math/vec3.o: math/vec3.cpp.o

.PHONY : math/vec3.o

# target to build an object file
math/vec3.cpp.o:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/vec3.cpp.o
.PHONY : math/vec3.cpp.o

math/vec3.i: math/vec3.cpp.i

.PHONY : math/vec3.i

# target to preprocess a source file
math/vec3.cpp.i:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/vec3.cpp.i
.PHONY : math/vec3.cpp.i

math/vec3.s: math/vec3.cpp.s

.PHONY : math/vec3.s

# target to generate assembly for a file
math/vec3.cpp.s:
	$(MAKE) -f CMakeFiles/SvarogGameEngine.dir/build.make CMakeFiles/SvarogGameEngine.dir/math/vec3.cpp.s
.PHONY : math/vec3.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... SvarogGameEngine"
	@echo "... edit_cache"
	@echo "... core/String.o"
	@echo "... core/String.i"
	@echo "... core/String.s"
	@echo "... core/ds-classes/ArrayList.o"
	@echo "... core/ds-classes/ArrayList.i"
	@echo "... core/ds-classes/ArrayList.s"
	@echo "... core/ds-classes/LinkedList.o"
	@echo "... core/ds-classes/LinkedList.i"
	@echo "... core/ds-classes/LinkedList.s"
	@echo "... core/events/Event.o"
	@echo "... core/events/Event.i"
	@echo "... core/events/Event.s"
	@echo "... core/events/EventDispatch.o"
	@echo "... core/events/EventDispatch.i"
	@echo "... core/events/EventDispatch.s"
	@echo "... core/events/EventListener.o"
	@echo "... core/events/EventListener.i"
	@echo "... core/events/EventListener.s"
	@echo "... core/events/InputEvent.o"
	@echo "... core/events/InputEvent.i"
	@echo "... core/events/InputEvent.s"
	@echo "... core/events/event-types/keyevent.o"
	@echo "... core/events/event-types/keyevent.i"
	@echo "... core/events/event-types/keyevent.s"
	@echo "... core/events/event-types/mousevent.o"
	@echo "... core/events/event-types/mousevent.i"
	@echo "... core/events/event-types/mousevent.s"
	@echo "... debugger/logger.o"
	@echo "... debugger/logger.i"
	@echo "... debugger/logger.s"
	@echo "... glad/glad.o"
	@echo "... glad/glad.i"
	@echo "... glad/glad.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... main/camera/camera.o"
	@echo "... main/camera/camera.i"
	@echo "... main/camera/camera.s"
	@echo "... main/color/Color.o"
	@echo "... main/color/Color.i"
	@echo "... main/color/Color.s"
	@echo "... main/color/HSV.o"
	@echo "... main/color/HSV.i"
	@echo "... main/color/HSV.s"
	@echo "... main/color/cmyk.o"
	@echo "... main/color/cmyk.i"
	@echo "... main/color/cmyk.s"
	@echo "... main/color/hsl.o"
	@echo "... main/color/hsl.i"
	@echo "... main/color/hsl.s"
	@echo "... main/color/htmlcolors.o"
	@echo "... main/color/htmlcolors.i"
	@echo "... main/color/htmlcolors.s"
	@echo "... main/enginewindow/enginewindow.o"
	@echo "... main/enginewindow/enginewindow.i"
	@echo "... main/enginewindow/enginewindow.s"
	@echo "... main/materials/shadergen.o"
	@echo "... main/materials/shadergen.i"
	@echo "... main/materials/shadergen.s"
	@echo "... main/shapes/shape.o"
	@echo "... main/shapes/shape.i"
	@echo "... main/shapes/shape.s"
	@echo "... main/svarogengine/svarogengine.o"
	@echo "... main/svarogengine/svarogengine.i"
	@echo "... main/svarogengine/svarogengine.s"
	@echo "... main/terrian/noisemap.o"
	@echo "... main/terrian/noisemap.i"
	@echo "... main/terrian/noisemap.s"
	@echo "... main/terrian/perlin.o"
	@echo "... main/terrian/perlin.i"
	@echo "... main/terrian/perlin.s"
	@echo "... main/window/window.o"
	@echo "... main/window/window.i"
	@echo "... main/window/window.s"
	@echo "... math/camera_matrix.o"
	@echo "... math/camera_matrix.i"
	@echo "... math/camera_matrix.s"
	@echo "... math/euler_angles.o"
	@echo "... math/euler_angles.i"
	@echo "... math/euler_angles.s"
	@echo "... math/matrix.o"
	@echo "... math/matrix.i"
	@echo "... math/matrix.s"
	@echo "... math/vec2.o"
	@echo "... math/vec2.i"
	@echo "... math/vec2.s"
	@echo "... math/vec3.o"
	@echo "... math/vec3.i"
	@echo "... math/vec3.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
