#include "linmath.h"
#include <math.h>
#include <stdio.h>

float absoluteValFloat(float input){
	float output;
	output = fabsf(input);
	return output;
}

void returnToLevel(quat quaternion, vec3 inputVec){
	int j;
	for(j = 480; j > 0; j--){
		quat_rotate(quaternion, M_PI/j, inputVec);
		printf("NEW: \n");
		printf("%f\n", quaternion[0]);
		printf("%f\n", quaternion[1]);
		printf("%f\n", quaternion[2]);
		printf("%f\n", quaternion[3]);
	}
}

void returnToLevelData1(quat quaternion, vec3 inputVec, FILE *fp){
	int j;
	for(j = 480; j > 0; j--){
		quat_rotate(quaternion, M_PI/j, inputVec);
		fprintf(fp, "%.5g\n", quaternion[2]);
	}
}

void returnToLevelData2(quat quaternion, vec3 inputVec, FILE *fp){
	int j;
	for(j = 480; j > 0; j--){
		quat_rotate(quaternion, M_PI/j, inputVec);
		fprintf(fp, "%.5g\n", quaternion[3]);
	}
}

void SLERPBoi(quat ret, quat start, quat finish, float NTimes){
 	//pulled this almost straight from wikipedia
	//idk this shit is black magic
	quat temp1;
	quat temp2;
	quat temp3;
	quat temp4;
	quat temp5;
	const float DOT_THRESHOLD = 0.9995;
	float dot = quat_inner_product(start, finish);
	// if(dot < 0.0f){
	// 	quat_conj(temp1, finish);
	// 	dot = -dot;
	// }
	// if(dot > DOT_THRESHOLD){

	// }
	float theta_0 = acosf(dot);
	float theta = theta_0 * NTimes;
	float sin_theta = sinf(theta);
	float sin_theta_0 = sinf(theta_0);

	float s0 = cosf(theta) - dot * sin_theta / sin_theta_0;
	float s1 = sin_theta / sin_theta_0;

	quat_scale(temp4, start, s0);
	quat_scale(temp5, finish, s1);
	quat_add(ret, temp4, temp5);
}


int main(void)
{	
	//file opening just for testing
	// FILE *fp1 = fopen("quat_data1.txt", "ab+");
	// FILE *fp2 = fopen("quat_data2.txt", "ab+");
	int i, j;
	quat levelQuat = {0,0,1,0};
	quat levelQuat2 = {0,0,1,0};
	quat ident = {0,0,0,0};
	quat ret = {0,0,0,0};
	quat_identity(ident);
	vec3 offsetVec = {.66, -.34, .54};
	vec3 zVec = {0,0,1};

	printf("Level quaterion with z == 1:\n");
	for(i = 0; i < 4; i++){
		printf("%f\n", levelQuat[i]);
	}
	quat_rotate(levelQuat, (2*M_PI)/2, offsetVec);
	printf("\noriginal quaterion rotated by some 3d vec to:\n");
	for(i = 0; i < 4; i++){
		printf("%f\n", levelQuat[i]);
	}
	printf("\nRotate original quaternion back to level:\n");
	// returnToLevel(levelQuat, zVec);

	// returnToLevelData1(levelQuat, zVec, fp1);
	// returnToLevelData2(levelQuat, zVec, fp2);
	// fclose(fp1);
	// fclose(fp2);
	SLERPBoi(ret, levelQuat, levelQuat2, 480);
	for(i = 0; i < 480; i++){
		SLERPBoi(ret, levelQuat, levelQuat2, 480);
	}
	for(i = 0; i < 4; i++){
		printf("%f\n", ret[i]);
	}
	return 0;
}
