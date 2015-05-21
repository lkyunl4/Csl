
#include "_malloc.h"

int initialized = 0;

void set_used(void* ptr){
	*(int *)ptr = 1;
}

void set_unused(void* ptr){
	*(int *)ptr = 0;
}

void set_block_size(void * ptr, size_t size){
	*(int *) (ptr + sizeof(int)) = size;
}

void set_next_block(void *ptr, size_t ex_size, size_t size){
	void* next = NEXT_BLOCK(ptr);
	set_unused(next);
	set_block_size(next, ex_size - size);
}

void* allocate_block(void * ptr, size_t size){
	size_t ex_size = BLOCK_SIZE(ptr);
	set_used(ptr);
	set_block_size(ptr, size);
	set_next_block(ptr, ex_size, size);

	return ptr + sizeof(header);
}

void mem_initialize(){
	void* ptr = HEAP_START;
	void* end = HEAP_END;
	set_unused(ptr);
	set_block_size(ptr,(end - ptr) + 1);
	initialized = 1;
}

void* _malloc(size_t size){
	if(!initialized)
		mem_initialize();

	void* cur = HEAP_START;
	void* end = HEAP_END;
	size += sizeof(header);

	do {
		if(IS_USED(cur) || BLOCK_SIZE(cur) < size)
			continue;

		return allocate_block(cur, size);

	} while(NEXT_BLOCK(cur) >= end);

	/* TODO:파편화 확인 및 재배열 코드 추가 */

	return 0;
}

