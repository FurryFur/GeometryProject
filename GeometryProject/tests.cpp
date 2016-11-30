#define _USE_MATH_DEFINES
#include <math.h>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "geometry.h"

TEST_CASE("Test Equality Function") {
	REQUIRE(Equals(TVector3{ 1, 2, 0.8f - 0.7f }, TVector3{ 1, 2, 0.1f }));
	REQUIRE(Equals(TVector3{ 1, 2, sin(M_PI) }, TVector3{ 1, 2, 0 }));
	REQUIRE_FALSE( Equals(TVector3{ 1, 2, 3 }, TVector3{ 3, 2, 1 }) );
	REQUIRE_FALSE(Equals(TVector3{ 1, 2, sin(M_PI + 0.00001f) }, TVector3{ 1, 2, sin(M_PI) }));
	REQUIRE(Equals(TVector3{ 1000000, 2, 2 }, TVector3{ 999992 + 8, 2, 2 }));
	REQUIRE_FALSE(Equals(TVector3{ 1000000, 2, 2 }, TVector3{ 999992 + 8.1, 2, 2 }));

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

	SECTION("Test Scale Function")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = ScaleVector(TVector3{ 1, 2, 3 }, 3, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 3, 6, 9}));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}

	SECTION("Test CrossProduct Function")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = CrossProduct(TVector3{ 3, 2, 2 }, TVector3{ 4, 5, 6 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 2, 10, 7 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}
}