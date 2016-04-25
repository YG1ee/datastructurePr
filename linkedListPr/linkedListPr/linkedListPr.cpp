// linkedListPr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

typedef char element;

typedef struct ListNode { // �ܼ����Ḯ��Ʈ�� ��� ���� ����
	element data[4];
	struct Node *link;
} listNode;

typedef struct { // ����Ʈ�� ��� ����� ���� ����
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(); // �Լ� ���� ����
void freeLinkedList_h(linkedList_h*);
void addLastNode(linkedList_h*, char*);
void reverse(linkedList_h*);
void deleteLastNode(linkedList_h*);
void printList(linkedList_h*);

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h *)malloc(sizeof(linkedList_h)); // ��� ��� �Ҵ�
	L->head = NULL; // ���� ����Ʈ�̹Ƿ� NULL ����
	return L;
}

int main() {

	return 0;
}