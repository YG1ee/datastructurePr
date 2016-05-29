#include "stdafx.h"

typedef char element;

typedef struct treeNode {
	element key; // 데이터 필드
	struct treeNode *left; // 왼쪽 서브 트리 링크 필드
	struct treeNode *right; // 오른쪽 서브 트리 링크 필드
} treeNode;

treeNode *insertNode(treeNode *p, char x) {
	// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key) p->left = insertNode(p->left, x);
	else if (x > p->key) p->right = insertNode(p->right, x);
	else printf("\n이미 같은 키가 있습니다.\n");

	return p;
}

void deleteNode(treeNode *root, element key) {
	// root 노드부터 탐색하여 key 값과 같은 노드를 찾아 삭제하는 연산
	treeNode *child, *parent, *p, *succ, *succ_parent;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
	if (p == NULL) { // 삭제할 노드가 없는 경우
		printf("\n 찾는 키가 이진 트리에 없습니다!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right = NULL)) {
		if (parent != NULL) {
			if (parent->left == p)
				parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// 삭제할 노드가 한 개의 자식 노드를 가진 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left == NULL)
			child = p->left;
		else
			child = p->right;

		if (parent != NULL) {
			if (parent->left == p)
				parent->left = child;
			else
				parent->right = child;
		}
		else
			root = child;
	}
	
	// 삭제할 노드가 두 개의 자식 노드를 가진 경우
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;

		}
	}
}