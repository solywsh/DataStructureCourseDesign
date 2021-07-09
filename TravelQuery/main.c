#include <malloc.h>

typedef int DataType;
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
	//������������,���ڴ洢����
	char PlaceName[MaxVertices][100];
	//�����ص��ţ����ڴ���ͼʱʹ��
	int PlaceCode[MaxVertices];
	for (int i = 0; i < MaxVertices; ++i) {
		PlaceCode[i] = i;
	}

	//��������
	CreatePlace(PlaceName);
	//�����ڽӾ���
	RowColWeight rcw[100];
	count = CreateAdjacencyMatrix(PlaceName, rcw);
	//����ͼ
	CreatGraph(&g, PlaceCode, n, rcw, count);
	//�������·������
	Dijkstra(g,0, distance, path);
	//��ӡ�������ص�Ļ���
	print_cost(PlaceName, distance);
	//��ӡ�������ص��·��
	print_path(PlaceName, path);

	return 0;
}