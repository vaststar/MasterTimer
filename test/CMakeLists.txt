
set(CMAKE_CXX_STANDARD 11)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} DIR_SRCS)

#build exe
add_executable(testTimer ${DIR_SRCS})

target_link_libraries(testTimer PRIVATE MasterTimer)

add_test (NAME test_timer1 COMMAND testTimer)