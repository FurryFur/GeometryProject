#include <math.h>
#include <algorithm>
#include "geometry.h"

// -Lance / Jack, Seb, Shawn
bool AlmostEqual(const float _kfA, const float _kfB, const float _fMaxAbsDiff = std::numeric_limits<float>::epsilon() * 2)
{
	float fDiff = abs(_kfA - _kfB);
	if (fDiff <= _fMaxAbsDiff)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// -Lance / Jack, Seb, Shawn
bool Equals(const TVector3& _krA, const TVector3& _krB)
{
	return AlmostEqual(_krA.m_fX, _krB.m_fX) && 
	       AlmostEqual(_krA.m_fY, _krB.m_fY) && 
	       AlmostEqual(_krA.m_fZ, _krB.m_fZ);
}

bool Equals(const TVector2& _krA, const TVector2& _krB)
{
	return AlmostEqual(_krA.m_fX, _krB.m_fX) &&
           AlmostEqual(_krA.m_fY, _krB.m_fY);
}

// -Lance / Jack, Seb, Shawn
TVector3& Add(const TVector3& _krA,
              const TVector3& _krB,
              TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;
	return _rResultant;
}

// -Lance / Jack, Seb, Shawn
TVector2& Add(const TVector2& _krA,
              const TVector2& _krB,
              TVector2& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	return _rResultant;
}

// -Lance / Jack, Seb, Shawn
TVector3& Subtract(const TVector3& _krA,
                   const TVector3& _krB,
                   TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
}

// -Lance / Jack, Seb, Shawn
TVector2& Subtract(const TVector2& _krA,
	const TVector2& _krB,
	TVector2& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	return _rResultant;
}

// -Seb / Jack, Lance, Shawn
TVector3& ScaleVector(const TVector3& _krA,
	const float _kfScalar,
	TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX * _kfScalar;
	_rResultant.m_fY = _krA.m_fY * _kfScalar;
	_rResultant.m_fZ = _krA.m_fZ * _kfScalar;
	return _rResultant;
}

// -Jack / Lance, Seb, Shawn
float Magnitude(const TVector3& _krA)
{
	return sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2));
}

// -Jack / Lance, Seb, Shawn
float DotProduct(const TVector3& _krA, const TVector3& _krB)
{
	return ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ));
}

// -Seb / Jack, Lance, Shawn
TVector3& CrossProduct(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant)
{
	_rResultant.m_fX = (_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY);
	_rResultant.m_fY = (_krA.m_fZ * _krB.m_fX) - (_krA.m_fX * _krB.m_fZ);
	_rResultant.m_fZ = (_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX);
	return _rResultant;
}

// -Seb / Jack, Lance, Shawn
TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant)
{
	float fMag = Magnitude(_krA);
	_rResultant.m_fX = _krA.m_fX / fMag;
	_rResultant.m_fY = _krA.m_fY / fMag;
	_rResultant.m_fZ = _krA.m_fZ / fMag;
	return _rResultant;
}

// -Jack / Lance, Seb, Shawn
TVector3& Projection(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant)
{
	float fProjMultpr = (DotProduct(_krA, _krB)) / (pow(Magnitude(_krB), 2));
	_rResultant.m_fX = fProjMultpr * _krB.m_fX;
	_rResultant.m_fY = fProjMultpr * _krB.m_fY;
	_rResultant.m_fZ = fProjMultpr * _krB.m_fZ;
	return _rResultant;
}

// -Lance / Jack, Seb, Shawn
float ComputeAngleBetween(const TVector2& _krA,
	const TVector2& _krB)
{
	float fADotB = _krA.m_fX * _krB.m_fX + _krA.m_fY * _krB.m_fY;
	float fMagA = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2));
	float fMagB = sqrt(pow(_krB.m_fX, 2) + pow(_krB.m_fY, 2));
	return acos(fADotB / ( fMagA * fMagB));
}

// -Lance / Jack, Seb, Shawn
float ComputeAngleBetween(const TVector3& _krA,
	const TVector3& _krB)
{
	float fADotB = DotProduct(_krA, _krB);
	float fMagA = Magnitude(_krA);
	float fMagB = Magnitude(_krB);
	return acos(fADotB / (fMagA * fMagB));
}

