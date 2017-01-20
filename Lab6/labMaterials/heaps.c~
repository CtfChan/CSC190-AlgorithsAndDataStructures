#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

struct Heap * initMinHeap()
{
	struct Heap *h = (struct Heap *)malloc(sizeof(struct Heap));
	h->count = 0;
	return h;
}

void insertMinHeap(struct Heap * h, struct Data d)
{	

	int cIndex = ++ (h->count); 
	int pIndex = cIndex/2;
	while (pIndex > 0) {

		if (h->heapArray[pIndex].data.data > d.data) {
			h->heapArray[cIndex] = h->heapArray[pIndex];
			cIndex = pIndex;
			pIndex = cIndex/2;
		}			
		else {
			h->heapArray[cIndex].data = d;
			return;	
		}
	}
	h->heapArray[cIndex].data = d;

}

struct Data removeMinHeap(struct Heap * h)
{
	struct Data dat = h->heapArray[1].data;
	h->heapArray[1] = h->heapArray[h->count];
	h->count --;	

	int pIndex = 1;
	int cIndex = pIndex * 2;
	struct Data temp;	

	while (cIndex <= h->count) {
		if (cIndex < h->count) {
			if (h->heapArray[cIndex].data.data > h->heapArray[cIndex+1].data.data) {
				cIndex ++;
			}
		}
		if (h->heapArray[pIndex].data.data > h->heapArray[cIndex].data.data) {
			temp.data = h->heapArray[pIndex].data.data;
			h->heapArray[pIndex] = h->heapArray[cIndex];
			h->heapArray[cIndex].data.data = temp.data;
		}
		pIndex = cIndex;
		cIndex = pIndex * 2;
	}
	
	
	return dat;

}

void freeMinHeap(struct Heap * h)
{
	free(h);
}







