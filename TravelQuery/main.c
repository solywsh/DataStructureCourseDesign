#include <malloc.h>

typedef char DataType;
#define MaxSize 10 //顺序表数组最大个数
#define MaxVertices 10//顶点最大个数
#define MaxWeight 10000//权值最大值

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"
#include "map.h"

int main(void) {
	AdjMGraph g;
	//创建10个地点
	char a[MaxVertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
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
	int i, n = MaxVertices, e = 14;
	int distance[MaxVertices], path[MaxVertices];
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