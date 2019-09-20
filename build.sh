#!/bin/bash
# build script
cmake -Bbuilds -H. -Wno-dev -DCMAKE_BUILD_TYPE=DEBUG
echo "cmake executed, beginning make...."
cd builds && make
echo "$USER , Svarog engine ready for use, head to builds DIR to run!"
exit 0
