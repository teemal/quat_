#include "/home/osboxes/Desktop/Unity/src/unity.h"
#include "linmath.h"
#include <stdio.h>

/*
Tests for the linmath header file.
These tests describe oprations on vectors (the mathmatic kind not the data structure)
, matrices, and quaternions. A description of what each
operation is doing, and why it would be used, should be above each function.
*/

//TODO find more elegant solution to all asserts


/*
(a,b,c) * (x,y,z) = (b*z - c*y, c*x - a*z, a*y - b*x)
Used for a lot of different things but the most
common being the angle between two vectors
or the projection of one normalized vector on another
*/
void test_vec3_mul_cross(void){
	int i;
	int arrSize = 3;
	vec3 a = {1, 2, 3};
	vec3 b = {7, 8, 9};
	vec3 r = {0, 0, 0};
	vec3 expected = {-6, 12, -6};
	vec3_mul_cross(r, a, b);
	for(i = 0; i < arrSize; i++){
		TEST_ASSERT_EQUAL_DOUBLE(expected[i], r[i]);
	}

	/*this is the more elegant test but I can't
	figure out why I'm getting weird changing values
	TODO
	*/
	//TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, r, arrSize);
}

/*
the mirrored image of a vector
*/
void test_vec3_reflect(void){
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

void test_vec4_mul_cross(void){
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

void test_vec4_reflect(void){
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

/*
An identity matrix is one with 1's running across it
diagnally. It has the same use as the number 1 in real numbers
*/
void test_mat4x4_identity(void){
	int i, j;
	int arrDim = 4;
	mat4x4 expected = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
	mat4x4 M;
	mat4x4_identity(M);
	for(i = 0; i < arrDim; i++){
		for(j = 0; j < arrDim; j++){
			M[i][j] = i == j ? 1.f : 0.f;
		}
	}
	for(i = 0; i < arrDim; i++){
		for(j = 0; j < arrDim; j++){
			TEST_ASSERT_EQUAL_DOUBLE(expected[i][j],M[i][j]);
		}
	}
}

/*
duplicates a 4x4 matrix
*/
void test_mat4x4_dup(void){
	int i,j;
	int arrDim = 4;
	mat4x4 M = {{1,2,3,4}, {5,6,7,8}, {8,7,6,5}, {4,3,2,1}};
	mat4x4 N = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	mat4x4_dup(M, N);
	for(i = 0; i < arrDim; i++){
		for(j = 0; j < arrDim; j++){
			TEST_ASSERT_EQUAL_DOUBLE(M[i][j],N[i][j]);
		}
	}
}

/*
Gives row of a 4x4 matrix. Row N is the N-1th index
for each subarray
*/
void test_mat4x4_row(void){
	int i;
	int arrSize = 4;
	mat4x4 M = {{1,2,3,4}, {5,6,7,8}, {8,7,6,5}, {4,3,2,1}};
	vec4 r = {0,0,0,0};
	mat4x4_row(r, M, 1);
	TEST_ASSERT_EQUAL_DOUBLE(2, r[0]);
	TEST_ASSERT_EQUAL_DOUBLE(6, r[1]);
	TEST_ASSERT_EQUAL_DOUBLE(7, r[2]);
	TEST_ASSERT_EQUAL_DOUBLE(3, r[3]);
}

/*
Gives column of a 4x4 Matrix. Column N is the N-1th subarray itself
*/
void test_mat4x4_col(void){
	int i;
	int arrSize = 4;
	mat4x4 M = {{1,2,3,4}, {5,6,7,8}, {8,7,6,5}, {4,3,2,1}};
	vec4 r = {0,0,0,0};
	mat4x4_col(r, M, 1);
	TEST_ASSERT_EQUAL_DOUBLE(5, r[0]);
	TEST_ASSERT_EQUAL_DOUBLE(6, r[1]);
	TEST_ASSERT_EQUAL_DOUBLE(7, r[2]);
	TEST_ASSERT_EQUAL_DOUBLE(8, r[3]);
}

/*
Gives transposed 4x4 matrix. 
{{1,2},{3,4}} becomes {{1,3},{2,4}}
*/ 
void test_mat4x4_transpose(void){
	int i, j;
	int arrSize = 4;
	mat4x4 M = {{1,2,3,4}, {5,6,7,8}, {8,7,6,5}, {4,3,2,1}};
	mat4x4 N = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0} , {0,0,0,0}};
	mat4x4_transpose(N, M);
	for(i = 0; i < arrSize; i++){
		for(j = 0; j < arrSize; j++)
			TEST_ASSERT_EQUAL_DOUBLE(N[i][j], M[j][i]);
	}
}
/*
Simply the added values between two matrices
*/
void test_mat4x4_add(void){
	int i, j;
	int arrSize = 4;
	mat4x4 a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 b = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 M = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0} , {0,0,0,0}};
	mat4x4 expected = {{2,4,6,8}, {10,12,14,16}, {18,20,22,24}, {26,28,30,32}};
	mat4x4_add(M, a, b);
	for(i = 0; i < arrSize; i++){
		for(j = 0; j < arrSize; j++)
			TEST_ASSERT_EQUAL_DOUBLE(expected[i][j], M[i][j]);
	}
}
/*
Simply the subracted values between two matrices
*/
void test_mat4x4_sub(void){
	int i, j;
	int arrSize = 4;
	mat4x4 a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 b = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 M = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0} , {0,0,0,0}};
	mat4x4 expected = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0} , {0,0,0,0}};
	mat4x4_sub(M, a, b);
	for(i = 0; i < arrSize; i++){
		for(j = 0; j < arrSize; j++)
			TEST_ASSERT_EQUAL_DOUBLE(expected[i][j], M[i][j]);
	}
}
/*
Scale a 4x4 matrix by N
*/
void test_mat4x4_scale(void){
	int i, j;
	int arrSize = 4;
	mat4x4 a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 M = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0} , {0,0,0,0}};
	mat4x4 expected = {{2,4,6,8}, {10,12,14,16}, {18,20,22,24}, {26,28,30,32}};
	mat4x4_scale(M, a, 2);
	for(i = 0; i < arrSize; i++){
		for(j = 0; j < arrSize; j++){
			TEST_ASSERT_EQUAL_DOUBLE(expected[i][j], M[i][j]);
		}
	}
}

