cmake_minimum_required( VERSION 3.10 )

project( MyString )

add_executable( program src/main.cpp src/MyString.cpp )

INCLUDE_DIRECTORIES ( include )
