#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "fancyPower.hpp"

// write your test cases here
TEST_CASE("Test case", "fancyPower"){
  //run function with known powers ie. 2^3 = 8
  REQUIRE(fancyPower(2,3) == 8);

  //run function with 4^4 = 256
  REQUIRE(fancyPower(4,4) == 256);

  //3^7 = 2187
  REQUIRE(fancyPower(3,7) == 2187);

  //12^8 = 429981696
  REQUIRE(fancyPower(12,8) == 429981696);

  //300^0 = 1
  REQUIRE(fancyPower(300,0) == 1);

  //4^1 = 4
  REQUIRE(fancyPower(4,1) == 4);
}
