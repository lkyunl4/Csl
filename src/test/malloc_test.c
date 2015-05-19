/*
 * malloc_test.c
 *
 *  Created on: May 19, 2015
 *      Author: kyun
 */


#include"function_test.h"
#include"../malloc/_malloc.h"

void malloc_test(){
	printf("start malloc test");
	int* a = (int*)_malloc(sizeof(int) * 4);

	printf(" <<<success\n");
}
