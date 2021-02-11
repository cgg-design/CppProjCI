// This tells Catch to provide a main() - only do this in one cpp file
#define CATCH_CONFIG_MAIN  

#include "catch2/catch.hpp"
#include "my_lib.hpp"
#include "calc_add.hpp"
#include "calc_sub.hpp"
#include "calc_mul.hpp"
#include "calc_square.hpp"

TEST_CASE( "Test addition function", "[add]" ) {
    int x = add_values(2,2);
    REQUIRE(x == 4);
}  

TEST_CASE("Test my vector function", "TestVector")
{
    linalg::aliases::float3 v = print_linalg_vector();

    REQUIRE(1 == v[0]);
    REQUIRE(2 == v[1]);
    REQUIRE(3 == v[2]);
}

TEST_CASE("Test my boost function", "TestBoost")
{
    bool b = print_boost_version();
    
    REQUIRE(true == b); 
}

TEST_CASE( "Test sub", "[sub]" ) {
    int x = sub_values(12,7);
    REQUIRE(x == 5);
}  

TEST_CASE( "Test mul", "[mul]" ) {
    int x = mul_values(2,2);
    REQUIRE(x == 4);
}  

TEST_CASE( "Test sqr", "[sqr]" ) {
    int x = square_values(5);
    REQUIRE(x == 25);
}  