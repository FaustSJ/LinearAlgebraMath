#include "vec3.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <math.h>	///for abs()
#define EPSILON 0.0000000001
/// Constructors
///----------------------------------------------------------------------
vec3::vec3()
{
	data[0] = 0;
	data[1] = 0;
	data[2] = 0;
}
vec3::vec3(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

///----------------------------------------------------------------------
/// Getters/Setters
///----------------------------------------------------------------------		
/// Returns the value at index
			//(const means the borrowed value can't be edited.)
float vec3::operator[](unsigned int index) const
{
	assert(index < 3);
	return data[index];
}

/// Returns a reference to the value at index
float& vec3::operator[](unsigned int index)
{
	assert(index < 3);
	return data[index];
}

/// Prints the vector to standard output in a nice format
void vec3::print()
{
	std::cout << "[" << data[0] << ", " << data[1] << ", " << data[2] << "]" <<std::endl;
}

///----------------------------------------------------------------------
/// Vector Operations
///----------------------------------------------------------------------
/// Returns the geometric length of the vector
float vec3::length() const
{
	float length = sqrt((data[0]*data[0]) + (data[1]*data[1]) + (data[2]*data[2]));
	return length;
}

///----------------------------------------------------------------------
/// Friend Functions
///----------------------------------------------------------------------		
/// Checks if v1 == v2
bool operator==(const vec3& v1, const vec3& v2)
{
	if (abs(v1[0] - v2[0]) > EPSILON)
		return false;
	if (abs(v1[1] - v2[1]) > EPSILON)
		return false;
	if (abs(v1[2] - v2[2]) > EPSILON)
		return false;

	return true; ///on default...
}

/// Checks if v1 != v2
bool operator!=(const vec3& v1, const vec3& v2)
{
	if (abs(v1[0] - v2[0]) > EPSILON)
		return true;
	if (abs(v1[1] - v2[1]) > EPSILON)
		return true;
	if (abs(v1[2] - v2[2]) > EPSILON)
		return true;
			
	return false; ///on default...
}

/// Vector Addition (v1 + v2)
vec3 operator+ (const vec3& v1, const vec3& v2)
{
	vec3 temp = vec3();
	temp[0] = v1[0] + v2[0];
	temp[1] = v1[1] + v2[1];
	temp[2] = v1[2] + v2[2];
	return temp;
}

/// Vector Subtraction (v1 - v2)
vec3 operator- (const vec3& v1, const vec3& v2)
{
	vec3 temp = vec3();
	temp[0] = v1[0] - v2[0];
	temp[1] = v1[1] - v2[1];
	temp[2] = v1[2] - v2[2];
	return temp;
}

/// Scalar Multiplication (v * c)
vec3 operator* (const vec3& v, float c)
{
	vec3 temp = vec3();
	temp[0] = v[0] * c;
	temp[1] = v[1] * c;
	temp[2] = v[2] * c;
	return temp;
}

/// Scalar Multiplication (c * v)
vec3 operator* (float c, const vec3& v)
{
	vec3 temp = vec3();
	temp[0] = v[0] * c;
	temp[1] = v[1] * c;
	temp[2] = v[2] * c;
	return temp;
}

/// Scalar Division (v/c)
vec3 operator/ (const vec3& v, float c)
{
	vec3 temp = vec3();
	temp[0] = v[0] / c;
	temp[1] = v[1] / c;
	temp[2] = v[2] / c;
	return temp;
}

/// Dot Product (v1 * v2)
float operator* (const vec3& v1, const vec3& v2)
{
	return ((v1[0]*v2[0]) + (v1[1]*v2[1]) + (v1[2]*v2[2]));
}

/// Cross Product (v1 % v2)
vec3 operator% (const vec3& v1, const vec3& v2)
{
	vec3 temp = vec3();
	temp[0] = v1[1]*v2[2] - v1[2]*v2[1];
	temp[1] = v1[2]*v2[0] - v1[0]*v2[2];
	temp[2] = v1[0]*v2[1] - v1[1]*v2[0];
	return temp;
}
