/*
 * test1.h
 *
 *  Created on: May 19, 2015
 *      Author: kyun
 */

#ifndef MALLOC_H_
#define MALLOC_H_
#include <stddef.h>

#define HEAP_START (0x10000000); //128K : 0 ~ 0x20000
#define HEAP_END (0x2000000);

#define IS_USED(p) *(int *)p
#define BLOCK_SIZE(p) *(int *)(p + sizeof(int))
#define NEXT_BLOCK(p) p + BLOCK_SIZE(p)

typedef struct Header {
	int used;
	int size;
}header;


void* _malloc(size_t size);

#endif /* TEST1_H_ */

