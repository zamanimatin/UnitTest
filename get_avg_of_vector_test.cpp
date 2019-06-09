#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "get_avg_of_vector.hpp"
using namespace std;

TEST_CASE("empty vector")
{
    vector<int> v;
    REQUIRE_THROWS_AS(get_avg_of_vector(v),std::length_error);
}
TEST_CASE("simple vector with just zero")
{
    vector<int> v;
    v.push_back(0);
    REQUIRE(get_avg_of_vector(v)==0);
}
TEST_CASE("simple vector with various values")
{
    vector<int> v;
    for(int i=0;i<10;i++)
        v.push_back(i+1);
    REQUIRE(get_avg_of_vector(v)==5.5);
}
TEST_CASE("vector with only negative values")
{
    vector<int>v;
    for(int i=0;i<10;i++)
        v.push_back(-(i+1));
    REQUIRE(get_avg_of_vector(v)==-5.5);
}
TEST_CASE("vector of symmetric range")
{
    vector<int>v;
    for(int i=-10;i<11;i++)
        v.push_back(i);
    REQUIRE(get_avg_of_vector(v)==0);
}
TEST_CASE("vector of various positive and negative values")
{
    vector<int>v;
    for(int i=-20;i<-6;i++)
        v.push_back(i);
    for(int i=0;i<10;i++)
        v.push_back(i);
    REQUIRE(get_avg_of_vector(v)==-6);
}
