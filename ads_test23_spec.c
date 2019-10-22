#include <stdint.h>
#include <assert.h>
#include "heap.h"
#include<stdio.h>
void test_sort( int32_t data[], uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx <= len; ++idx) {
		printf("%d,",data[idx]);	
	}
	printf("\n");
}
void print_heap(int32_t data[],uint32_t size, int32_t ac_no[], int32_t status[])
{
	printf("The flight list is:\n");
	for(int i=1;i<=size;++i){
		printf("\nAircraft number:%d",ac_no[i]);
		printf("\nTime:%d",data[i]);
		if(status[i]== 0){
			printf("\nStatus:Landing");
		}
		else{
			printf("\nStatus:Take off");
		}
	}
}

void test_heap()
{
	int32_t data[] = { 0, 9, 1540, 7, 1900, 1870, 1560, 1930, 1610, 1700, 1730};
	int32_t status[] = {LANDING, TAKE_OFF, LANDING, LANDING, LANDING, LANDING, TAKE_OFF, TAKE_OFF, TAKE_OFF, LANDING, TAKE_OFF };
	int32_t ac_no[] = {0,1,2,3,4,5,6,7,8,9,10,11};
	Heap heap = heap_new(data, 10, status,ac_no);	
	//heap_insert(&heap, 47, LANDING);
	heap_test(&heap);
	//assert(heap_get_max(&heap) == 93);
	//assert(heap_extract_max(&heap) == 93);
	heap_test(&heap);
	assert(heap_size(&heap) == 10);

	heap_sort(&heap);
	//test_sort(heap.status, 10);
	print_heap(heap.data,10,heap.ac_no, heap.status);

}

int main()
{
	test_heap();
	return 0;
}