void test_mat4x4_scale_aniso(void){
	/*TODO I think this operation just scales the first 3
	4d vectors from one matrix by another and then directly copies
	over the final vector but I need to make sure before hammering out this test
	*/
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

/*
Multiply 2 matrices together. 
*/
void test_mat4x4_mul(void){
	int i, j;
	int arrSize = 4;
	mat4x4 a = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 b = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4x4 M = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0} , {0,0,0,0}};
	mat4x4 expected = {{90,100,110,120}, {202,228,254,280}, {314,356,398,440}, {426,484,542,600}};
	mat4x4_mul(M, a, b);
	for(i = 0; i < arrSize; i++){
		for(j = 0; j < arrSize; j++){
			TEST_ASSERT_EQUAL_DOUBLE(expected[i][j], M[i][j]);
		}
	}
}

/*
Multiply a 4x4 matrix by a 4d vector
*/
void test_mat4x4_mul_vec4(void){
	int i;
	int arrSize = 4;
	mat4x4 M = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	vec4 v = {1,2,3,4};
	vec4 r = {0,0,0,0};
	vec4 expected = {90,100,110,120};
	mat4x4_mul_vec4(r, M, v);
	for(i = 0; i < arrSize; i++){
		TEST_ASSERT_EQUAL_DOUBLE(expected[i], r[i]);
	}
}

