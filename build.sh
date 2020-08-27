#!/bin/bash

rm -rf build
DIR=`pwd`

cd $DIR
mkdir build
cd build
cmake ..

#先cd 到上一级编译，后续要把makefile 在build 下生成。
cd ..

make -j8
# cp -r lib ..
cd $DIR
