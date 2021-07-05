#include <stdio.h>
#include <malloc.h>

typedef char DataType;
#define MaxSize 10
#define MaxVertices 10
#define MaxWeight 10000

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"


// void PreviousPath(AdjMGraph *g, const int path[10], int flag) {
// 	int Previous_Place = path[flag],temp;
// 	if (Previous_Place != -1) {
// 		temp = Previous_Place;
// 		PreviousPath(g, path, path[Previous_Place]);
// 		printf("%c->", g->Vertices.list[temp]);
// 	} else return;
// }

int main(void) {
	AdjMGraph g;
	//创建10个地点
	char a[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	//输入邻接矩阵
	RowColWeight rcw[] = {
			{0, 1, 2},
			{0, 2, 3},
			{1, 2, 5},
			{1, 4, 7},
			{2, 5, 6},
			{2, 6, 4},
			{3, 5, 3},
			{3, 7, 2},
			{3, 8, 7},
			{4, 3, 4},
			{5, 8, 8},
			{6, 7, 10},
			{6, 9, 10},
			{8, 9, 20},
	};
	//设置基本变量，共有10个地点，14条路径
	int i, n = 10, e = 14;
	int distance[10], path[10];
	CreatGraph(&g, a, n, rcw, e);
	Dijkstra(g, 0, distance, path);

	printf("从%c到其他景点的少路费为:\n", g.Vertices.list[0]);
	for (i = 0; i < n; ++i) {
		printf("\t到%c的最少路费为%d元.\n", g.Vertices.list[i], distance[i]);
	}

	printf("\n从%c到其他景点的前一地点为:\n", g.Vertices.list[0]);
	for (i = 1; i < n; ++i) {
		//PreviousPath(&g, path, i);
		int Previous_Place, flag = i;
		if (path[flag] != -1) {
			printf("\t到景点%c的路径为: %c", g.Vertices.list[i], g.Vertices.list[i]);
			Previous_Place = path[flag];
			while (Previous_Place != -1 ) {
				printf("<-%c", g.Vertices.list[Previous_Place]);
				Previous_Place = path[Previous_Place];
			}
		}
		printf("\n");
	}
}