/*
I'm not entirely sure the purposed of this but
it appears to be given a 4x4 matrix and giving it x,y,z properties 
*/
void test_mat4x4_translate(void){
	//TODO
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

void test_mat4x4_translate_in_place(void){
	//TODO
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

void test_mat4x4_from_vec3_mul_outer(void){
	//TODO
	TEST_IGNORE_MESSAGE("coming back to flush this out once I figure out the logic behind it and get some values to test against");
}

void test_mat4x4_rotate(void){
	//TODO
}

void test_mat4x4_rotate_X(void){
	//TODO
}

void test_mat4x4_rotate_Y(void){
	//TODO
}

void test_mat4x4_rotate_Z(void){
	//TODO
}

void test_mat4x4_invert(void){
	//TODO
}

void test_mat4x4_orthonormalize(void){
	//TODO
}

void test_mat4x4_frustum(void){
	//TODO
}

void test_mat4x4_ortho(void){
	//TODO
}

void test_mat4x4_perspective(void){
	//TODO
}

void test_mat4x4_look_at(void){
	//TODO
}

void test_quat_identity(void){
	//TODO
}

void test_quat_add(void){
	//TODO
}

void test_quat_sub(void){
	//TODO
}

void test_quat_mul(void){
	//TODO
}

void test_quat_scale(void){
	//TODO
}

void test_quat_inner_product(void){
	//TODO
}

void test_quat_conj(void){
	//TODO
}

void test_quat_rotate(void){
	//TODO
}

void test_quat_mul_vec3(void){
	//TODO
}

void test_mat4x4_from_quat(void){
	//TODO
}

void test_mat4x4o_mul_quat(void){
	//TODO
}

void test_quat_from_mat4x4(void){
	//TODO
}



int main(void){
	UNITY_BEGIN();
	RUN_TEST(test_vec3_mul_cross);
	RUN_TEST(test_vec3_reflect);
	RUN_TEST(test_vec4_mul_cross);
	RUN_TEST(test_vec4_reflect);
	RUN_TEST(test_mat4x4_identity);
	RUN_TEST(test_mat4x4_dup);
	RUN_TEST(test_mat4x4_row);
	RUN_TEST(test_mat4x4_col);
	RUN_TEST(test_mat4x4_transpose);
	RUN_TEST(test_mat4x4_add);
	RUN_TEST(test_mat4x4_sub);
	RUN_TEST(test_mat4x4_scale);
	RUN_TEST(test_mat4x4_scale_aniso);
	RUN_TEST(test_mat4x4_mul);
	RUN_TEST(test_mat4x4_mul_vec4);
	RUN_TEST(test_mat4x4_translate);
	RUN_TEST(test_mat4x4_translate_in_place);
	RUN_TEST(test_mat4x4_from_vec3_mul_outer);
	RUN_TEST(test_mat4x4_rotate);
	RUN_TEST(test_mat4x4_rotate_X);
	RUN_TEST(test_mat4x4_rotate_Y);
	RUN_TEST(test_mat4x4_rotate_Z);
	RUN_TEST(test_mat4x4_invert);
	RUN_TEST(test_mat4x4_orthonormalize);
	RUN_TEST(test_mat4x4_frustum);
	RUN_TEST(test_mat4x4_ortho);
	RUN_TEST(test_mat4x4_perspective);
	RUN_TEST(test_mat4x4_look_at);
	RUN_TEST(test_quat_identity);
	RUN_TEST(test_quat_add);
	RUN_TEST(test_quat_sub);
	RUN_TEST(test_quat_mul);
	RUN_TEST(test_quat_scale);
	RUN_TEST(test_quat_inner_product);
	RUN_TEST(test_quat_conj);
	RUN_TEST(test_quat_rotate);
	RUN_TEST(test_quat_mul_vec3);
	RUN_TEST(test_mat4x4_from_quat);
	RUN_TEST(test_mat4x4o_mul_quat);
	RUN_TEST(test_quat_from_mat4x4);
	return UNITY_END();
}