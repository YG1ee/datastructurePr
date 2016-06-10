//  binarySearchTree
//
//  Created by YGLee on 2016. 6. 10..
//  Copyright © 2016년 YGLee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct treeNode {
	element data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *searchTree(treeNode *tree, element key) {
	treeNode *p = tree;
	if (key == p->data) {
		return p;
	}
	else if (key > p->data) {
		return searchTree(p->right, key);
	}
	else { // key < p->data
		return searchTree(p->left, key);
	}
}

void insertNode(treeNode *tree, element key) {
	treeNode *p = tree, *q = NULL;
	treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
	while (p != NULL) {
		if (key == p->data) {
			return;
		}
		q = p;
		if (key < p->data) {
			p = p->left;
		}
		else { // key > p->data
			p = p->right;
		}
	}
	newNode->data = key;
	newNode->left = NULL;
	newNode->right = NULL;

	if (tree == NULL) {
		tree = newNode;
	}
	else if (key < q->data) {
		q->left = newNode;
	}
	else if (key > q->data) {
		q->right = newNode;
	}
}

void deleteNode(treeNode *tree, element key) {
	treeNode *p = tree;
	treeNode *parent, *child;
	treeNode *succ, *succ_parent;

	parent = NULL;

	while ((p != NULL) && (p->data != key)) { // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->data) {
			p = p->left;
		}
		else { // key > p->data
			p = p->right;
		}
	}

	if (p == NULL) {
		printf("\n 지우려는 키가 이진 트리에 없습니다!\n");
		return;
	}

	// 삭제할 노드가 단말인 경우 
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) {
				parent->left = NULL;
			}
			else { // parent->right == p
				parent->right = NULL;
			}
		}
	}
	// 삭제할 노드의 차수가 1인 경우
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) {
			child = p->left;
		}
		else { // p->right != NULL
			child = p->right;
		}

		if (parent != NULL) {
			if (p == parent->left) {
				parent->left = child;
			}
			else { // p == parent->right
				parent->right = child;
			}
		}
		else { // parent == NULL, 즉 p가 root인 상황
			tree = child; // root 자리에 child를 놓음.
		}
	}
	// 삭제할 노드의 차수가 2인 경우
	else {
		// 왼쪽의 가장 큰 키 불러오기
		succ = p;
		p = p->left;
		while (1) {
			succ = p;
			if (succ->right) {
				succ = succ->right;
			}
			else if (succ->left) {
				succ = p->left;
			}
			else { // (p->right == NULL) && (p->left == NULL)
				break;
			}
		}
		if (parent->left == p) {
			parent->left;
		}
	}
	free(p);
}

int main() {

	return 0;
}