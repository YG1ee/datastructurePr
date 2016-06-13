// MIN heap
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ELEMENT 100

typedef struct { // ���� ���� 1���� �迭�� �� ������ ������ ����ü�� ��� ����
	int heap[MAX_ELEMENT];
	int heapSize;
} heapType;

heapType *createHeap() {
	heapType *h = (heapType*)malloc(sizeof(heapType));
	h->heapSize = 0;
	return h;
}

void insertHeap(heapType *h, int item) { // ���� item�� �����ϴ� ����
	if (h->heapSize + 1 > MAX_ELEMENT) {
		return;
	}
	int i; // ���� �����ϴ� item�� ��ġ
	h->heapSize += 1;
	i = h->heapSize;
	// ���� �����ϴ� item�� �θ� ��� ��
	// ���⼭�� �ε�ȣ�� ���� MAX heap�� MIN heap�� ������
	while ((i != 1) && (item < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int deleteHeap(heapType *h) { // ���� ��Ʈ�� �����Ͽ� ��ȯ�ϴ� ����
	if (!(h->heapSize)) {
		printf("\n���� ������ϴ�!\n");
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

void printHeap(heapType *h) { // 1���� �迭 ���� ������ ����ϴ� ����
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