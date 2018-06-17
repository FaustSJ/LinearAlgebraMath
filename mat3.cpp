#include "mat3.h"
#include "vec3.h"
#include <assert.h>
#include <stdio.h>      
///#include <stdlib.h>    <--has abs() that doesnt accept floats
#include <math.h>	///for abs()
#define EPSILON 0.0000000001
#define PI 3.14159


/// Default Constructor.  Initialize to matrix of all 0s.
mat3::mat3(){
	data[0] = vec3();	///row 0
	data[1] = vec3();	///row 1
	data[2] = vec3();	///row 2
}

/// Initializes matrix with each vector representing a row in the matrix
mat3::mat3(const vec3& row1, const vec3& row2, const vec3& row3)
{
	data[0] = row1;
	data[1] = row2;
	data[2] = row3;
}

///----------------------------------------------------------------------
/// Getters
///----------------------------------------------------------------------	
/// Returns the values of the row at the index
vec3 mat3::operator[](unsigned int index) const
{
	assert(index < 3);
	return data[index];
}

/// Returns a reference to the row at the index
vec3& mat3::operator[](unsigned int index)
{
	assert(index < 3);
	return data[index];
}

/// Returns a column of the matrix
vec3 mat3::getColumn(unsigned int index) const
{
	vec3 temp = vec3();
	if (index < 3)
	{
		temp[0] = data[0][index];
		temp[1] = data[1][index];
		temp[2] = data[2][index];
	}
	return temp;
}

/// Prints the matrix to standard output in a nice format
void mat3::print()
{
	data[0].print();
	data[1].print();
	data[2].print();
}

///----------------------------------------------------------------------
/// Matrix Operations
///----------------------------------------------------------------------	
/// Returns the transpose of the matrix (v_ij == v_ji)
mat3 mat3::transpose() const
{
	mat3 temp = mat3();
	temp[0] = vec3(data[0][0], data[1][0], data[2][0]);
	temp[1] = vec3(data[0][1], data[1][1], data[2][1]);
	temp[2] = vec3(data[0][2], data[1][2], data[2][2]);
	return temp;
}

///----------------------------------------------------------------------
/// Static Initializers
///----------------------------------------------------------------------	
/// Creates a 3-D rotation matrix.
/// Takes an angle in degrees and outputs a 3x3 rotation matrix
mat3 mat3::rotation2D(float angle)
{
	mat3 temp = mat3();
	temp[0] = vec3(cos(angle*(PI/180.0)), -sin(angle*(PI/180.0)), 0);
	temp[1] = vec3(sin(angle*(PI/180.0)), cos(angle*(PI/180.0)), 0);
	temp[2] = vec3(0, 0, 1);
	return temp;
}

/// Takes an x and y displacement and outputs a 3x3 translation matrix
mat3 mat3::translation2D(float x, float y)
{
	mat3 temp = mat3();
	temp[0] = vec3(1, 0, x);
	temp[1] = vec3(0, 1, y);
	temp[2] = vec3(0, 0, 1);
	return temp;
}

/// Takes an x and y scale and outputs a 3x3 scale matrix
mat3 mat3::scale2D(float x, float y)
{
	mat3 temp = mat3();
	temp[0] = vec3(x, 0, 0);
	temp[1] = vec3(0, y, 0);
	temp[2] = vec3(0, 0, 1);
	return temp;
}

/// Generates a 3x3 identity matrix
mat3 mat3::identity()
{
	mat3 temp = mat3();
	temp[0] = vec3(1, 0, 0);
	temp[1] = vec3(0, 1, 0);
	temp[2] = vec3(0, 0, 1);
	return temp;
}


///----------------------------------------------------------------------
/// Friend Functions
///----------------------------------------------------------------------
/// Checks if m1 == m2
 bool operator==(const mat3& m1, const mat3& m2)
{
	if (abs(m1[0][0] - m2[0][0]) > EPSILON)
		return false;
	if (abs(m1[0][1] - m2[0][1]) > EPSILON)
		return false;
	if (abs(m1[0][2] - m2[0][2]) > EPSILON)
		return false;
	if (abs(m1[1][0] - m2[1][0]) > EPSILON)
		return false;
	if (abs(m1[1][1] - m2[1][1]) > EPSILON)
		return false;
	if (abs(m1[1][2] - m2[1][2]) > EPSILON)
		return false;
	if (abs(m1[2][0] - m2[2][0]) > EPSILON)
		return false;
	if (abs(m1[2][1] - m2[2][1]) > EPSILON)
		return false;
	if (abs(m1[2][2] - m2[2][2]) > EPSILON)
		return false;

	return true;   ///by default...
}

/// Checks if m1 != m2
bool operator!=(const mat3& m1, const mat3& m2)
{
	if (abs(m1[0][0] - m2[0][0]) > EPSILON)
		return true;
	if (abs(m1[0][1] - m2[0][1]) > EPSILON)
		return true;
	if (abs(m1[0][2] - m2[0][2]) > EPSILON)
		return true;
	if (abs(m1[1][0] - m2[1][0]) > EPSILON)
		return true;
	if (abs(m1[1][1] - m2[1][1]) > EPSILON)
		return true;
	if (abs(m1[1][2] - m2[1][2]) > EPSILON)
		return true;
	if (abs(m1[2][0] - m2[2][0]) > EPSILON)
		return true;
	if (abs(m1[2][1] - m2[2][1]) > EPSILON)
		return true;
	if (abs(m1[2][2] - m2[2][2]) > EPSILON)
		return true;

	return false;   ///by default...
}

