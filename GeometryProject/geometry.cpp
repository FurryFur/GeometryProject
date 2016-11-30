#include <math.h>
#include <algorithm>
#include "geometry.h"
#include "math.h"

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

bool Equals(const TVector3& _krA, const TVector3& _krB)
{
	return AlmostEqual(_krA.m_fX, _krB.m_fX) && 
	       AlmostEqual(_krA.m_fY, _krB.m_fY) && 
	       AlmostEqual(_krA.m_fZ, _krB.m_fZ);
}

TVector3& Add(const TVector3& _krA,
              const TVector3& _krB,
              TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX + _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY + _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ + _krB.m_fZ;
	return _rResultant;
}

TVector3& Subtract(const TVector3& _krA,
                   const TVector3& _krB,
                   TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX - _krB.m_fX;
	_rResultant.m_fY = _krA.m_fY - _krB.m_fY;
	_rResultant.m_fZ = _krA.m_fZ - _krB.m_fZ;
	return _rResultant;
}

TVector3& ScaleVector(const TVector3& _krA,
	const float _kfScalar,
	TVector3& _rResultant)
{
	_rResultant.m_fX = _krA.m_fX * _kfScalar;
	_rResultant.m_fY = _krA.m_fY * _kfScalar;
	_rResultant.m_fZ = _krA.m_fZ * _kfScalar;
	return _rResultant;
}

float Magnitude(const TVector3& _krA)
{
	return sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2));
}

float DotProduct(const TVector3& _krA, const TVector3& _krB)
{
	return ((_krA.m_fX * _krB.m_fX) + (_krA.m_fY * _krB.m_fY) + (_krA.m_fZ + _krB.m_fZ));
}

TVector3& CrossProduct(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant)
{

}

TVector3& Normalise(const TVector3& _krA, TVector3& _rResultant)
{

}

TVector3& Projection(const TVector3& _krA,
	const TVector3& _krB,
	TVector3& _rResultant)
{

}

float ComputeAngleBetween(const TVector2& _krA,
	const TVector2& _krB)
{

}

float ComputeAngleBetween(const TVector3& _krA,
	const TVector3& _krB)
{

}

float ComputeDistancePointToLine(const T3DLine& _krLine,
	const TVector3& _krPoint)
{

}

float ComputeDistancePointToPlane(const TPlane& _krPlane,
	const TVector3& _krPoint)
{

}

//Distance between point and center of the spheres
float ComputeDistancePointToSphere(const TSphere& _krSphere,
	const TVector3& _krPoint)
{

}

//Distance between center of the circles
float ComputeDistanceCircleToCircle(const TCircle& _krCircle1,
	const TCircle& _krCircle2)
{

}

//Distance between center of the circle and triangle
float ComputeDistanceCircleToTriangle(const TCircle& _krCircle,
	const TTriangle2& _krTriangle)
{

}

EIntersections ComputeLineSphereIntersection(const T3DLine& _krLine,
	const TSphere& _krSphere,
	TVector3& _rv3IntersectionPoint1,
	TVector3& _rv3IntersectionPoint2)
{

}

bool IsLinePlaneIntersection(const T3DLine& _krLine,
	const TPlane& _krPlane,
	TVector3& _rv3IntersectionPoint)
{

}

bool IsIntersection(const T3DLine& _krLine1,
	const T3DLine& _krLine2)
{

}

TVector3& ComputeIntersectionBetweenLines(const T3DLine& _krLine1,
	const T3DLine& _krLine2,
	TVector3& _rIntersectionPoint)
{

}

bool IsInFieldOfView(const TVector2& _krCameraPosition,
	const TVector2& _krCameraDirection,
	const float _kfFieldOfViewInRadians,
	const TVector2& _krObjectPosition)
{

}

TVector3& FindTriangleNormal(const TTriangle3& _krTriangle,
	TVector3& _rNormal)
{

}

bool IsSurfaceLit(const TVector3& _krPointOnSurface,
	const TVector3& _krLightSourcePosition,
	const TTriangle3& _krSurface)
{

}

TTriangle2& RotateTriangleAroundPoint(const TTriangle2& _krTriangle,
	const float _kfRotAngleInRadians,
	const TVector2& _krRotAroundPoint,
	TTriangle2& _rRotatedTriangle)
{

}