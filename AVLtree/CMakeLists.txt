# требование нужной версии самого cmake
cmake_minimum_required(VERSION 3.1)

# как мы называемся
project(tree)

# требования к компилятору
set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES *.cpp )

add_executable(tree ${SOURCES} ../SimpleTree/Container.cpp ../SimpleTree/SimpleTree.cpp)


