#include "/home/osboxes/Desktop/Unity/src/unity.h"
#include <stdio.h>

/*
Test file for PWM in to vec3. These test should take in
mock PWM signals for our gyro scopes x, y, and z
and turn that into a vector. It should also handle NULL
value inputs and values outside 0 - 255
*/


/*
duplicates a 4x4 matrix
*/
void test_mat4x4_dup(void){
}

int main(void){
	UNITY_BEGIN();
	RUN_TEST(test_mat4x4_dup);
	return UNITY_END();
}