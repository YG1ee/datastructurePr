// graph.cpp : Defines the entry point for the console application.
// stdafx contains stdio, stdlib, tchar
//

#include "stdafx.h"
#define MAX_VERTEX 30

typedef struct graphNode { // �׷����� ���� ���� ����Ʈ�� ��� ���� ����
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n; // ������ ����
	graphNode* adjList_H[MAX_VERTEX]; // �׷��� ������ ���� ��� ��� �迭
} graphType;

void createGraph(graphType *g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL; // �׷����� ������ ���� ��� ��� �迭�� NULL�� �ʱ�ȭ
}

void insertVertex(graphType* g, int v) { // �׷��� g�� ���� v�� �����ϴ� ����
	if (((g->n) + 1)>MAX_VERTEX) {
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v) { // �׷��� g�� ���� (u,v)�� �����ϴ� ����
	graphNode* node; // ���� ������ִ� ���
	if ((u >= g->n) || (v >= g->n)) {
		printf("\n �׷����� ���� �����Դϴ�!");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node; // g�� ��� ��带 ���� ������� ��尡 �ǵ��� ������
	// g->adjList_H[u]->link �� ���� �ʴ� ������ adjList_H�� 2���� �迭�̱� ������
	// ������ ���������� ������ �ڵ����� name�ּҸ� ����Ű�� ����
}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t���� %c�� ���� ����Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65); // ���� 0~3�� A~D�� ���
			p = p->link;
		}
	}
}

int main()
{
    return 0;
}

