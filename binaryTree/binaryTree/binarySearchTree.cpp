#include "stdafx.h"

typedef char element;

typedef struct treeNode {
	element key; // ������ �ʵ�
	struct treeNode *left; // ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode *right; // ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

treeNode *insertNode(treeNode *p, char x) {
	// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
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
	else printf("\n�̹� ���� Ű�� �ֽ��ϴ�.\n");

	return p;
}

void deleteNode(treeNode *root, element key) {
	// root ������ Ž���Ͽ� key ���� ���� ��带 ã�� �����ϴ� ����
	treeNode *child, *parent, *p, *succ, *succ_parent;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}
	if (p == NULL) { // ������ ��尡 ���� ���
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!");
		return;
	}

	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right = NULL)) {
		if (parent != NULL) {
			if (parent->left == p)
				parent->left = NULL;
			else parent->right = NULL;
		}
		else root = NULL;
	}

	// ������ ��尡 �� ���� �ڽ� ��带 ���� ���
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
	
	// ������ ��尡 �� ���� �ڽ� ��带 ���� ���
	else {
		succ_parent = p;
		succ = p->left;
		while (succ->right != NULL) {
			succ_parent = succ;

		}
	}
}