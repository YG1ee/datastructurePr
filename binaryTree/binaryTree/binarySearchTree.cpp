#include "stdafx.h"
#include <stdlib.h>

typedef struct treeNode {
	int key;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

treeNode *insertNode(treeNode *p, char x) {
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