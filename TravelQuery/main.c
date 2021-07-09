#include <malloc.h>

typedef int DataType;
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
	//创建地名变量,用于存储地名
	char PlaceName[MaxVertices][100];
	//创建地点编号，用于创建图时使用
	int PlaceCode[MaxVertices];
	for (int i = 0; i < MaxVertices; ++i) {
		PlaceCode[i] = i;
	}

	//创建地名
	CreatePlace(PlaceName);
	//输入邻接矩阵
	RowColWeight rcw[100];
	count = CreateAdjacencyMatrix(PlaceName, rcw);
	//创建图
	CreatGraph(&g, PlaceCode, n, rcw, count);
	//进行最短路径运算
	Dijkstra(g,0, distance, path);
	//打印到其他地点的花费
	print_cost(PlaceName, distance);
	//打印到其他地点的路径
	print_path(PlaceName, path);

	return 0;
}