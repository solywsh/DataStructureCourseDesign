#include <malloc.h>

typedef char *DataType;
#define MaxSize 10 //˳�������������
#define MaxVertices 10//����������
#define MaxWeight 10000//Ȩֵ���ֵ

#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include "Dijkstra.h"
#include "map.h"

//int main(void) {
//	AdjMGraph g;
//	//����10���ص�
//	char a[MaxVertices] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
//	//�����ڽӾ���
//	RowColWeight rcw[] = {
//			{0, 1, 2},
//			{0, 2, 3},
//			{1, 2, 5},
//			{1, 4, 7},
//			{2, 5, 6},
//			{2, 6, 4},
//			{3, 5, 3},
//			{3, 7, 2},
//			{3, 8, 7},
//			{4, 3, 4},
//			{5, 8, 8},
//			{6, 7, 10},
//			{6, 9, 10},
//			{8, 9, 20},
//	};
//	//���û�������������10���ص㣬14��·��
//	int i, n = MaxVertices, e = 14;
//	int distance[MaxVertices], path[MaxVertices];
//	CreatGraph(&g, a, n, rcw, e);
//	Dijkstra(g, 0, distance, path);
//
//	printf("��%c�������������·��Ϊ:\n", g.Vertices.list[0]);
//	for (i = 0; i < n; ++i) {
//		printf("\t��%c������·��Ϊ%dԪ.\n", g.Vertices.list[i], distance[i]);
//	}
//
//	printf("\n��%c�����������ǰһ�ص�Ϊ:\n", g.Vertices.list[0]);
//	for (i = 1; i < n; ++i) {
//		//PreviousPath(&g, path, i);
//		int Previous_Place, flag = i;
//		if (path[flag] != -1) {
//			printf("\t������%c��·��Ϊ: %c", g.Vertices.list[i], g.Vertices.list[i]);
//			Previous_Place = path[flag];
//			while (Previous_Place != -1 ) {
//				printf("<-%c", g.Vertices.list[Previous_Place]);
//				Previous_Place = path[Previous_Place];
//			}
//		}
//		printf("\n");
//	}
//}
int main(void) {
//	int n = MaxVertices, count = 0;
//	int distance[MaxVertices], path[MaxVertices];
//	AdjMGraph g;
//	//����10���ص�
//	char place_name[MaxVertices];
//	CreatePlace(place_name);
//	//�����ڽӾ���
//	RowColWeight rcw[100];
//	count = CreateAdjacencyMatrix(place_name, rcw);
//	//����ͼ
//	CreatGraph(&g, place_name, n, rcw, count);
//	//�������·������
//	Dijkstra(g,0, distance, path);
//	//��ӡ�������ص�Ļ���
//	print_cost(g,distance);
//	//��ӡ�������ص��·��
//	print_path(g,path);
//
//	return 0;
	char *PlaceName[100];
	int LetterCode = 65;//����Ӣ�ı��룬a�ı���Ϊ65
	printf("������10���ص���(����0Ĭ��ΪA-J)��");

	for (int i = 0; i < 10; ++i) {
		printf("\n�������һ���ص�����ƣ�");
		gets(PlaceName[i]);
		//�ж��Ƿ�����Ϊ�գ�Ҳ����ֱ�ӻس��������Ϊ�ո�ֵ������
		if (PlaceName[i] == "0") {
			PlaceName[i] = LetterCode;
			LetterCode++;
		}


	}

	for (int i = 0; i < MaxVertices; ++i) {
		printf("%s",PlaceName[i]);
	}
}
