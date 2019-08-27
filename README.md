# Svarog Engine
## An open source C++ path tracing game engine, made with GLFW and OpenGL.

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
To build the engine, run the bash script `build.sh` with `sh build.sh` or simply `./build.sh` to build, then head into the builds directory, and run: `./SvarogGameEngine` to run the engine!
