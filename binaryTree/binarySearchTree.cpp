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
		printf("\n 이미 같은 키가 있습니다!! \n");

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
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!");
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
	// ������ ������ ������ 1�� ����
	// ������ (left,right) = (0,0), (1,0), (0,1) �� ��������,
	// ������ 0�� ���� (0,0)�� ������ �Ÿ��� ���ϱ� ������ 1�� ���츸 �ɷ���
	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL)
			child = p->left;
		else // p->right != NULL
			child = p->right;

		if (parent != NULL) { // ���ư� �� ���� �Ծ��۾�
			if (parent->left == p)
				parent->left = child;
			else // parent-> right == p
				parent->right = child;
		}
		else // parent == NULL
			root = child;
	}

	// ������ ���尡 �� ���� �ڽ� ���带 ���� ����
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
	printf("%c Ű�� ���� ���带 ���� �Ϸ��߽��ϴ�!", key);
}

treeNode *searchBST(treeNode *root, element x) {
	// ���� Ž�� Ʈ������ Ű���� x�� ������ ��ġ�� Ž���ϴ� ����
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
	printf("\n ã�� Ű�� �����ϴ�!");
	return p;
}

void displayInorder(treeNode* root) {
	// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 �����ϴ� ����
	if (root) {
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}

void menu() {
	printf("\n*-------------------*");
	printf("\n\t1 : Ʈ�� ����");
	printf("\n\t2 : ���� ����");
	printf("\n\t3 : ���� ����");
	printf("\n\t4 : ���� �˻�");
	printf("\n\t5 : ����");
	printf("\n*-------------------*");
	printf("\n�޴��Է� >> ");
}

int main() {
	treeNode* root = NULL;
	treeNode* foundNode = NULL;
	element choice, key;

	root = insertNode(root, 'G'); // Ʈ�� ������
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
		case '1': printf("\t[����Ʈ�� ����] ");
			displayInorder(root); printf("\n");
			break;
		case '2': printf("������ ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			insertNode(root, key);
			break;
		case '3': printf("������ ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			deleteNode(root, key);
			break;
		case '4': printf("ã�� ���ڸ� �Է��ϼ���: ");
			key = getchar(); getchar();
			foundNode = searchBST(root, key);
			if (foundNode)
				printf("\n %c�� ã�ҽ��ϴ�! \n", foundNode->key);
			else
				printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			break;
		case '5': printf("���α׷��� �����մϴ�.\n");
			return 0;
		default: printf("���� �޴��Դϴ�. ���ڸ� ��Ȯ�� �Է����ּ���. \n");
			break;
		}
	}
}