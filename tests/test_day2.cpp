#include <iostream>

#include <catch2/catch.hpp>
#include "day2.hpp"
#include "helpers.hpp"

/* 
abcdef contains no letters that appear exactly two or three times.
bababc contains two a and three b, so it counts for both.
abbcde contains two b, but no letter appears exactly three times.
abcccd contains three c, but no letter appears exactly two times.
aabcdd contains two a and two d, but it only counts once.
abcdee contains two e.
ababab contains three a and three b, but it only counts once.
*/

TEST_CASE( "test puzzle examples part 1", "[day 2]" ) {
  std::string example = 
  R"(abcdef
bababc
abbcde
abcccd
aabcdd
abcdee
ababab
)";

  REQUIRE( find_puzzle_answer_part_1(example) == 12 );
}

TEST_CASE( "find solution part 1", "[day 2]" ) {
    auto input = get_puzzle_input(2);
    int answer = find_puzzle_answer_part_1(input);
    std::cout << "ANSWER PART 1: " << answer << std::endl;
    REQUIRE(answer == 4920);
}

TEST_CASE( "test puzzle examples part 2", "[day 2]" ) {
  std::string example = 
  R"(abcde
fghij
klmno
pqrst
fguij
axcye
wvxyz)";

  REQUIRE( find_puzzle_answer_part_2(example) == "fgij" );
}

TEST_CASE( "find solution part 2", "[day 2]" ) {
    auto input = get_puzzle_input(2);
    auto answer = find_puzzle_answer_part_2(input);
    std::cout << "ANSWER PART 2: " << answer << std::endl;
    REQUIRE(answer == "fonbwmjquwtapeyzikghtvdxl");
}
