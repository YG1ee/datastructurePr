// MIN heap
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

typedef struct { // 힙에 대한 1차원 배열과 힙 원소의 갯수를 구조체로 묶어서 선언
	int heap[MAX_ELEMENT];
	int heapSize;
} heapType;

heapType *createHeap() {
	heapType *h = (heapType*)malloc(sizeof(heapType));
	h->heapSize = 0;
	return h;
}

void insertHeap(heapType *h, int item) { // 힙에 item을 삽입하는 연산
	if (h->heapSize + 1 > MAX_ELEMENT) {
		return;
	}
	int i; // 새로 삽입하는 item의 위치
	h->heapSize += 1;
	i = h->heapSize;
	// 새로 삽입하는 item과 부모 노드 비교
	// 여기서의 부등호에 따라 MAX heap과 MIN heap이 결정됨
	while ((i != 1) && (item < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int deleteHeap(heapType *h) { // 힙의 루트를 삭제하여 반환하는 연산
	if (!(h->heapSize)) {
		printf("\n힙이 비었습니다!\n");
		return NULL;
	}
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heapSize];
	h->heapSize -= 1;
	parent = 1;
	child = 2;
	while (child <= h->heapSize) {
		if ((h->heap[child]) > h->heap[child + 1])
			child++;
		if (temp <= h->heap[child])
			break;
		else { // temp > h->heap[child]
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
	for (i = 1; i <= h->heapSize; i++)
		printf("[%d]_", h->heap[i]);
}

int main() {
	int i, /*j, m,*/ n, item;
	heapType *heap = createHeap();
	/*srand(time(NULL));
	for (j = 0; j < 10; j++) {

		m = rand() % 10 + 1;
		insertHeap(heap, m);
	}*/
	insertHeap(heap, 2);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 4);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 2);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 4);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 9);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 8);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 8);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 10);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 7);
	printHeap(heap);
	printf("\n");
	insertHeap(heap, 9);
	printHeap(heap);
	printf("\n");

	n = heap->heapSize;
	for (i = 0; i < n; i++) {
		item = deleteHeap(heap);
		if (i < n)
			printf("\n delete: [%d] ", item);
	}

	system("pause");

    return 0;
}