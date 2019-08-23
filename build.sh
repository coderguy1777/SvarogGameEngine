#!/bin/bash
# build script
BUILD_DIR = "/home/jordan/Documents/SvarogGameEngine/builds"
cmake -Bbuilds -H.
echo "cmake executed, beginning make...."
cd builds && make
echo "$USER , make has finished the build, now exiting..."
exit 0