// -Jack / Lance, Seb, Shawn
float ComputeDistancePointToLine(const T3DLine& _krLine,
	const TVector3& _krPoint)
{
	TVector3 resultant;
	TVector3 pointtoLine = { (_krPoint.m_fX - _krLine.m_v3q.m_fX), (_krPoint.m_fY - _krLine.m_v3q.m_fY), (_krPoint.m_fZ - _krLine.m_v3q.m_fZ) };
	return Magnitude(CrossProduct(pointtoLine, _krLine.m_v3v, resultant)) / Magnitude(_krLine.m_v3v);
}

// -Jack / Lance, Seb, Shawn
float ComputeDistancePointToPlane(const TPlane& _krPlane,
	const TVector3& _krPoint)
{
	T3DLine line{ _krPoint, _krPlane.m_v3normal };
	TVector3 v3IntersectionPoint;
	IsLinePlaneIntersection(line, _krPlane, v3IntersectionPoint);
	TVector3 v3DifVector;
	Subtract(v3IntersectionPoint, _krPoint, v3DifVector);
	return Magnitude(v3DifVector);
}

// -Seb / Jack, Lance, Shawn
//Distance between point and center of the spheres
float ComputeDistancePointToSphere(const TSphere& _krSphere,
	const TVector3& _krPoint)
{
	return sqrt((_krSphere.m_v3center.m_fX - _krPoint.m_fX) * (_krSphere.m_v3center.m_fX - _krPoint.m_fX) + 
		(_krSphere.m_v3center.m_fY - _krPoint.m_fY) * (_krSphere.m_v3center.m_fY - _krPoint.m_fY) + 
		(_krSphere.m_v3center.m_fZ - _krPoint.m_fZ) * (_krSphere.m_v3center.m_fZ - _krPoint.m_fZ));
}

// -Jack / Lance, Seb, Shawn
//Distance between center of the circles
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1,
	const TCircle& _krCircle2)
{
	return sqrt(pow((_krCircle1.m_v2center.m_fX - _krCircle2.m_v2center.m_fX), 2) + pow((_krCircle1.m_v2center.m_fY - _krCircle2.m_v2center.m_fY), 2));
}

// -Lance / Jack, Seb, Shawn
//Distance between center of the circle and triangle
float ComputeDistanceCircleToTriangle(const TCircle& _krCircle,
	const TTriangle2& _krTriangle)
{
	float fTriCentreX = (_krTriangle.m_v2p1.m_fX + _krTriangle.m_v2p2.m_fX + _krTriangle.m_v2p3.m_fX) / 3;
	float fTriCentreY = (_krTriangle.m_v2p1.m_fY + _krTriangle.m_v2p2.m_fY + _krTriangle.m_v2p3.m_fY) / 3;
	float fVDiffX = fTriCentreX - _krCircle.m_v2center.m_fX;
	float fVDiffY = fTriCentreY - _krCircle.m_v2center.m_fY;
	return sqrt(pow(fVDiffX, 2) + pow(fVDiffY, 2));
}

