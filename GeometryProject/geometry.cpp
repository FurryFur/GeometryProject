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
	float fADotB = _krA.m_fX * _krB.m_fX + _krA.m_fY * _krB.m_fY + _krA.m_fZ * _krB.m_fZ;
	float fMagA = sqrt(pow(_krA.m_fX, 2) + pow(_krA.m_fY, 2) + pow(_krA.m_fZ, 2));
	float fMagB = sqrt(pow(_krB.m_fX, 2) + pow(_krB.m_fY, 2) + pow(_krB.m_fZ, 2));
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
	if (DotProduct(_krPlane.m_v3normal, _krLine.m_v3v) == 0)
	{
		return false;
	}
	else{
		float _krPlaneD = DotProduct(_krPlane.m_v3normal, _krPlane.m_v3point);
		float _fTValue = (-(_krPlaneD + _krPlane.m_v3normal.m_fX * _krLine.m_v3q.m_fX + _krPlane.m_v3normal.m_fY * _krLine.m_v3q.m_fY + _krPlane.m_v3normal.m_fZ * _krLine.m_v3q.m_fZ)) / DotProduct(_krPlane.m_v3normal, _krLine.m_v3v);
		_rv3IntersectionPoint.m_fX = _krLine.m_v3q.m_fX + _fTValue * _krLine.m_v3v.m_fX;
		_rv3IntersectionPoint.m_fY = _krLine.m_v3q.m_fY + _fTValue * _krLine.m_v3v.m_fY;
		_rv3IntersectionPoint.m_fZ = _krLine.m_v3q.m_fZ + _fTValue * _krLine.m_v3v.m_fZ;
		if (_fTValue >= 0 && _fTValue <= 1){
			return true;
		}
		else{
			return false;
		}
	}
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