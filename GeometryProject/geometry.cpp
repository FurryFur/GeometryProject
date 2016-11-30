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
	return 0;
}

// -Lance
float ComputeAngleBetween(const TVector3& _krA,
	const TVector3& _krB)
{
	return 0;
}

// -Jack
float ComputeDistancePointToLine(const T3DLine& _krLine,
	const TVector3& _krPoint)
{
	return 0;
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
	return 0;
}

// -Lance
//Distance between center of the circle and triangle
float ComputeDistanceCircleToTriangle(const TCircle& _krCircle,
	const TTriangle2& _krTriangle)
{
	return 0;
}

// -Seb
EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine,
	const TSphere& _krSphere,
	TVector3& _rv3IntersectionPoint1,
	TVector3& _rv3IntersectionPoint2)
{
	return INTERSECTION_NONE;
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
	return false;
}

// -Seb
TVector3& FindTriangleNormal(const TTriangle3& _krTriangle,
	TVector3& _rNormal)
{
	return _rNormal;
}

// -Lance
bool IsSurfaceLit(const TVector3& _krPointOnSurface,
	const TVector3& _krLightSourcePosition,
	const TTriangle3& _krSurface)
{
	return false;
}

// -Lance
TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle,
	const float _kfRotAngleInRadians,
	const TVector2& _krRotAroundPoint,
	TTriangle2& _rRotatedTriangle)
{
	return _rRotatedTriangle;
}