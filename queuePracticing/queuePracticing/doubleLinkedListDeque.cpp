#include "stdafx.h"
#include <stdlib.h>

typedef char element;
typedef struct DQNode {
	element data;
	struct DQNode *lLink;
	struct DQNode *rLink;
} DQNode;

typedef struct {
	DQNode *front, *rear;
} DQueType;

DQueType *createDQue() {
	DQueType *DQ;
	DQ = (DQueType *)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

int isEmpty(DQueType *DQ) {
	if (DQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else
		return 0;
}

void insertFront(DQueType *DQ, element item) {
	DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->front == NULL) { // ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->lLink = NULL;
		newNode->rLink = NULL;
	}
	else { // ���� ������ �ƴ� ���
		DQ->front->lLink = newNode;
		newNode->lLink = NULL;
		newNode->rLink = DQ->front;
		DQ->front = newNode;
	}
}

void insertRear(DQueType *DQ, element item) {
	DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->rear == NULL) { // ���� ������ ���
		DQ->rear = newNode;
		DQ->front = newNode;
		newNode->lLink = NULL;
		newNode->rLink = NULL;
	}
	else {
		DQ->rear->rLink = newNode;
		newNode->rLink = NULL;
		newNode->lLink = DQ->rear;
		DQ->rear = newNode;
	}
}

element deleteFront(DQueType *DQ) {
	DQNode *old = DQ->front; // ������ front ��� ����
	element item;
	if (isEmpty(DQ))
		return 0;
	else {
		item = old->data;
		if (DQ->front->rLink == NULL) { // ���� ���Ұ� ������ ���
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else { // ���� ���Ұ� �� �̻��� ���
			DQ->front = DQ->front->rLink;
			DQ->front->lLink = NULL;
		}
		free(old);
		return item;
	}
}

element deleteRear(DQueType *DQ) {
	DQNode *old = DQ->rear; // ������ rear ��� ����
	element item;
	if (isEmpty(DQ))
		return 0;
	else {
		item = old->data;
		if (DQ->rear->lLink == NULL) { // ���� ���Ұ� ������ ���
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else { // ���� ���Ұ� �� �̻��� ���
			DQ->rear = DQ->rear->lLink;
			DQ->rear->rLink = NULL;
		}
		free(old);
		return item;
	}
}

int removeFront(DQueType *DQ) {
}