/// Matrix addition (m1 + m2)
mat3 operator+ (const mat3& m1, const mat3& m2)
{
	mat3 temp = mat3();
	temp[0] = vec3(m1[0][0] + m2[0][0], m1[0][1] + m2[0][1], m1[0][2] + m2[0][2]);
	temp[1] = vec3(m1[1][0] + m2[1][0], m1[1][1] + m2[1][1], m1[1][2] + m2[1][2]);
	temp[2] = vec3(m1[2][0] + m2[2][0], m1[2][1] + m2[2][1], m1[2][2] + m2[2][2]);
	return temp;
}

/// Matrix subtraction (m1 - m2)
mat3 operator- (const mat3& m1, const mat3& m2)
{
	mat3 temp = mat3();
	temp[0] = vec3(m1[0][0] - m2[0][0], m1[0][1] - m2[0][1], m1[0][2] - m2[0][2]);
	temp[1] = vec3(m1[1][0] - m2[1][0], m1[1][1] - m2[1][1], m1[1][2] - m2[1][2]);
	temp[2] = vec3(m1[2][0] - m2[2][0], m1[2][1] - m2[2][1], m1[2][2] - m2[2][2]);
	return temp;
}

/// Scalar multiplication (m * c)
mat3 operator* (const mat3& m, float c)
{
	mat3 temp = mat3();
	temp[0] = vec3(m[0][0] * c, m[0][1] * c, m[0][2] * c);
	temp[1] = vec3(m[1][0] * c, m[1][1] * c, m[1][2] * c);
	temp[2] = vec3(m[2][0] * c, m[2][1] * c, m[2][2] * c);
	return temp;
}

/// Scalar multiplication (c * m)
mat3 operator* (float c, const mat3& m)
{
	mat3 temp = mat3();
	temp[0] = vec3(m[0][0] * c, m[0][1] * c, m[0][2] * c);
	temp[1] = vec3(m[1][0] * c, m[1][1] * c, m[1][2] * c);
	temp[2] = vec3(m[2][0] * c, m[2][1] * c, m[2][2] * c);
	return temp;
}

/// Scalar division (m / c)
mat3 operator/ (const mat3& m, float c)
{
	mat3 temp = mat3();
	temp[0] = vec3(m[0][0] / c, m[0][1] / c, m[0][2] / c);
	temp[1] = vec3(m[1][0] / c, m[1][1] / c, m[1][2] / c);
	temp[2] = vec3(m[2][0] / c, m[2][1] / c, m[2][2] / c);
	return temp;
}

/// Matrix multiplication (m1 * m2)
mat3 operator* (const mat3& m1, const mat3& m2)
{
	mat3 temp = mat3();
	float r0c0 = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]);
	float r0c1 = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]) + (m1[0][2] * m2[2][1]);
	float r0c2 = (m1[0][0] * m2[0][2]) + (m1[0][1] * m2[1][2]) + (m1[0][2] * m2[2][2]);

	float r1c0 = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]);
	float r1c1 = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]) + (m1[1][2] * m2[2][1]);
	float r1c2 = (m1[1][0] * m2[0][2]) + (m1[1][1] * m2[1][2]) + (m1[1][2] * m2[2][2]);

	float r2c0 = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]);
	float r2c1 = (m1[2][0] * m2[0][1]) + (m1[2][1] * m2[1][1]) + (m1[2][2] * m2[2][1]);
	float r2c2 = (m1[2][0] * m2[0][2]) + (m1[2][1] * m2[1][2]) + (m1[2][2] * m2[2][2]);

	temp[0] = vec3(r0c0, r0c1, r0c2);
	temp[1] = vec3(r1c0, r1c1, r1c2);
	temp[2] = vec3(r2c0, r2c1, r2c2);
	return temp;
}

/// Matrix/vector multiplication (m * v)
/// Assume v is a column vector (ie. a 3x1 matrix)
 vec3 operator* (const mat3& m, const vec3& v)
{
	vec3 temp = vec3();
	temp[0] = (m[0][0] * v[0]) + (m[0][1] * v[1]) + (m[0][2] * v[2]);
	temp[1] = (m[1][0] * v[0]) + (m[1][1] * v[1]) + (m[1][2] * v[2]);
	temp[2] = (m[2][0] * v[0]) + (m[2][1] * v[1]) + (m[2][2] * v[2]);
	return temp;
}

/// Vector/matrix multiplication (v * m)
/// Assume v is a row vector (ie. a 1x3 matrix)
vec3 operator* (const vec3& v, const mat3& m)
{
	vec3 temp = vec3();
	temp[0] = (m[0][0] * v[0]) + (m[1][0] * v[1]) + (m[2][0] * v[2]);
	temp[1] = (m[0][1] * v[0]) + (m[1][1] * v[1]) + (m[2][1] * v[2]);
	temp[2] = (m[0][2] * v[0]) + (m[1][2] * v[1]) + (m[2][2] * v[2]);
	return temp;
}