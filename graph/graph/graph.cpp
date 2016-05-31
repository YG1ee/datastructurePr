// graph.cpp : Defines the entry point for the console application.
// stdafx contains stdio, stdlib, tchar
//

#include "stdafx.h"
#define MAX_VERTEX 30

typedef struct graphNode { // 그래프에 대한 인접 리스트의 노드 구조 정의
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n; // 정점의 갯수
	graphNode* adjList_H[MAX_VERTEX]; // 그래프 정점에 대한 헤드 노드 배열
} graphType;

void createGraph(graphType *g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++)
		g->adjList_H[v] = NULL; // 그래프의 정점에 대한 헤드 노드 배열을 NULL로 초기화
}

void insertVertex(graphType* g, int v) { // 그래프 g에 정점 v를 삽입하는 연산
	if (((g->n) + 1)>MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

void insertEdge(graphType* g, int u, int v) { // 그래프 g에 간선 (u,v)를 삽입하는 연산
	graphNode* node; // 새로 만들어주는 노드
	if ((u >= g->n) || (v >= g->n)) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node; // g의 헤드 노드를 새로 만들어준 노드가 되도록 포인팅
	// g->adjList_H[u]->link 를 하지 않는 이유는 adjList_H가 2차원 배열이기 때문에
	// 열값을 지정해주지 않으면 자동으로 name주소를 가리키기 때문
}

void print_adjList(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65); // 정점 0~3을 A~D로 출력
			p = p->link;
		}
	}
}

int main()
{
    return 0;
}

