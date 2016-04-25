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