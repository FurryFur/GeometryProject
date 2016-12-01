#include <math.h>
#include <algorithm>
#include "geometry.h"

// -Lance
bool AlmostEqual(const float _kfA, const float _kfB, const float _fMaxAbsDiff = FLT_EPSILON, const float _fMaxPercentDiff = FLT_EPSILON)
{
	float fDiff = abs(_kfA - _kfB);
	if (fDiff <= _fMaxAbsDiff)
	{
		return true;
	}

	float fPercentDiff = fDiff / std::max<float>(_kfA, _kfB);
	if (fPercentDiff <= _fMaxPercentDiff)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// -Lance
bool Equals(const TVector3& _krA, const TVector3& _krB)
{
	return AlmostEqual(_krA.m_fX, _krB.m_fX) && 
	       AlmostEqual(_krA.m_fY, _krB.m_fY) && 
	       AlmostEqual(_krA.m_fZ, _krB.m_fZ);
}

// -Lance
TVector3& Add(const TVector3& _krA,
              const TVector3& _krB,
              TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;
	return _rResultant;
}

// -Lance
TVector3& Subtract(const TVector3& _krA,
                   const TVector3& _krB,
                   TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
}

// -Seb
TVector3& ScaleVector(const TVector3& _krA,
	const float _kfScalar,
	TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX * _kfScalar;
	_rResultant.m_fY = _krA.m_fY * _kfScalar;
	_rResultant.m_fZ = _krA.m_fZ * _kfScalar;
	return _rResultant;
}

// -Jack
float Magnitude(const TVector3& _krA)
{
	return sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2));
}

// -Jack
float DotProduct(const TVector3& _krA, const TVector3& _krB)
{
	return ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ * _krB.m_fZ));
}

// -Seb
TVector3& CrossProduct(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant)
{
	_rResultant.m_fX = (_krA.m_fY * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fY);
	_rResultant.m_fY = (_krA.m_fX * _krB.m_fZ) - (_krA.m_fZ * _krB.m_fX);
	_rResultant.m_fZ = (_krA.m_fX * _krB.m_fY) - (_krA.m_fY * _krB.m_fX);
	return _rResultant;
}

// -Seb
TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant)
{
	float fMag = Magnitude(_krA);
	_rResultant.m_fX = _krA.m_fX / fMag;
	_rResultant.m_fY = _krA.m_fY / fMag;
	_rResultant.m_fZ = _krA.m_fZ / fMag;
	return _rResultant;
}

// -Jack
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

// -Lance
float ComputeAngleBetween(const TVector2& _krA,
	const TVector2& _krB)
{
	float fADotB = _krA.m_fX * _krB.m_fX + _krA.m_fY * _krB.m_fY;
	float fMagA = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2));
	float fMagB = sqrt(pow(_krB.m_fX, 2) + pow(_krB.m_fY, 2));
	return acos(fADotB / ( fMagA * fMagB));
}

// -Lance
float ComputeAngleBetween(const TVector3& _krA,
	const TVector3& _krB)
{
	float fADotB = DotProduct(_krA, _krB);
	float fMagA = Magnitude(_krA);
	float fMagB = Magnitude(_krB);
	return acos(fADotB / (fMagA * fMagB));
}

// -Jack
float ComputeDistancePointToLine(const T3DLine& _krLine,
	const TVector3& _krPoint)
{
	TVector3 _rResultant;
	TVector3 _rPointtoLine = { (_krPoint.m_fX - _krLine.m_v3q.m_fX), (_krPoint.m_fY - _krLine.m_v3q.m_fY), (_krPoint.m_fZ - _krLine.m_v3q.m_fZ) };
	return Magnitude(CrossProduct(_rPointtoLine, _krLine.m_v3v, _rResultant)) / Magnitude(_krLine.m_v3v);
}

// -Seb
float ComputeDistancePointToPlane(const TPlane& _krPlane,
	const TVector3& _krPoint)
{
	return 0;
}

// -Seb
//Distance between point and center of the spheres
float ComputeDistancePointToSphere(const TSphere& _krSphere,
	const TVector3& _krPoint)
{
	return 0;
}

// -Jack
//Distance between center of the circles
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1,
	const TCircle& _krCircle2)
{
	return sqrt(pow((_krCircle1.m_v2center.m_fX - _krCircle2.m_v2center.m_fX), 2) + pow((_krCircle1.m_v2center.m_fY - _krCircle2.m_v2center.m_fY), 2));
}

// -Lance
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

// -Seb
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

// -Jack
bool IsLinePlaneIntersection(const T3DLine& _krLine,
	const TPlane& _krPlane,
	TVector3& _rv3IntersectionPoint)
{
	return false;
}

// -Jack
bool IsIntersection(const T3DLine& _krLine1,
	const T3DLine& _krLine2)
{
	return false;
}

// -Jack
TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1,
	const T3DLine& _krLine2,
	TVector3& _rIntersectionPoint)
{
	return _rIntersectionPoint;
}

// -Seb
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

// -Lance
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

// -Lance
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

// -Lance
TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle,
	const float _kfRotAngleInRadians,
	const TVector2& _krRotAroundPoint,
	TTriangle2& _rRotatedTriangle)
{
	return _rRotatedTriangle;
}