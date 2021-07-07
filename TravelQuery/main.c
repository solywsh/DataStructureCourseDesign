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
	int n = MaxVertices, count = 0;//count为路径条数
	int distance[MaxVertices], path[MaxVertices];
	char place_name[MaxVertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	//输入邻接矩阵
	RowColWeight rcw[100];
	count = CreateAdjacencyMatrix(place_name, rcw);
	//创建图
	CreatGraph(&g, place_name, n, rcw, count);
	//进行最短路径运算
	Dijkstra(g,0, distance, path);
	//打印到其他地点的花费
	print_cost(g,distance);
	//打印到其他地点的路径
	print_path(g,path);

	return 0;
}