// binaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

typedef struct treeNode { // ���� �ڷᱸ���� �����ϱ� ���� Ʈ���� ��� ����
	char data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	// data�� ��Ʈ ���� �Ͽ� ���� ����Ʈ���� ������ ����Ʈ���� �����ϴ� ����
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder(treeNode* root) {
	if (root) {
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

int main() {
	treeNode* n7 = makeRootNode('D', NULL, NULL);
	treeNode* n6 = makeRootNode('C', NULL, NULL);
	treeNode* n5 = makeRootNode('B', NULL, NULL);
	treeNode* n4 = makeRootNode('A', NULL, NULL);
	treeNode* n3 = makeRootNode('/', n6, n7);
	treeNode* n2 = makeRootNode('*', n4, n5);
	treeNode* n1 = makeRootNode('-', n2, n3);

	printf("- preorder\n");
	preorder(n1);

	printf("\n\n- inorder\n");
	inorder(n1);

	printf("\n\n- postorder\n");
	postorder(n1);

	system("pause");
	return 0;
}