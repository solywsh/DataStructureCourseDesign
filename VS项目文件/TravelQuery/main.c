#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

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
	int distance[MaxVertices] = { MaxWeight }, path[MaxVertices] = { MaxWeight };
	//���������������ҳ�ʼ��,���ڴ洢����
	char PlaceName[MaxVertices][100];
	for (int i = 0; i < MaxVertices; ++i) {
		strcpy(PlaceName[i], "\0");
	}
	//�����ص��Ų���ʼ�������ڴ���ͼʱʹ��
	int PlaceCode[MaxVertices];
	for (int i = 0; i < MaxVertices; ++i) {
		PlaceCode[i] = i;
	}
	//��������
	RowColWeight rcw[100];
	while (1)
	{
		int choice;
		system("cls");
		printf("================================================================================\n");
		printf("                              ��ͨ���η��ò�ѯϵͳ\n");
		printf("================================================================================\n");
		printf("\n");
		printf("                                 1.��������\n");
		printf("                                 2.�������\n");
		printf("                                 3.�������·��\n");
		printf("                                 4.��ӡ�����еط��ķ���\n");
		printf("                                 5.��ӡ�����еط������·\n");
		printf("                                 6.��ѯ��ĳ�صĻ����Լ�·��\n");
		printf("                                 7.�˳�\n");
		printf("\n");
		printf("================================================================================\n");
		printf("================================================================================\n");
		printf("��ѡ���Ӧ����:");
		scanf("%d", &choice);
		getchar();
		while (choice < 1 || choice > 7) {
			
			printf("�������ֲ���ȷ������������1-5:");
			scanf("%d", &choice);
		}

		switch (choice) {
		case 1:
			//��������
			CreatePlace(PlaceName);
			system("pause");//ͣ��
			break;
		case 2:
			//�������
			count = CreateAdjacencyMatrix(PlaceName, rcw);
			break;
		case 3:
			//����ͼ
			if (count == 0) {
				printf("���ȴ��������Լ��������!\n");
				system("pause");//ͣ��
				break;
			}
			CreatGraph(&g, PlaceCode, n, rcw, count);
			//�������·������
			Dijkstra(g, 0, distance, path);
			printf("���·������ɹ�!\n");
			system("pause");
			break;
		case 4:
			//��ӡ�������ص�Ļ���
			if (!strcmp(PlaceName[0], "\0")) {
				printf("����û�д���,���ȴ�������!\n");
				system("pause");//ͣ��
				break;
			}
			if (distance[0] != 0) {
				printf("û���ҵ�������Ϣ,���Ƚ��м���!\n");
				system("pause");//ͣ��
				break;
			}
			print_cost(PlaceName, distance);
			system("pause");
			break;
		case 5:
			if (!strcmp(PlaceName[0], "\0")) {
				printf("����û�д���,���ȴ�������!\n");
				system("pause");//ͣ��
				break;
			}
			if (path[0] == MaxWeight) {
				printf("ô���ҵ�·����Ϣ,���Ƚ������·������!\n");
				system("pause");//ͣ��
				break;
			}
			//��ӡ�������ص��·��
			print_path(PlaceName, path);
			system("pause");//ͣ��
			break;
		case 6:
			//��ӡ�������ص��·��
			find_one(PlaceName, distance, path);
			break;
		default:
			return 0;
		}
	}
}


