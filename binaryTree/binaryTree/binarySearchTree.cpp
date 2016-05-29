#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
	element key;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *insertNode(treeNode *p, element x) {
	treeNode *newNode;
	if (p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (x < p->key)
		p->left = insertNode(p->left, x);
	else if (x > p->key)
		p->right = insertNode(p->right, x);
	else // x = p->key
		printf("\n 이미 같은 키가 있습니다! \n");

	return p;
}

void deleteNode(treeNode *root, element key) {
	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) { // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->key)
			p = p->left;
		else // key > p->key
			p = p->right;
	}
	if (p == NULL) { // 삭제할 노드가 없는 경우
		printf("\n 찾는 키가 이진 트리에 없습니다!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p)
				parent->left = NULL;
			else // parent->right == p
				parent->right = NULL;
		}
		else // parent == NULL
			root = NULL;
	}
	// 삭제할 노드의 차수가 1인 경우
	// 원래는 (left,right) = (0,0), (1,0), (0,1) 세 가지지만,
	// 차수가 0인 경우 (0,0)는 위에서 거르고 오니까 차수가 1인 경우만 걸러냄
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL)
			child = p->left;
		else // p->right != NULL
			child = p->right;

		if (parent != NULL) { // 고아가 된 노드 입양작업
			if (parent->left == p)
				parent->left = child;
			else // parent-> right == p
				parent->right = child;
		}
		else // parent == NULL
			root = child;
	}

	// 삭제할 노드가 두 개의 자식 노드를 가진 경우
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ)
			succ_parent->left = succ->left;
		else // succ_parent->right == succ
			succ_parent->right = succ->left;
		p->key = succ->key;
		p = succ;
	}
	free(p);
	printf("%c 키가 담긴 노드를 삭제 완료했습니다!", key);
}

treeNode *searchBST(treeNode *root, element x) {
	// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
	treeNode *p;
	p = root;
	while (p != NULL) {
		if (x < p->key)
			p = p->left;
		else if (x > p->key)
			p = p->right;
		else // x == p->key
			return p;
	}
	printf("\n 찾는 키가 없습니다!");
	return p;
}

void displayInorder(treeNode* root) {
	// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
	if (root) {
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}

void menu() {
	printf("\n*-------------------*");
	printf("\n\t1 : 트리 출력");
	printf("\n\t2 : 문자 삽입");
	printf("\n\t3 : 문자 삭제");
	printf("\n\t4 : 문자 검색");
	printf("\n\t5 : 종료");
	printf("\n*-------------------*");
	printf("\n메뉴입력 >> ");
}

int main() {
	treeNode* root = NULL;
	treeNode* foundNode = NULL;
	element choice, key;

	root = insertNode(root, 'G'); // 트리 만들기
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');

	while (1) {
		menu();
		choice = getchar(); getchar();
		switch (choice) {
		case '1': printf("\t[이진트리 출력] ");
			displayInorder(root); printf("\n");
			break;
		case '2': printf("삽입할 문자를 입력하세요: ");
			key = getchar(); getchar();
			insertNode(root, key);
			break;
		case '3': printf("삭제할 문자를 입력하세요: ");
			key = getchar(); getchar();
			deleteNode(root, key);
			break;
		case '4': printf("찾을 문자를 입력하세요: ");
			key = getchar(); getchar();
			foundNode = searchBST(root, key);
			if (foundNode)
				printf("\n %c를 찾았습니다! \n", foundNode->key);
			else
				printf("\n 문자를 찾지 못했습니다. \n");
			break;
		case '5': printf("프로그램을 종료합니다.\n");
			return 0;
		default: printf("없는 메뉴입니다. 숫자를 정확히 입력해주세요. \n");
			break;
		}
	}
}