# Svarog Game Engine
## A Path Tracing Game engine made with GLFW and OpenGL, using C++.

# How to build Svarog Engine
## Step 1: clone the repository to your machine.
To clone the repository, do: `git clone https://github.com/coderguy1777/SvarogGameEngine to get the engine source`
code. It's also a good idea to make a directory on your machine to clone it into for the sake of being orgainzed.

## Step 2: Install the dependencies.
For installing the dependencies needed for the Engine to be buildable, run the following 
command to obtain the depedencies needed as shown down below: 

### Command for dependicies:
`sudo apt-get install build-essential libx11-dev libxcursor-dev libxinerama-dev libgl1-mesa-dev libglu-dev libasound2-dev libpulse-dev libfreetype6-dev libudev-dev libxi-dev libxrandr-dev libglfw3-dev cmake gedit git.`

Then, to get the OpenGL loader, glad, go to the site https://glad.dav1d.de/ and set the gl option to OpenGL 4.6, 
and the profile to Core instead of compatibility. You are also going to want to check the box that says `omit KHR`
also. Once you download glad, you'll need to configure the header file to be on your machine locally if you run linux. With Windows, the new linux terminal that's in microsofts new Terminal, Windows terminal, this process should work on windows as well.
To make sure the header for `glad.h` is included properly on your machine, run the following commands in order:

  `git clone https://github.com/Dav1dde/glad.git`
  
  `cmake ./`
  
  `make`
  
  `sudo cp -a include /usr/local/`
  

Once you have all that done and built with cmake, you should be good to go and ready to build the engine.

## Step 3: Building Svarog Engine.
As of right now, Svarog Engine is not built with cmake due to the low amount of files used within the project, having no
need for the use of cmake in my opinion. This may change in the future however for building the engine.

But anyway, to start out, use gedit or any text editor and enter into the cloned engine directory, and find the bash script: compile.sh. Once you find this file, open the file with `gedit compile.sh` to edit the paths of where some of the source files are located to be up to date with your machine. 

If you are using windows terminal to build the engine, then don't make the paths to them as they would be written on linux. But, once you are done fixing the paths, you are now able to build the engine. 

To do this, run the compiling bash script `./compile.sh`, to build the engine. Once it completes the building process, run the bash script `./run.sh` to run the engine. If everything built correctly, you should have a working build on your machine once you use `./run.sh`.

## Step 4: Updating your local build.
When you make new classes to add into the functionallity itself, you should include the header file in the libs.h file, as it 
serves to make it easier to include in other files and stay orgainzed. To compile the new .cpp files for the class if it has 
any, add the path to it in the compile.sh script, and you should be good to go. You then can update your engine build by using
the following command, similar to the initial build process, but you can do it that way or this way as follows: `./compile.sh && ./run.sh`
