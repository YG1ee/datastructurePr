// heap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

typedef struct { // 힙에 대한 1차원 배열과 힙 원소의 갯수를 구조체로 묶어서 선언
	int heap[MAX_ELEMENT];
	int heap_size;
} heapType;

heapType *createHeap() {
	heapType *h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

	void insertHeap(heapType *h, int item) { // 힙에 item을 삽입하는 연산
	int i;
	h->heap_size += 1;
	i = h->heap_size;
	while ((i != 1) && (item < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int deleteHeap(heapType *h) { // 힙의 루트를 삭제하여 반환하는 연산
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((h->heap[child]) > h->heap[child + 1])
			child++;
		if (temp <= h->heap[child])
			break;
		else { // temp < h->heap[child]
			h->heap[parent] = h->heap[child];
			parent = child;
			child *= 2;
		}
	}
	h->heap[parent] = temp;
	return item;
}

void printHeap(heapType *h) { // 1차원 배열 힙의 내용을 출력하는 연산
	int i;
	printf(" Heap: ");
	for (i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
}

int main() {
	int i, j, m, n, item;
	heapType *heap = createHeap();
	srand(time(NULL));
	for (j = 0; j < 10; j++) {

		m = rand() % 10 + 1;
		insertHeap(heap, m);
	}

	printHeap(heap);

	n = heap->heap_size;
	for (i = 1; i <= n; i++) {
		item = deleteHeap(heap);
		printf("\n delete: [%d] ", item);
	}

	system("pause");

    return 0;
}