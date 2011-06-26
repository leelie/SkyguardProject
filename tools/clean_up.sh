#!/bin/bash
#Author: Patryk Mirecki
#Description: Clean-up project from unnecessary files. Use before commit

extensions=("*.ilk" "*.exe" "*.pdb" "*.log")

for name in ${extensions[@]}
do
find ../. -name $name -exec rm -rf {} \;
done
rm -rf ../win/VC100/*
 
echo 'Run [OK]'
