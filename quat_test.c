#include "linmath.h"
#include "stdio.h"
#include "/home/osboxes/Desktop/Unity/src/unity.h"

#include "quat.h"

int main(void)
{	
	int i;

	vec3 a = {1.0,2.0,3.0};
	vec3 b = {7.0,8.0,9.0};
	vec3 r = {0.0,0.0,0.0};
	vec3 expected = {-6.0, 12.0, -6.0};
	vec3_mul_cross(r, a, b);

	TEST_ASSERT_EQUAL_DOUBLE(3.000000, 3.000000);
	return 0;
}
