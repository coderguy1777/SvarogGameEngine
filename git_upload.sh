#!/bin/sh
git add .
COMMIT_M=0
echo "TYPE GIT COMMIT MESSAGE"
read COMMIT_M
git commit -m "$COMMIT_M"
git push
exit 0
