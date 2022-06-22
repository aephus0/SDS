cmake_minimum_required(VERSION 3.0.0)
project(SDS 
	VERSION 0.1.0
	DESCRIPTION "Student Database System"
	LANGUAGES C
	)

include(CTest)
enable_testing()

add_executable(SDS main.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_C_STANDARD C17)
set(CMAKE_C_STANDARD_REQUIRED True)
include(CPack)
