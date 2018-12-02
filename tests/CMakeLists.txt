
set(CURRENT_DAY 2)

add_executable(test_AoC test_day${CURRENT_DAY}.cpp test_main.cpp)
target_link_libraries(test_AoC day${CURRENT_DAY})
target_link_libraries(test_AoC Catch2::Catch2)
