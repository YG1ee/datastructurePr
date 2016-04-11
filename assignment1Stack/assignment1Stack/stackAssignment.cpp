#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef char element;
element stack[STACK_SIZE];
int top = -1;

void push(element item) {
	if (top >= STACK_SIZE - 1) {
		printf("\n\n Stack is full!\n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (top == -1) {
		printf("\n\n Stack is empty.\n");
		return 0;
	}
	else 
		return stack[top--];
}

void del() {
	if (top == -1) {
		printf("\n\n Err: Stack is empty.\n");
		exit(1);
	}
	else top--;
}

element peek() {
	if (top == -1) {
		printf("\n\n Err: Stack is empty.\n");
		exit(1);
	}
	else
		return stack[top];
}

void printStack() {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%c ", stack[i]);
	printf("] ");
}

int main() {
	int i, j;
	char item[26];

	printf("빈 상태의 스택");
	printStack();

	printf("\n\n스택에 A부터 Z까지 삽입");
	for (i = 65; i < 91; i++) {
		push(i);
	}
	printStack();

	printf("\n\npop으로 역순 출력");
	for (j = 0; j < 26; j++) {
		item[j] = pop();
	}
	printf("\n ");
	for (j = 0; j < 26; j++) {
		printf("%c ", item[j]);
	}

	printf("\n\npop 이후, 빈 상태의 스택");
	printStack();

	return 0;
}