#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "geometry.h"

TEST_CASE("Test Equality Function") {
	REQUIRE( Equals(TVector3{ 1, 2, 3 }, TVector3{ 1, 2, 3 }) );
	REQUIRE_FALSE( Equals(TVector3{ 1, 2, 3 }, TVector3{ 3, 2, 1 }) );

	SECTION("Test Add Function")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = Add(TVector3{ 1, 1, 1 }, TVector3{ 1, 2, 3 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 2, 3, 4 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}

	SECTION("Test Subtract Function")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = Subtract(TVector3{ 1, 2, 3 }, TVector3{ 1, 1, 1 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 0, 1, 2 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}
}