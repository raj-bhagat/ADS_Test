#ifndef _INCLUDED_HEAP_
#define _INCLUDED_HEAP_

#include <stdint.h>
#define HEAP_MAX_SIZE 32
#define LANDING 0
#define TAKE_OFF 1

typedef struct _heap_ Heap;
struct  _heap_
{
	uint32_t	size;
	int32_t		data[HEAP_MAX_SIZE]	;
	int32_t		status[HEAP_MAX_SIZE];
	int32_t		ac_no[HEAP_MAX_SIZE];
};

Heap 		heap_new(int32_t data[], uint32_t len, int32_t status[],int32_t ac_no[]);
Heap*		heap_sort(Heap *heap);
//Heap*		heap_insert(Heap *heap, int32_t key, uint32_t status);
Heap*		heap_test(Heap *heap);
int32_t		heap_get_min(Heap *heap);
int32_t		heap_extract_min(Heap *heap);
uint32_t	heap_size(Heap *heap);
//void		print_heap(int32_t data,uint32_t size, int32_t ac_no, int32_t status);

#endif