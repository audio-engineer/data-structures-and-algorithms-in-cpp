project(hash_table CXX)

file(GLOB SRC_FILES *.cc *.h)
add_executable(${PROJECT_NAME} ${SRC_FILES})