// -Seb / Jack, Lance, Shawn
EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine,
	const TSphere& _krSphere,
	TVector3& _rv3IntersectionPoint1,
	TVector3& _rv3IntersectionPoint2)
{
	float fT1;
	float fT2;
	TVector3 Normalized = Normalise(_krLine.m_v3v, Normalized);
	float fA = (_krLine.m_v3v.m_fX * _krLine.m_v3v.m_fX) + (_krLine.m_v3v.m_fY *_krLine.m_v3v.m_fY) + (_krLine.m_v3v.m_fZ*_krLine.m_v3v.m_fZ);

	float fB = (2 * _krLine.m_v3v.m_fX * _krLine.m_v3q.m_fX) - (2 * _krLine.m_v3v.m_fX * _krSphere.m_v3center.m_fX) +
		(2 * _krLine.m_v3v.m_fY * _krLine.m_v3q.m_fY) - (2 * _krLine.m_v3v.m_fY * _krSphere.m_v3center.m_fY) + 
		(2 * _krLine.m_v3v.m_fZ * _krLine.m_v3q.m_fZ) - (2 * _krLine.m_v3v.m_fZ * _krSphere.m_v3center.m_fZ);

	float fC = (_krLine.m_v3q.m_fX * _krLine.m_v3q.m_fX) + (_krSphere.m_v3center.m_fX * _krSphere.m_v3center.m_fX) - (2 * _krLine.m_v3q.m_fX * _krSphere.m_v3center.m_fX)+
		(_krLine.m_v3q.m_fY * _krLine.m_v3q.m_fY) + (_krSphere.m_v3center.m_fY * _krSphere.m_v3center.m_fY) - (2 * _krLine.m_v3q.m_fY * _krSphere.m_v3center.m_fY)+
		(_krLine.m_v3q.m_fZ * _krLine.m_v3q.m_fZ) + (_krSphere.m_v3center.m_fZ * _krSphere.m_v3center.m_fZ) - (2 * _krLine.m_v3q.m_fZ * _krSphere.m_v3center.m_fZ)
		- (_krSphere.m_fRadius * _krSphere.m_fRadius);

	// If the discriminant is negative
	if ((fB * fB) - (4 * fA * fC) < 0)
	{
		return INTERSECTION_NONE;
	}

	// If there is one intersection (discriminant is 0)
	if (AlmostEqual((fB * fB) - (4 * fA * fC), 0))
	{
		fT1 = -fB / (2 * fA);

		_rv3IntersectionPoint1.m_fX = (_krLine.m_v3v.m_fX * fT1) + _krLine.m_v3q.m_fX;
		_rv3IntersectionPoint1.m_fY = (_krLine.m_v3v.m_fY * fT1) + _krLine.m_v3q.m_fY;
		_rv3IntersectionPoint1.m_fZ = (_krLine.m_v3v.m_fZ * fT1) + _krLine.m_v3q.m_fZ;

		_rv3IntersectionPoint1 = _rv3IntersectionPoint2;

		return INTERSECTION_ONE;
	}

	fT1 = (-fB / (2 * fA)) + sqrt((fB * fB) - ((4 * fA * fC))) / (2 * fA);
	fT2 = (-fB / (2 * fA)) - sqrt((fB * fB) - ((4 * fA * fC))) / (2 * fA);

	_rv3IntersectionPoint1.m_fX = (_krLine.m_v3v.m_fX * fT1) + _krLine.m_v3q.m_fX;
	_rv3IntersectionPoint1.m_fY = (_krLine.m_v3v.m_fY * fT1) + _krLine.m_v3q.m_fY;
	_rv3IntersectionPoint1.m_fZ = (_krLine.m_v3v.m_fZ * fT1) + _krLine.m_v3q.m_fZ;

	_rv3IntersectionPoint2.m_fX = (_krLine.m_v3v.m_fX * fT2) + _krLine.m_v3q.m_fX;
	_rv3IntersectionPoint2.m_fY = (_krLine.m_v3v.m_fY * fT2) + _krLine.m_v3q.m_fY;
	_rv3IntersectionPoint2.m_fZ = (_krLine.m_v3v.m_fZ * fT2) + _krLine.m_v3q.m_fZ;

	return INTERSECTION_TWO;
}

// -Jack -Lance / Seb, Shawn
bool IsLinePlaneIntersection(const T3DLine& _krLine,
	const TPlane& _krPlane,
	TVector3& _rv3IntersectionPoint)
{
	float fDenominator = DotProduct(_krPlane.m_v3normal, _krLine.m_v3v);
	if (AlmostEqual(fDenominator, 0))
	{
		return false;
	}
	else{
		float _fD = -DotProduct(_krPlane.m_v3normal, _krPlane.m_v3point);
		float _fT = -(DotProduct(_krPlane.m_v3normal, _krLine.m_v3q) + _fD) / fDenominator;
		_rv3IntersectionPoint.m_fX = _krLine.m_v3q.m_fX + _fT * _krLine.m_v3v.m_fX;
		_rv3IntersectionPoint.m_fY = _krLine.m_v3q.m_fY + _fT * _krLine.m_v3v.m_fY;
		_rv3IntersectionPoint.m_fZ = _krLine.m_v3q.m_fZ + _fT * _krLine.m_v3v.m_fZ;
		
		return true;
	}
}

