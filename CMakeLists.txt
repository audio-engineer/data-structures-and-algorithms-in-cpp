cmake_minimum_required(VERSION 3.26)
project(data_structures_and_algorithms_in_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(data_structures_and_algorithms_in_cpp main.cc
        data_structures_and_algorithms_in_cpp/hash_table/hash_table.cc
        data_structures_and_algorithms_in_cpp/hash_table/hash_table.h
        data_structures_and_algorithms_in_cpp/hash_table/item.cc
        data_structures_and_algorithms_in_cpp/hash_table/item.h
        data_structures_and_algorithms_in_cpp/hash_table/hash_table_utilities.cc
        data_structures_and_algorithms_in_cpp/hash_table/hash_table_utilities.h
        data_structures_and_algorithms_in_cpp/hash_table/hash_table_application.cc
        data_structures_and_algorithms_in_cpp/hash_table/hash_table_application.h
)
