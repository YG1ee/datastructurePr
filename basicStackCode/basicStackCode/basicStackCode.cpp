// basicStackCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE];
int top = -1;

void push(element item) {
	if (top >= STACK_SIZE - 1) {
		printf("\n\n Stack is FULL ! \n");
		return;
	}
	else
		stack[++top] = item;
}

element pop() {
	if (top == -1) {
		printf("\n\n Stack is empty!\n");
		return 0;
	}
	else
		return stack[top--];
}

void del() {
	if (top == -1) {
		printf("\n\n Stack is empty!");
		exit(1);
	}
	else top--;
}

element peek() {
	if (top == -1) {
		printf("\n\n Stack is empty!\n");
		exit(1);
	}
	else
		return stack[top];
}

void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

int main() {
	int item;
	printStack();

	push(1);
	printStack();

	push(2);
	printStack();

	push(3);
	printStack();

	item = peek();
	printStack();
	printf("peek top => %d", item);

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