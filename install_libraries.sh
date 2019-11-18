#!/bin/bash
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

XI_CHECK=$(dpkg -s libxi-dev|grep installed)
echo Checking for XI: $XI_CHECK
if [ "" == "$XI_CHECK" ]; then
    echo "Setting up Xi now..."
    sudo apt-get install libxi-dev
elif [ "" != "$XI_CHECK" ]; then
    echo "Xi installed, continuing lib check."
fi

XRANDR_CHECK=$(dpkg -s libxrandr-dev|grep installed)
echo Checking for XRANDR: $XRANDR_CHECK
if [ "" == "$XRANDR_CHECK" ]; then
    echo "Setting up Xrandr now..."
    sudo apt-get install libxrandr-dev
elif [ "" != "$XRANDR_CHECK" ]; then
    echo "Xrandr installed, continuing lib check."
fi

ASSIMP_CHECK=$(dpkg -s libassimp-dev|grep installed)
echo Checking for ASSIMP: $ASSIMP_CHECK
if [ "" == "$ASSIMP_CHECK" ]; then
    echo "Setting up assimp now..."
    sudo apt-get install libassimp-dev
elif [ "" != "$ASSIMP_CHECK" ]; then
    echo "assimp installed, continuing lib check."
fi

XCURSOR_CHECK=$(dpkg -s libxcursor-dev|grep installed)
echo Checking for XCURSOR: $XCURSOR_CHECK
if [ "" == "$XCURSOR_CHECK" ]; then
    echo "Setting up Xcursor now..."
    sudo apt-get install libxcursor-dev
elif [ "" != "$XCURSOR_CHECK" ]; then
    echo "Xcursor installed, continuing lib check."
fi

BOOST_CHECK=$(dpkg -s libboost-all-dev|grep installed)
echo Checking for BOOST: $BOOST_CHECK
if [ "" == "$BOOST_CHECK" ]; then
    echo "Setting up Boost now..."
    sudo apt-get install libboost-all-dev
elif [ "" != "$BOOST_CHECK" ]; then
    echo "Boost is installed, continuing lib check."
fi