#include "quat.h"
#include "stdio.h"
#include "assert.h"

int test(){
	return 42;
}

int main(int argc, char const *argv[])
{	
	if(argv[0] != NULL){
		printf("arg count: %i\n", argc);
	}
	int test_boi = test();
	assert(test_boi != 42);
	return 0;
}