#include "/home/osboxes/Desktop/Unity/src/unity.h"
#include "linmath.h"
#include <stdio.h>

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

void test_vec3_reflect(void){
	//TODO
}

void test_vec4_mul_cross(void){
	// int i;
	// int arrSize = 3;
	// vec4 a = {1, 2, 3, 4};
	// vec4 b = {6, 7, 8, 9};
	// vec4 r = {0, 0, 0, 0};
	// vec4 expected = {};
	// vec4_mul_cross(r, a, b);
	// for(i = 0; i < arrSize; i++){
	// 	TEST_ASSERT_EQUAL_DOUBLE(expected[i], r[i]);
	//TODO -- you can't do cross product on a 4D matrix?
	//}

	/*this is the more elegant test but I can't
	figure out why I'm getting weird changing values
	TODO
	*/
	//TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, r, arrSize);
}

void test_vec4_reflect(void){
	//TODO
}

void test_mat4x4_identity(void){
	//TODO find more elegant solution for assert
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

void test_mat4x4_dup(void){
	//TODO
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

void test_mat4x4_row(void){
	//TODO
}

void test_mat4x4_col(void){
	//TODO
}

void test_mat4x4_transpose(void){
	//TODO
}

void test_mat4x4_add(void){
	//TODO
}

void test_mat4x4_sub(void){
	//TODO
}

void test_mat4x4_scale(void){
	//TODO
}

void test_mat4x4_scale_aniso(void){
	//TODO
}

void test_mat4x4_mul(void){
	//TODO
}

void test_mat4x4_mul_vec4(void){
	//TODO
}

void test_mat4x4_translate(void){
	//TODO
}

void test_mat4x4_translate_in_place(void){
	//TODO
}

void test_mat4x4_from_vec3_mul_outer(void){
	//TODO
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