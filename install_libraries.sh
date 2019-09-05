#!/bin/bash
# library name variables
LIB_GLFW="libglfw3-dev"
LIB_X11="libx11-dev"
LIB_BLD_ESSENTIAL="build-essential"
LIB_XINERMA="x11proto-xinerama-dev"
LIB_GLU="libglu1-mesa-dev"
LIB_DL="libdl-dev"
LIB_XI="libxi-dev"
LIB_XRANDR="libxrandr-dev"
LIB_ASSIMP="libassimp-dev"
LIB_XCURSOR="libxcursor-dev"

# running of checks for libraries.
GLFW_CHECK=$(dpkg -s libglfw3-dev|grep installed)
echo Checking for glfw3: $GLFW_CHECK
if [ "" == "$GLFW_CHECK" ]; then
    echo "Setting up glfw3 now..."
    cd && mkdir glfw_dir
    cd glfw_dir && git clone https://github.com/glfw/glfw
    cd glfw && cmake .
    cmake -DBUILD_SHARED_LIBS=ON .
elif [ "" != "$GLFW_CHECK" ]; then
    echo "GLFW is installed, continuing lib check."
fi

X11_CHECK=$(dpkg -s libx11-dev|grep installed)
echo Checking for X11: $X11_Check
if [ "" == "$X11_CHECK" ]; then 
    echo "Setting up X11 now...."
    sudo apt install libx11-dev && sudo apt update
elif [ "" != "$X11_CHECK" ]; then 
    echo "X11 is installed, continuing lib check."
fi

BLD_ESNT=$(dpkg -s build-essential|grep installed)
echo Checking for build-essential: $BLD_ESNT
if [ "" == "$BLD_ESNT" ]; then
    echo "Setting up build essential now..."
    sudo apt-get install build-essential
elif [ "" != "$BLD_ESNT" ]; then
    echo "Build Essential is installed, continuing lib check."
fi

XINERMA_CHECK=$(dpkg -s x11proto-xinerama-dev|grep installed)
echo Checking for Xinerma: $XINERMA_CHECK
if [ "" == "$XINERMA_CHECK" ]; then
    echo "Setting up Xinerma now..."
    sudo apt-get install x11proto-xinerama-dev
elif [ "" != "$XINERMA_CHECK" ]; then
    echo "Xinerma installed, continuing lib check."
fi

GLU_CHECK=$(dpkg -s libglu1-mesa-dev|grep installed)
echo Checking for GLU: $GLU_CHECK
if [ "" == "$GLU_CHECK" ]; then
    echo "Setting up GLU now..."
    sudo apt-get install libglu1-mesa-dev
elif [ "" != "$XINERMA_CHECK" ]; then
    echo "GLU installed, continuing lib check."
fi

# TODO: check if dl needs to be installed
DL_CHECK=$(dpkg -s libdl-dev|grep installed)
echo Checking for DL: $DL_CHECK
if [ "" == "$DL_CHECK" ]; then
    echo "Setting up DL now..."
    sudo apt-get install dl
elif [ "" != "$DL_CHECK" ]; then
    echo "dl installed, continuing lib check."
fi