#include <malloc.h>

typedef char DataType;
#define MaxSize 10 //˳�������������
#define MaxVertices 10//����������
#define MaxWeight 10000//Ȩֵ���ֵ

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"
#include "map.h"

int main(void) {
	AdjMGraph g;
	//����10���ص�
	int n = MaxVertices, count = 0;//countΪ·������
	int distance[MaxVertices], path[MaxVertices];
	char place_name[MaxVertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	//�����ڽӾ���
	RowColWeight rcw[100];
	count = CreateAdjacencyMatrix(place_name, rcw);
	//����ͼ
	CreatGraph(&g, place_name, n, rcw, count);
	//�������·������
	Dijkstra(g,0, distance, path);
	//��ӡ�������ص�Ļ���
	print_cost(g,distance);
	//��ӡ�������ص��·��
	print_path(g,path);

	return 0;
}