// -Lance / Shawn, Jack, Seb
bool IsIntersection(const T3DLine& _krLine1,
                    const T3DLine& _krLine2)
{
	// Can we calculate an intersection
	TVector3 v3L2VCrossL1V;
	CrossProduct(_krLine2.m_v3v, _krLine1.m_v3v, v3L2VCrossL1V);
	if (Equals(v3L2VCrossL1V, { 0, 0, 0 }))
	{
		return false;
	}

	// Do the intersections match for both line equations
	TVector3 v3Intersection1;
	TVector3 v3Intersection2;
	ComputeIntersectionBetweenLines(_krLine1, _krLine2, v3Intersection1);
	ComputeIntersectionBetweenLines(_krLine2, _krLine1, v3Intersection2);

	return Equals(v3Intersection1, v3Intersection2);
}

// -Lance / Shawn, Jack, Seb
TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1,
                                          const T3DLine& _krLine2,
                                          TVector3& _rIntersectionPoint)
{
	TVector3 v3L1QCrossL2V;
	TVector3 v3L2VCrossL2Q;
	TVector3 v3L2VCrossL1V;
	CrossProduct(_krLine1.m_v3q, _krLine2.m_v3v, v3L1QCrossL2V);
	CrossProduct(_krLine2.m_v3v, _krLine2.m_v3q, v3L2VCrossL2Q);
	CrossProduct(_krLine2.m_v3v, _krLine1.m_v3v, v3L2VCrossL1V);

	// Work out 't' using formula with non-zero denominator
	float fT;
	if (!AlmostEqual(v3L2VCrossL1V.m_fX, 0))
	{
		fT = (v3L1QCrossL2V.m_fX + v3L2VCrossL2Q.m_fX) / v3L2VCrossL1V.m_fX;
	}
	else if (!AlmostEqual(v3L2VCrossL1V.m_fY, 0))
	{
		fT = (v3L1QCrossL2V.m_fY + v3L2VCrossL2Q.m_fY) / v3L2VCrossL1V.m_fY;
	}
	else if (!AlmostEqual(v3L2VCrossL1V.m_fZ, 0))
	{
		fT = (v3L1QCrossL2V.m_fZ + v3L2VCrossL2Q.m_fZ) / v3L2VCrossL1V.m_fZ;
	}
	else
	{
		return _rIntersectionPoint;
	}

	_rIntersectionPoint.m_fX = _krLine1.m_v3q.m_fX + fT * _krLine1.m_v3v.m_fX;
	_rIntersectionPoint.m_fY = _krLine1.m_v3q.m_fY + fT * _krLine1.m_v3v.m_fY;
	_rIntersectionPoint.m_fZ = _krLine1.m_v3q.m_fZ + fT * _krLine1.m_v3v.m_fZ;

	return _rIntersectionPoint;
}

// -Seb / Jack, Lance, Shawn
bool IsInFieldOfView(const TVector2& _krCameraPosition,
	const TVector2& _krCameraDirection,
	const float _kfFieldOfViewInRadians,
	const TVector2& _krObjectPosition)
{
	float fObjectThetaInRadians = atan2((_krObjectPosition.m_fY - _krCameraPosition.m_fY), (_krObjectPosition.m_fX - _krCameraPosition.m_fX));
	float fCameraDirectionInRadians = atan2(_krCameraDirection.m_fY, _krCameraDirection.m_fX);

	if (fObjectThetaInRadians >= (fCameraDirectionInRadians + _kfFieldOfViewInRadians / 2))
	{
		return false;
	}
	else if (fObjectThetaInRadians <= fCameraDirectionInRadians - (_kfFieldOfViewInRadians / 2))
	{
		return false;
	}

	return true;
}

