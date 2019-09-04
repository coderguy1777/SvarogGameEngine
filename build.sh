#!/bin/bash
# build script
cmake -Bbuilds -H.
echo "cmake executed, beginning make...."
cd builds && make
echo "$USER , Svarog engine ready for use, head to builds DIR to run!"
exit 0
