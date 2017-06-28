#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode { // 단순연결리스트의 노드 구조 정의
	element data[4];
	struct Node *link;
} listNode;

typedef struct { // 리스트의 헤드 노드의 구조 정의
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(); // 함수 원형 선언
void freeLinkedList_h(linkedList_h*);
void addLastNode(linkedList_h*, char*);
void reverse(linkedList_h*);
void deleteLastNode(linkedList_h*);
void printList(linkedList_h*);

linkedList_h* createLinkedList_h() {
	linkedList_h* L;
	L = (linkedList_h *)malloc(sizeof(linkedList_h)); // 헤드 노드 할당
	L->head = NULL; // 공백 리스트이므로 NULL 설정
	return L;
}

int main() {

	return 0;
}