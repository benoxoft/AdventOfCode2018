#include <iostream>

#include <catch2/catch.hpp>
#include "day1.hpp"
#include "helpers.hpp"

#define PART_1_EXAMPLE_1 "+1\n+1\n+1"
#define PART_1_ANSWER_1 3

#define PART_1_EXAMPLE_2 "+1\n+1\n-2"
#define PART_1_ANSWER_2 0

#define PART_1_EXAMPLE_3 "-1\n-2\n-3"
#define PART_1_ANSWER_3 -6

TEST_CASE( "test puzzle examples part 1", "[day 1]" ) {
    REQUIRE( find_puzzle_answer_part_1(PART_1_EXAMPLE_1) == PART_1_ANSWER_1 );
    REQUIRE( find_puzzle_answer_part_1(PART_1_EXAMPLE_2) == PART_1_ANSWER_2 );
    REQUIRE( find_puzzle_answer_part_1(PART_1_EXAMPLE_3) == PART_1_ANSWER_3 );
}

TEST_CASE( "find solution part 1", "[day 1]" ) {
    auto input = get_puzzle_input(1);
    int answer = find_puzzle_answer_part_1(input);
    std::cout << "ANSWER PART 1: " << answer << std::endl;
    REQUIRE(answer == 508);
}


#define PART_2_EXAMPLE_1 "+1\n-1"
#define PART_2_ANSWER_1 0

#define PART_2_EXAMPLE_2 "+3\n+3\n+4\n-2\n-4"
#define PART_2_ANSWER_2 10

#define PART_2_EXAMPLE_3 "-6\n+3\n+8\n+5\n-6"
#define PART_2_ANSWER_3 5

#define PART_2_EXAMPLE_4 "+7\n+7\n-2\n-7\n-4"
#define PART_2_ANSWER_4 14

TEST_CASE("test puzzle examples part 2", "[day 1]") {
    REQUIRE( find_puzzle_answer_part_2(PART_2_EXAMPLE_1) == PART_2_ANSWER_1 );
    REQUIRE( find_puzzle_answer_part_2(PART_2_EXAMPLE_2) == PART_2_ANSWER_2 );
    REQUIRE( find_puzzle_answer_part_2(PART_2_EXAMPLE_3) == PART_2_ANSWER_3 );
    REQUIRE( find_puzzle_answer_part_2(PART_2_EXAMPLE_4) == PART_2_ANSWER_4 );
}

TEST_CASE( "find solution part 2", "[day 1]" ) {
    auto input = get_puzzle_input(1);
    int answer = find_puzzle_answer_part_2(input);
    std::cout << "ANSWER PART 2: " << answer << std::endl;
    REQUIRE(answer == 549);
}
