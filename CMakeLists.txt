cmake_minimum_required(VERSION 3.12)
project(Lab15 C)

set(CMAKE_C_STANDARD 11)

include_directories(genericArray)
include_directories(utils)
include_directories(words)

add_executable(Lab15
        genericArray/genericArray.c
        genericArray/genericArray.h
        utils/fileUtils.c
        utils/fileUtils.h
        utils/utils.c
        utils/utils.h
        words/word.h
        words/word.c
        cscd240Lab15.c)
