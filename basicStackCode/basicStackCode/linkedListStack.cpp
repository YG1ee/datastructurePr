#include "stdafx.h"
#include <stdlib.h>

typedef int element;

typedef struct stackNode {
	element data;
	stackNode *link;
}stackNode;

stackNode* top; // 스택의 top 노드를 지정하기 위한 포인터 top 선언

void push(element item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {
		printf("\n\n Stack is empty\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

void del() {
	stackNode* temp;
	if (top == NULL)
		printf("\n\n Stack is empty! \n");
	else {
		temp = top;
		top = top->link;
		free(temp);
	}
}

element peek() {
	if (top == NULL) {
		printf("\n\nStack is empty! \n");
		exit(1);
	}
	else {
		return top->data;
	}
}

void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

int main() {
	element item;
	top = NULL;
	printStack();
	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	item = peek();
	printStack();
	printf("peek top => %d\n", item);

	del();
	printStack();

	item = pop();
	printStack();
	printf("\t pop top => %d", item);

	item = pop();
	printStack();
	printf("\t pop top => %d", item);

	pop();

	system("pause");

	return 0;
}