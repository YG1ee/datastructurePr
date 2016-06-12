//  binarySearchTree

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef char element;

typedef struct treeNode {
	element data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

char s2l(char alp) { // �ҹ��ڸ� �빮�ڷ� �ٲ��ִ� �Լ�
	if (('a' <= alp) && (alp <= 'z'))
		alp -= 32;
	return alp;
}

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

treeNode *insertNode(treeNode *tree, element key) {
	treeNode *newNode;
	key = s2l(key);

	if (tree == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->data = key;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (key < tree->data) {
		tree->left = insertNode(tree->left, key);
	}
	else if (key > tree->data) {
		tree->right = insertNode(tree->right, key);
	}
	else {
		printf("\n�ش� Ű�� �̹� ���� Ʈ���� �ֽ��ϴ�!\n");
	}

	return tree;
}

void deleteNode(treeNode *tree, element key) {
	treeNode *p = tree;
	treeNode *parent, *child;
	treeNode *succ = NULL, *succ_parent;
	key = s2l(key);

	parent = NULL;

	while ((p != NULL) && (p->data != key)) { // ������ ��� ��ġ Ž��
		parent = p;
		if (key < p->data) {
			p = p->left;
		}
		else { // key > p->data
			p = p->right;
		}
	}

	if (!p) {
		printf("\n ������� Ű�� ���� Ʈ���� �����ϴ�!\n");
		return;
	}

	// ������ ��尡 �ܸ��� ���
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
	// ������ ����� ������ 1�� ���
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
		else { // parent == NULL, �� p�� root�� ��Ȳ
			tree = child; // root �ڸ��� child�� ����.
		}
	}
	// ������ ����� ������ 2�� ���
	else {
		// ������ ���� ū Ű ��������
		succ_parent = succ;
		succ = p->left;
		while (succ->right) {
			succ_parent = succ;
			succ = succ->right;
		}
		if (succ_parent->left == succ) {
			succ_parent->left = succ->left;
		}
		else {
			succ_parent->right = succ->left;
		}
		p->data = succ->data;
		p = succ;
	}
	free(p);
	printf("\n %c Ű�� ���������� �����߽��ϴ�!\n", key);
}

treeNode *searchBST(treeNode *tree, element key) {
	treeNode *p = tree;
	key = s2l(key);

	while (p) {
		if (key == p->data) {
			break;
		}
		else if (key < p->data) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (!p)
		printf("\n ã�� Ű�� ���� Ʈ���� �������� �ʽ��ϴ�!\n");
	return p;
}

void displayInorder(treeNode* tree) {
	if (tree) {
		displayInorder(tree->left);
		printf("%c_", tree->data);
		displayInorder(tree->right);
	}
}

void menu() {
	printf("\n*------------------------*\n");
	printf("\n\t1: Ʈ�� ���");
	printf("\n\t2: ���� ����");
	printf("\n\t3: ���� ����");
	printf("\n\t4: ���� �˻�");
	printf("\n\t5: ����");
	printf("\n*------------------------*\n");
	printf("\n�޴� �Է� >> ");
}

int main() {
	treeNode* tree = NULL;
	treeNode* foundNode = NULL;
	char key, choice;

	tree = insertNode(tree, 'G'); // Ʈ�� �����
	insertNode(tree, 'I');
	insertNode(tree, 'H');
	insertNode(tree, 'D');
	insertNode(tree, 'B');
	insertNode(tree, 'M');
	insertNode(tree, 'N');
	insertNode(tree, 'A');
	insertNode(tree, 'J');
	insertNode(tree, 'E');
	insertNode(tree, 'Q');

	while (1) {
		menu();
		choice = getchar(); getchar();
		switch (choice) {
		case '1': printf("\t[���� Ʈ�� ���] ");
			displayInorder(tree);
			printf("\n");
			break;
		case '2': printf("������ ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			insertNode(tree, key);
			break;
		case '3': printf("������ ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			deleteNode(tree, key);
			break;
		case '4': printf("ã�� ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			foundNode = searchBST(tree, key);
			if (foundNode) {
				printf("\n %c Ű�� ã�ҽ��ϴ�! \n", foundNode->data);
			} else {
				printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			} break;
		case '5': return 0;
		default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
			break;
		}
	}
	return 0;
}