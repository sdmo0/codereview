cmake_minimum_required (VERSION 3.5)
project (codereview)

FILE(GLOB SRCFILES src/*.cc)

INCLUDE_DIRECTORIES(src)

add_executable(codereview ${SRCFILES})