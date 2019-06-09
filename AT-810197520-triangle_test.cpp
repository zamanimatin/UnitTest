#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Triangle.hpp"
using namespace std;

TEST_CASE("A triangle with no value for sides")
{   
    Triangle t();
    REQUIRE_THROWS_AS(t,std::invalid_argument);
}
TEST_CASE("A triangle with one zero side")
{
    REQUIRE_THROWS_AS(Triangle(0,2,3),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(2,0,3),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(2,3,0),std::invalid_argument);
}
TEST_CASE("A triangle with not valid arguments")
{
    REQUIRE_THROWS_AS(Triangle(1,2,3),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(1,3,2),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(2,1,3),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(2,3,1),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(3,2,1),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(3,1,2),std::invalid_argument);
}
TEST_CASE("A triangle with a negative value")
{
    REQUIRE_THROWS_AS(Triangle(-1,3,4),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(-1,4,3),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(3,-1,4),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(4,-1,3),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(3,4,-1),std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(4,3,-1),std::invalid_argument);
}
TEST_CASE("get primeter of a simple triangle")
{
    Triangle t(5,2,4);
    REQUIRE(t.get_perimeter()==11);
}
TEST_CASE("get kind of a simple triangle")
{
    Triangle t(5,2,4);
    REQUIRE(t.get_kind()==Triangle::Kind::SCALENE);
}
TEST_CASE("get area of a simple triangle")
{
    Triangle t(5,2,4);
    REQUIRE(t.get_area()==3.79967);
} 
TEST_CASE("get kind of a ISOSCELES triangle")
{
    REQUIRE(Triangle(3,3,5).get_kind()==Triangle::Kind::ISOSCELES);
    REQUIRE(Triangle(5,3,3).get_kind()==Triangle::Kind::ISOSCELES);
    REQUIRE(Triangle(3,5,3).get_kind()==Triangle::Kind::ISOSCELES);
}
TEST_CASE("get kind of a EQUILATERAL triangle")
{
    REQUIRE(Triangle(3,3,3).get_kind()==Triangle::Kind::EQUILATERAL);
}
TEST_CASE("get area of a ISOSCELES triangle")
{
    REQUIRE(Triangle(4,4,6).get_area()==3*sqrt(7));
}
TEST_CASE("get area of a EQUILATERAL triangle")
{
    REQUIRE(Triangle(4,4,4).get_area()==4*sqrt(3));
}
TEST_CASE("is_isosceles test for true answers")
{
    class TriangleUnderTest : private Triangle
    {
        public:
            TriangleUnderTest(int _side1,int _side2,int _side3) : Triangle(_side1,_side2,_side3){}
            bool get_if_isosceles(){return is_isosceles();}
    };
    REQUIRE(TriangleUnderTest(1,3,3).get_if_isosceles()==true);
    REQUIRE(TriangleUnderTest(3,1,3).get_if_isosceles()==true);
    REQUIRE(TriangleUnderTest(3,3,1).get_if_isosceles()==true);
}
TEST_CASE("is_isosceles test to check for false answers")
{
    class TriangleUnderTest : private Triangle
    {
        public:
            TriangleUnderTest(int _side1,int _side2,int _side3) : Triangle(_side1,_side2,_side3){}
            bool get_if_isosceles(){return is_isosceles();}
    };
    REQUIRE(TriangleUnderTest(2,3,4).get_if_isosceles()==false);
}
TEST_CASE("is_equilateral test for true answers")
{
    class TriangleUnderTest : public Triangle
    {
        public:
            TriangleUnderTest(int _side1,int _side2,int _side3) : Triangle(_side1,_side2,_side3){}
            bool get_if_equilateral(){return is_equilateral();}
    };
    REQUIRE(TriangleUnderTest(3,3,3).get_if_equilateral()==true);
}
TEST_CASE("is_equilateral test for false answers")
{
    class TriangleUnderTest : public Triangle
    {
        public:
            TriangleUnderTest(int _side1,int _side2,int _side3) : Triangle(_side1,_side2,_side3){}
            bool get_if_equilateral(){return is_equilateral();}
    };
    REQUIRE(TriangleUnderTest(2,3,4).get_if_equilateral()==false);
    REQUIRE(TriangleUnderTest(3,3,4).get_if_equilateral()==false);
    REQUIRE(TriangleUnderTest(3,4,3).get_if_equilateral()==false);
    REQUIRE(TriangleUnderTest(4,3,3).get_if_equilateral()==false);
}