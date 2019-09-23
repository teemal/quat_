#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float * buildVec3(float x, float y, float z){
	float maxVal = 255.0;
	float minVal = 0.0;
	if(x > maxVal || y > maxVal || z > maxVal){
		printf("You shouldn't be seeing this. \
			 Checks against input values should be \
			 happening before entering these functions\n");
	}
	if(x < minVal || y < minVal || z < minVal){
		printf("You shouldn't be seeing this. \
			 Checks against input values should be \
			 happening before entering these functions\n");
	}

	static float vec3[3];
	vec3[0] = x;
	vec3[1] = y;
	vec3[2] = z;

	return vec3;
}

void unitVec3(float *inputArray){
	/*
	convert array to unit array (unit vec3).
	do so by dividing x,y,and z by sqrt(x^2 + y^2 + z^2)
	*/
	float magnitude = sqrtf((inputArray[0] * inputArray[0]) + (inputArray[1] * inputArray[1]) + (inputArray[2] * inputArray[2]));
	inputArray[0] = inputArray[0] / magnitude;
	inputArray[1] = inputArray[1] / magnitude;
	inputArray[2] = inputArray[2] / magnitude;
}

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