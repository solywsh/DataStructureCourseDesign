#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

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
	int distance[MaxVertices] = { MaxWeight }, path[MaxVertices] = { MaxWeight };
	//创建地名变量并且初始化,用于存储地名
	char PlaceName[MaxVertices][100];
	for (int i = 0; i < MaxVertices; ++i) {
		strcpy(PlaceName[i], "\0");
	}
	//创建地点编号并初始化，用于创建图时使用
	int PlaceCode[MaxVertices];
	for (int i = 0; i < MaxVertices; ++i) {
		PlaceCode[i] = i;
	}
	//创建矩阵
	RowColWeight rcw[100];
	while (1)
	{
		int choice;
		system("cls");
		printf("================================================================================\n");
		printf("                              交通旅游费用查询系统\n");
		printf("================================================================================\n");
		printf("\n");
		printf("                                 1.创建地名\n");
		printf("                                 2.输入费用\n");
		printf("                                 3.运算最短路径\n");
		printf("                                 4.打印到所有地方的费用\n");
		printf("                                 5.打印到所有地方的最短路\n");
		printf("                                 6.查询到某地的花费以及路径\n");
		printf("                                 7.退出\n");
		printf("\n");
		printf("================================================================================\n");
		printf("================================================================================\n");
		printf("请选择对应功能:");
		scanf("%d", &choice);
		getchar();
		while (choice < 1 || choice > 7) {
			
			printf("输入数字不正确，请重新输入1-5:");
			scanf("%d", &choice);
		}

		switch (choice) {
		case 1:
			//创建地名
			CreatePlace(PlaceName);
			system("pause");//停顿
			break;
		case 2:
			//输入矩阵
			count = CreateAdjacencyMatrix(PlaceName, rcw);
			break;
		case 3:
			//创建图
			if (count == 0) {
				printf("请先创建地名以及输入费用!\n");
				system("pause");//停顿
				break;
			}
			CreatGraph(&g, PlaceCode, n, rcw, count);
			//进行最短路径运算
			Dijkstra(g, 0, distance, path);
			printf("最短路径计算成功!\n");
			system("pause");
			break;
		case 4:
			//打印到其他地点的花费
			if (!strcmp(PlaceName[0], "\0")) {
				printf("地名没有创建,请先创建地名!\n");
				system("pause");//停顿
				break;
			}
			if (distance[0] != 0) {
				printf("没有找到花费信息,请先进行计算!\n");
				system("pause");//停顿
				break;
			}
			print_cost(PlaceName, distance);
			system("pause");
			break;
		case 5:
			if (!strcmp(PlaceName[0], "\0")) {
				printf("地名没有创建,请先创建地名!\n");
				system("pause");//停顿
				break;
			}
			if (path[0] == MaxWeight) {
				printf("么有找到路径信息,请先进行最短路径运算!\n");
				system("pause");//停顿
				break;
			}
			//打印到其他地点的路径
			print_path(PlaceName, path);
			system("pause");//停顿
			break;
		case 6:
			//打印到其他地点的路径
			find_one(PlaceName, distance, path);
			break;
		default:
			return 0;
		}
	}
}


