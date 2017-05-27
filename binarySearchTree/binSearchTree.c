#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct treeNode {
	element data;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;

char s2l(char alp) { // 소문자를 대문자로 바꿔주는 함수
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
		printf("\n해당 키는 이미 이진 트리에 있습니다!\n");
	}

	return tree;
}

void deleteNode(treeNode *tree, element key) {
	treeNode *p = tree;
	treeNode *parent, *child;
	treeNode *succ = NULL, *succ_parent;
	key = s2l(key);

	parent = NULL;

	while ((p != NULL) && (p->data != key)) { // 삭제할 노드 위치 탐색
		parent = p;
		if (key < p->data) {
			p = p->left;
		}
		else { // key > p->data
			p = p->right;
		}
	}

	if (!p) {
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
		// 왼쪽의 가장 큰 키 가져오기
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
	printf("\n %c 키를 성공적으로 삭제했습니다!\n", key);
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
		printf("\n 찾는 키가 이진 트리에 존재하지 않습니다!\n");
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
	printf("\n\t1: 트리 출력");
	printf("\n\t2: 문자 삽입");
	printf("\n\t3: 문자 삭제");
	printf("\n\t4: 문자 검색");
	printf("\n\t5: 종료");
	printf("\n*------------------------*\n");
	printf("\n메뉴 입력 >> ");
}

int main() {
	treeNode* tree = NULL;
	treeNode* foundNode = NULL;
	char key, choice;

	tree = insertNode(tree, 'G'); // 트리 만들기
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
		case '1': printf("\t[이진 트리 출력] ");
			displayInorder(tree);
			printf("\n");
			break;
		case '2': printf("삽입할 문자를 입력하세요: ");
			key = getchar(); getchar();
			insertNode(tree, key);
			break;
		case '3': printf("삭제할 문자를 입력하세요: ");
			key = getchar(); getchar();
			deleteNode(tree, key);
			break;
		case '4': printf("찾을 문자를 입력하세요: ");
			key = getchar(); getchar();
			foundNode = searchBST(tree, key);
			if (foundNode) {
				printf("\n %c 키를 찾았습니다! \n", foundNode->data);
			} else {
				printf("\n 문자를 찾지 못했습니다. \n");
			} break;
		case '5':
			return 0;
		default: printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}
	}
	return 0;
}