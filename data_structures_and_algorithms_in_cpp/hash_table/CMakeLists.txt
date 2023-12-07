project(hash_table CXX)

add_executable(${PROJECT_NAME}
        bucket.cc
        hash_table.cc
        hash_table_application.cc
        hash_table_utilities.cc
        main.cc
        node.cc
)
target_include_directories(${PROJECT_NAME} PRIVATE .)
