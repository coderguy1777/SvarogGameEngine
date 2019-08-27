#!/bin/bash
# build script
cmake -Bbuilds -H.
echo "cmake executed, beginning make...."
cd builds && make
echo "$USER , make has finished the build, now exiting..."
exit 0
