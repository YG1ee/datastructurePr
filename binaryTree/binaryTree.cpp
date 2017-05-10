#include <stdio.h>
#include <stdlib.h>

typedef int dataType;

int folderSize = 0;

typedef struct treeNode { // 연결 자료구조로 구성하기 위해 트리의 노드 정의
	dataType data;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	// data를 루트 노드로 하여 왼쪽 서브트리와 오른쪽 서브트리를 연결하는 연산
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

int preorder(treeNode* root) {
	if (root) {
		folderSize += root->data;
		preorder(root->left);
		preorder(root->right);
	}
	return folderSize;
}

int inorder(treeNode* root) {
	if (root) {
		inorder(root->left);
		folderSize += root->data;
		inorder(root->right);
	}
	return folderSize;
}

int postorder(treeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		folderSize += root->data;
	}
	return folderSize;
}

int main() {
	treeNode* n7 = makeRootNode(10, NULL, NULL);
	treeNode* n6 = makeRootNode(20, NULL, NULL);
	treeNode* n5 = makeRootNode(30, NULL, NULL);
	treeNode* n4 = makeRootNode(40, NULL, NULL);
	treeNode* n3 = makeRootNode(50, n6, n7);
	treeNode* n2 = makeRootNode(60, n4, n5);
	treeNode* n1 = makeRootNode(70, n2, n3);

	printf("- preorder\n");
	preorder(n1);
	printf("size of the entire folder: %d", folderSize);

	printf("\n\n- inorder\n");
	inorder(n1);
	printf("size of the entire folder: %d", folderSize);

	printf("\n\n- postorder\n");
	postorder(n1);
	printf("size of the entire folder: %d", folderSize);

	printf("\n");

	return 0;
}