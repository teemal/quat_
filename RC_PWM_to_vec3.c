#include "IMU_to_curr_vec3.h"
#include <stdio.h>

int main(void)
{
	/* code */
	float testArr[3];
	testArr[0] = 45.30;
	testArr[1] = 44.50; 
	testArr[2] = 8.0;
	float * newArr = buildVec3(testArr[0], testArr[1], testArr[2]);
	unitVec3(newArr);
	for (int i = 0; i < 3; ++i)
	{
		printf("%f\n", newArr[i]);
	}
	return 0;
}