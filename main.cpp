#include "mat3.h"
#include "vec3.h"
#include <iostream>

int main(int argc, char * const argv[]) {
	///Testing the vector methods
		//constructors
	std::cout << "We will start by testing the vertex functions." << std::endl;
	vec3 v1 = vec3();
	v1[0] = 2;
	v1[1] = 3;
	v1[2] = 4;
	vec3 v2 = vec3(5, 7, 8);
	std::cout << "v1: ";
	v1.print();
	std::cout << "v2: ";
	v2.print();
		//length()
	float length = v1.length();
	std::cout << "v1's length is: " << length << ", which should be 5.385" << std::endl;
	length = v2.length();
	std::cout << "v2's length is: " << length << ", which should be 11.747" << std::endl;
		// == and !=
	vec3 v3 = vec3(2, 3, 4);
	std::cout << "v3 is the same as v1." << std::endl;
	bool eqv1v3 = (v1 == v3);
	bool eqv1v2 = (v2 == v1);
	bool neqv1v3 = (v1 != v3);
	bool neqv2v3 = (v2 != v3);
	std::cout << "v1 == v3 (T): "<< eqv1v3 << std::endl;
	std::cout << "v1 == v2 (F): " << eqv1v2 << std::endl;
	std::cout << "v1 != v3 (F): " << neqv1v3 << std::endl;
	std::cout << "v2 != v3 (T): " << neqv2v3 << std::endl;
		// + and -
	vec3 addvec = v1 + v2;
	vec3 addcor = vec3(7, 10, 12);
	vec3 subvec = v2 - v1;
	vec3 subcor = vec3(3, 4, 4);
	std::cout << "v1 + v2 = ";
	addvec.print();
	std::cout << "\twhich should be ";
	addcor.print();
	std::cout << "v2 - v1 = ";
	subvec.print();
	std::cout << "\twhich should be ";
	subcor.print();
		// *c and /c
	vec3 vecC = v1 * 2;
	vec3 Cvec = 2 * v1;
	vec3 corC = vec3(4 ,6, 8);
	vec3 divC = v2 / 2;
	vec3 divcor = vec3(2.5, 3.5, 4);
	std::cout << "v1*2 = ";
	vecC.print();
	std::cout << "\twhich equals 2*v1: ";
	Cvec.print();
	std::cout << "\tand both should equal: ";
	corC.print();
	std::cout << "v2 / 2 = ";
	divC.print();
	std::cout << "which should be: ";
	divcor.print();
		// vec * vec
	float multV = v1*v2;
	std::cout << "v1 * v2 = " << multV << " which should be 63" << std::endl;
		// vec % vec
	vec3 crossV = v1%v2;
	vec3 crossCor = vec3(-4, 4, -1);
	std::cout << "v1 % v2 = ";
	crossV.print();
	std::cout << "which should be: ";
	crossCor.print();
	//Done checking verticies.
	std::cout << "Press enter to proceed with checking the matrix functions." << std::endl;
	system("PAUSE");
	//now we check the matrix functions
	vec3 row11 = vec3(2, 3, 5);
	vec3 row12 = vec3(4, 1, 6);
	vec3 row13 = vec3();
	mat3 m1 = mat3(row11, row12, row13);
	vec3 row21 = vec3(4, 0, 1);
	vec3 row22 = vec3();
	vec3 row23 = vec3(8, 7, 2);
	mat3 m2 = mat3();
	m2[0] = row21;
	m2[1] = row22;
	m2[2] = row23;
	std::cout << "m1 is: " << std::endl;
	m1.print();
	std::cout << "m2 is: " << std::endl;
	m2.print();
		// transpose, rotation, translation, scale, and identity
	std::cout << "now we transpose m1:" << std::endl;
	m1 = m1.transpose();
	m1.print();
	std::cout << "Here is a rotation matrix by 45.5 degrees:" << std::endl;
	mat3 rota = mat3::rotation2D(45.5);
	rota.print();
	std::cout << "Here is a translation matrix up 2 and right 3:" << std::endl;
	mat3 trans = mat3::translation2D(2, 3);
	trans.print();
	std::cout << "Here is a scaling matrix x2 hight and x3 width:" << std::endl;
	mat3 scar = mat3::scale2D(2, 3);
	scar.print();
	std::cout << "Here is an identity matrix:" << std::endl;
	mat3 iden = mat3::identity();
	iden.print();
		// == and !=
	mat3 m3 = mat3(row21, row22, row23);
	std::cout << "m3 is the same as m2." << std::endl;
	bool eqm2m3 = (m2 == m3);
	bool eqm1m2 = (m1 == m2);
	bool neqm2m3 = (m2 != m3);
	bool neqm1m3 = (m1 != m3);
	std::cout << "m2 == m3 (T): " << eqm2m3 << std::endl;
	std::cout << "m1 == m2 (F): " << eqm1m2 << std::endl;
	std::cout << "m2 != m3 (F): " << neqm2m3 << std::endl;
	std::cout << "m1 != m3 (T): " << neqm1m3 << std::endl;
		// + and -
	vec3 addi11 = vec3(6, 4, 1);
	vec3 addi12 = vec3(3, 1, 0);
	vec3 addi13 = vec3(13, 13, 2);
	mat3 addicor = mat3(addi11, addi12, addi13);
	mat3 addi = m1 + m2;
	vec3 sub11 = vec3(2, -4, 1);
	vec3 sub12 = vec3(-3, -1, 0);
	vec3 sub13 = vec3(3, 1, 2);
	mat3 subtcor = mat3(sub11, sub12, sub13);
	mat3 sub = m2 - m1;
	std::cout << "m1 + m2 = " << std::endl;
	addi.print();
	std::cout << "\twhich should be " << std::endl;
	addicor.print();
	std::cout << "m2 - m1 = " << std::endl;
	sub.print();
	std::cout << "\twhich should be " << std::endl;
	subtcor.print();
		// m*c and c*m
	vec3 mult11 = vec3(4, 8, 0);
	vec3 mult12 = vec3(6, 2, 0);
	vec3 mult13 = vec3(10, 12, 0);
	mat3 multcor = mat3(mult11, mult12, mult13);
	mat3 mC = m1 * 2;
	mat3 Cm = 2 * m1;
	vec3 divi11 = vec3(2, 0, 0.5);
	vec3 divi12 = vec3(0, 0, 0);
	vec3 divi13 = vec3(4, 3.5, 1);
	mat3 divicor = mat3(divi11, divi12, divi13);
	mat3 divi = m2 / 2;
	std::cout << "m1*2 = " << std::endl;
	mC.print();
	std::cout << "\twhich equals 2*m1: " << std::endl;
	Cm.print();
	std::cout << "\tand both should equal: " << std::endl;
	multcor.print();
	std::cout << "m2 / 2 = " << std::endl;
	divi.print();
	std::cout << "which should be: " << std::endl;
	divicor.print();
		// m*m
	vec3 mm11 = vec3(8, 0, 2);
	vec3 mm12 = vec3(12, 0, 3);
	vec3 mm13 = vec3(20, 0, 5);
	mat3 mmcor = mat3(mm11, mm12, mm13);
	mat3 mm = m1 * m2;
	std::cout << "m1 * m2 = " << std::endl;
	mm.print();
	std::cout << "\twhich should be " << std::endl;
	mmcor.print();
		//m*v and v*m
	vec3 vecM = vec3(2, 3, 5);
	vec3 vmcor = vec3(38, 41, 0);
	vec3 vm = vecM*m1;
	vec3 mvcor = vec3(16, 9, 28);
	vec3 mv = m1*vecM;
	std::cout << "vector v = ";
	vecM.print();
	std::cout << "v * m1 = ";
	vm.print();
	std::cout << "\twhich should be: ";
	vmcor.print();
	std::cout << "m1 * v = ";
	mv.print();
	std::cout << "\twhich should be: ";
	mvcor.print();
	std::cout << "" << std::endl;
	std::cout << "This concludes our tests." << std::endl;

	system("PAUSE");

}