// -Lance / Jack, Seb, Shawn
TVector3& FindTriangleNormal(const TTriangle3& _krTriangle,
	TVector3& _rNormal)
{
	// Get surface normal vector with Counter Clockwise Winding
	TVector3 v3TriSide1;
	TVector3 v3TriSide2;
	Subtract(_krTriangle.m_v3p2, _krTriangle.m_v3p1, v3TriSide1);
	Subtract(_krTriangle.m_v3p3, _krTriangle.m_v3p1, v3TriSide2);
	return CrossProduct(v3TriSide1, v3TriSide2, _rNormal);
}

// -Lance / Jack, Seb, Shawn
bool IsSurfaceLit(const TVector3& _krPointOnSurface,
	const TVector3& _krLightSourcePosition,
	const TTriangle3& _krSurface)
{
	// Get vector to light source
	TVector3 v3VecToLight;
	Subtract(_krLightSourcePosition, _krPointOnSurface, v3VecToLight);
	
	// Get surface normal vector (Counter Clockwise Winding)
	TVector3 v3SurNormal;
	FindTriangleNormal(_krSurface, v3SurNormal);

	return DotProduct(v3VecToLight, v3SurNormal) > 0;
}

// -Lance / Jack, Seb, Shawn
TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle,
	const float _kfRotAngleInRadians,
	const TVector2& _krRotAroundPoint,
	TTriangle2& _rRotatedTriangle)
{
	// Translate triange so that the rotation point is at origin
	Subtract(_krTriangle.m_v2p1, _krRotAroundPoint, _rRotatedTriangle.m_v2p1);
	Subtract(_krTriangle.m_v2p2, _krRotAroundPoint, _rRotatedTriangle.m_v2p2);
	Subtract(_krTriangle.m_v2p3, _krRotAroundPoint, _rRotatedTriangle.m_v2p3);

	// Rotate coordinate system
	TVector2 v2I{ 1, 0 };
	TVector2 v2J{ 0, 1 };
	TVector2 v2IPrime{ v2I.m_fX * cos(_kfRotAngleInRadians), v2I.m_fX * sin(_kfRotAngleInRadians) };
	TVector2 v2JPrime{ -v2J.m_fY * sin(_kfRotAngleInRadians), v2J.m_fY * cos(_kfRotAngleInRadians) };

	// Place triangle points in new coordinate system
	_rRotatedTriangle.m_v2p1.m_fX = _rRotatedTriangle.m_v2p1.m_fX * v2IPrime.m_fX + _rRotatedTriangle.m_v2p1.m_fY * v2JPrime.m_fX;
	_rRotatedTriangle.m_v2p1.m_fY = _rRotatedTriangle.m_v2p1.m_fX * v2IPrime.m_fY + _rRotatedTriangle.m_v2p1.m_fY * v2JPrime.m_fY;
	_rRotatedTriangle.m_v2p2.m_fX = _rRotatedTriangle.m_v2p2.m_fX * v2IPrime.m_fX + _rRotatedTriangle.m_v2p2.m_fY * v2JPrime.m_fX;
	_rRotatedTriangle.m_v2p2.m_fY = _rRotatedTriangle.m_v2p2.m_fX * v2IPrime.m_fY + _rRotatedTriangle.m_v2p2.m_fY * v2JPrime.m_fY;
	_rRotatedTriangle.m_v2p3.m_fX = _rRotatedTriangle.m_v2p3.m_fX * v2IPrime.m_fX + _rRotatedTriangle.m_v2p3.m_fY * v2JPrime.m_fX;
	_rRotatedTriangle.m_v2p3.m_fY = _rRotatedTriangle.m_v2p3.m_fX * v2IPrime.m_fY + _rRotatedTriangle.m_v2p3.m_fY * v2JPrime.m_fY;

	// Translate triangle such that the rotation point is restored to its original position
	Add(_rRotatedTriangle.m_v2p1, _krRotAroundPoint, _rRotatedTriangle.m_v2p1);
	Add(_rRotatedTriangle.m_v2p2, _krRotAroundPoint, _rRotatedTriangle.m_v2p2);
	Add(_rRotatedTriangle.m_v2p3, _krRotAroundPoint, _rRotatedTriangle.m_v2p3);

	return _rRotatedTriangle;
}