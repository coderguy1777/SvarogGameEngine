#!/bin/sh
git add .
COMMIT_MSG=0
echo "Type a commit message."
read COMMIT_MSG
git commit -m "$COMMIT_MSG"
git push
exit 0
