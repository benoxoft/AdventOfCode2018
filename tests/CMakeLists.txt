
add_executable(test_day1 test_day1.cpp test_main.cpp)
target_link_libraries(test_day1 day1)
target_link_libraries(test_day1 Catch2::Catch2)
