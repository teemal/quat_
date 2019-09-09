#include "/home/osboxes/Desktop/Unity/src/unity.h"
#include "linmath.h"
#include <stdio.h>

void test_vec3_cross_prod(void){
	int i;
	vec3 a = {1, 2, 3};
	vec3 b = {7, 8, 9};
	vec3 r = {0, 0, 0};
	vec3 expected = {-6.0, 12.0, -6.0};
	vec3_mul_cross(r, a, b);
	TEST_ASSERT_EQUAL_DOUBLE(expected[0], r[1]);
	TEST_ASSERT_EQUAL_INT(2, 4);
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(test_vec3_cross_prod);
	return UNITY_END();
}