#include "stdafx.h"
#include <stdlib.h>
#include <malloc.h>

typedef char element;
typedef struct QNode {
	element data;
	struct QNode *link;
} QNode;

typedef struct {
	QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue() {
	LQueueType *LQ;
	LQ = (LQueueType *)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

int isEmpty(LQueueType *LQ) {
	if (LQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else
		return 0;
}

void enQueue(LQueueType *LQ, element item) {
	QNode *newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear = newNode;
		LQ->rear->link = newNode;
	}
}

element deQueue(LQueueType *LQ) {
	QNode *old = LQ->front;
	element item;
	if (isEmpty(LQ))
		return 0;
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}

int del(LQueueType *LQ) {
	element item;
	QNode *old = LQ->front;
	if (isEmpty(LQ))
		return 0;
	else {
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return 1;
	}
}

element peek(LQueueType *LQ) {
	element item;
	if (isEmpty(LQ))
		return 0;
	else {
		item = LQ->front->data;
		return item;
	}
}

void printLQ(LQueueType *LQ) {
	QNode *temp = LQ->front;
	printf(" Linked Queue: [");
	while (temp) {
		printf("%3c", temp->data);
		temp = temp->link;
	}
	printf(" ] \n");
}