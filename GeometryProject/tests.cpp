#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "geometry.h"

TEST_CASE("Test Equality Functions for both 2D and 3D") {
	REQUIRE(Equals(TVector3{ 1, 2, 0.8f - 0.7f }, TVector3{ 1, 2, 0.1f }));
	REQUIRE(Equals(TVector3{ 1, 2, sin(M_PI) }, TVector3{ 1, 2, 0 }));
	REQUIRE_FALSE( Equals(TVector3{ 1, 2, 3 }, TVector3{ 3, 2, 1 }) );
	REQUIRE_FALSE(Equals(TVector3{ 1, 2, sin(M_PI + 0.00001f) }, TVector3{ 1, 2, sin(M_PI) }));
	REQUIRE(Equals(TVector3{ 1000000, 2, 2 }, TVector3{ 999992 + 8, 2, 2 }));
	REQUIRE_FALSE(Equals(TVector3{ 1000000, 2, 2 }, TVector3{ 999992 + 8.1, 2, 2 }));

	REQUIRE(Equals(TVector2{ 1, 0.8f - 0.7f }, TVector2{ 1, 0.1f }));
	REQUIRE(Equals(TVector2{ 1, sin(M_PI) }, TVector2{ 1, 0 }));
	REQUIRE_FALSE(Equals(TVector2{ 1, 3 }, TVector2{ 3, 1 }));
	REQUIRE_FALSE(Equals(TVector2{ 1, sin(M_PI + 0.00001f) }, TVector2{ 1, sin(M_PI) }));
	REQUIRE(Equals(TVector2{ 1000000, 2 }, TVector2{ 999992 + 8, 2 }));
	REQUIRE_FALSE(Equals(TVector2{ 1000000, 2 }, TVector2{ 999992 + 8.1, 2 }));

	SECTION("Test Add Function in 3D")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = Add(TVector3{ 1, 1, 1 }, TVector3{ 1, 2, 3 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 2, 3, 4 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}

	SECTION("Test Add Function in 2D")
	{
		TVector2 rResultant;
		TVector2 rReturnedVal = Add(TVector2{ 1, 1}, TVector2{ 1, 2 }, rResultant);
		REQUIRE(Equals(rResultant, TVector2{ 2, 3 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}

	SECTION("Test Subtract Function in 3D")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = Subtract(TVector3{ 1, 2, 3 }, TVector3{ 1, 1, 1 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 0, 1, 2 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}

	SECTION("Test Subtract Function in 2D")
	{
		TVector2 rResultant;
		TVector2 rReturnedVal = Subtract(TVector2{ 1, 2 }, TVector2{ 1, 1 }, rResultant);
		REQUIRE(Equals(rResultant, TVector2{ 0, 1 }));
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

	SECTION("Test Magnitude Function")
	{
		float fReturnedVal = Magnitude(TVector3{ 1, 2, 3 });
		REQUIRE(fReturnedVal == Approx(sqrt(14)));
	}

	SECTION("Test Dot Product Function")
	{
		float fReturnedVal = DotProduct(TVector3{ 2, 2, 2 }, TVector3{ 1, 2, 3 });
		REQUIRE(fReturnedVal == Approx(12));
	}

	SECTION("Test Normalise Function")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = Normalise(TVector3{ 3, 0, 0 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 1, 0, 0 }));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}*/

	SECTION("Test ComputeLineSphereIntersection Function")
	{
		TVector3 rIntersectionPoint1;
		TVector3 rIntersectionPoint2;
		EIntersections rReturnedVal = ComputeLineSphereIntersection(T3DLine{ TVector3{ 0, 1, 0 }, TVector3{ 3, 0, 0 } }, TSphere{ TVector3{ 0, 1, 0 }, 2 }, 
			rIntersectionPoint1, rIntersectionPoint2);
		REQUIRE(Equals(rIntersectionPoint1, TVector3{ 2, 1, 0 }));
		REQUIRE(Equals(rIntersectionPoint2, TVector3{ -2, 1, 0 }));
		//REQUIRE(Equals(rReturnedVal, INTERSECTION_TWO));
	}

	SECTION("Test ComputeAngleBetween Function for 2D Vectors")
	{
		float fReturnVal = ComputeAngleBetween(TVector2{ 3.0f, 0 }, TVector2{ 0, 5.0f });
		REQUIRE(fReturnVal == Approx(M_PI / 2));
	}

	SECTION("Test ComputeAngleBetween Function for 3D Vectors")
	{
		float fReturnVal = ComputeAngleBetween(TVector3{ 3.0f, 0, 0 }, TVector3{ 0, 5.0f, 0 });
		REQUIRE(fReturnVal == Approx(M_PI / 2));
	}

	SECTION("Test Projection Function")
	{
		TVector3 rResultant;
		TVector3 rReturnedVal = Projection(TVector3{ 1, 1, 0 }, TVector3{ 3, 0, 0 }, rResultant);
		REQUIRE(Equals(rResultant, TVector3{ 1, 0, 0}));
		REQUIRE(Equals(rResultant, rReturnedVal));
	}

	SECTION("Test Compute Distance Point To Line Function")
	{
		T3DLine rTestline{ { 1, 3, 4 } , { 1, -2, -3} };
		float fReturnVal = ComputeDistancePointToLine(rTestline, { 4, 1, -2 });
		REQUIRE(fReturnVal == Approx(sqrt(854)/14));
	}

	SECTION("Test Compute Distance Circle To Circle Function")
	{
		float fReturnVal = ComputeDistanceCircleToCircle(TCircle{ { 2, 5 }, 4 }, TCircle{ { -4, -6 }, 8 });
		REQUIRE(fReturnVal == Approx(sqrt(157)));
	}

	SECTION("Test ComputeDistanceCircleToTriangle Function in 2D")
	{
		TVector2 v2p1{ -1, -1 };
		TVector2 v2p2{ 0, 2 };
		TVector2 v2p3{ 1, -1 };
		TTriangle2 tTri{ v2p1, v2p2, v2p3 };
		
		float fRadius = 5;
		TVector2 v2CircleCentre{ 6, 0 };
		TCircle cCircle{ v2CircleCentre, fRadius };
		REQUIRE(ComputeDistanceCircleToTriangle(cCircle, tTri) == Approx(6.0f));
	}

	SECTION("Test IsSurfaceLit Function")
	{
		TVector3 v3PointOnSurface{ 0, 0, 0 };
		TVector3 v3LightSourcePosition{ 1, 1, 1 };
		TTriangle3 t3Surface{ { 1, -1, 0 }, { 0, 2, 0 }, { -1, -1, 0 } };
		REQUIRE(IsSurfaceLit(v3PointOnSurface, v3LightSourcePosition, t3Surface));
		REQUIRE_FALSE(IsSurfaceLit(v3PointOnSurface, { 1, 1, -1 }, t3Surface));
	}

	SECTION("Test IsInFieldOfView Function")
	{
		TVector2 v2CameraDirection{ -1, -1 };
		TVector2 v2CameraPosition{ 2, 2 };
		TVector2 v2ObjectPosition{ 1, 1 };
		REQUIRE(IsInFieldOfView(v2CameraPosition, v2CameraDirection, 3.14, v2ObjectPosition));
	}

	SECTION("Test RotateTriangleAroundPoint (2D)")
	{
		TTriangle2 t2TriToRotate{ { 1, 0 }, { 2, 1 }, { 3, 0 } };
		float fRotAngle = M_PI;
		TVector2 v2RotPoint{ 1, 0 };
		TTriangle2 t2RotatedTri;
		RotateTriangleAroundPoint(t2TriToRotate, fRotAngle, v2RotPoint, t2RotatedTri);
		REQUIRE(Equals(t2RotatedTri.m_v2p1, { 1, 0 }));
		REQUIRE(Equals(t2RotatedTri.m_v2p2, { 0, -1 }));
		REQUIRE(Equals(t2RotatedTri.m_v2p3, { -1, 0 }));
	}
}