#pragma once

#include <stdio.h>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include <string.h>

//创建10个地点
void CreatePlace(char PlaceName[MaxVertices][100]) {

	//对地名参数进行初始化
	for (int i = 0; i < MaxVertices; ++i) {
		strcpy(PlaceName[i],"\0");
	}

	int LetterCode = 65;//创建英文编码，A的编码为65
	printf("请输入10个地点名(回车默认为A-J)：");

	for(int i = 0; i < MaxVertices; ++i) {
		printf("\n请输入第%d景点的名称：",i+1);
		gets(PlaceName[i]);
		//判断是否输入为空（也就是直接回车），如果为空赋值给数组
		if (PlaceName[i][0] == '\0') {
			PlaceName[i][0] = LetterCode;
			//在赋值完之后会出现后面跟着乱码的情况，为了以防万一，增加一个结束标志
			PlaceName[i][1] = '\0';
			LetterCode++;
		}
		printf("创建第%d个地名为:%s",i+1,PlaceName[i]);
	}

	printf("\n创建的地名为:");
	for (int i = 0; i < MaxVertices; ++i) {
		printf("\t%s",PlaceName[i]);
	}
	printf("\n");
}

//创建邻接矩阵
int CreateAdjacencyMatrix(char PlaceName[MaxVertices][100], RowColWeight AM[]) {
	int i = 0, count = 14;//默认路径的条数
	int whether = 0;//用于数字选择

	printf("是否采用默认路径?(1.yes/2.no):");
	scanf("%d",&whether);
	if (whether == 1) {
		//创建一个初始变量AM_用于给传入的AM赋值
		RowColWeight AM_[] = {
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
		//进行赋值
		for (int j = 0; j < count; ++j) {
			AM[j] = AM_[j];
		}

		return count;
	}


	count = 0;//初始化路径条数
	while (i < MaxVertices) {
		int row_ = i, col_ = 0, weight_ = 0;
		printf("\n请选择%s到其它地方的路径:\n", PlaceName[i]);

		for (int j = 0; j < MaxVertices; ++j) {
			if (j == i)continue;
			printf("\t%d:%s\n", j + 1, PlaceName[j]);
		}

		printf("\n(输入0结束这条路径的输入,输入99结束所有路径的输入):");
		scanf("%d",&col_);
		if (col_ == 0) {
			i++;
			continue;
		}
		if (col_ == 99)break;
		if (col_<1 || col_ >10 || --col_ == row_){
			printf("输入路径不合法！请重新输入。\n");
			continue;
		}
		printf("\n请输入景点%s到%s的花费(输入%d返回):",PlaceName[row_],PlaceName[col_],MaxWeight);
		scanf("%d",&weight_);
		if (weight_ == MaxWeight)continue;

		RowColWeight AM_ = {row_, col_, weight_};
		//判断输入是否合法
		if (count!=0){
			for (int j = 0; j < count; ++j) {
				if (AM[j].col==AM_.col && AM[j].row == AM_.row){
					printf("你已经输入了相同的路径,是否确定覆盖?(1.覆盖;2.跳过):");
					scanf("%d",&whether);
					if (whether==1){
						AM[j].weight = AM_.weight;
						continue;
					} else continue;
				}
			}
		}

		AM[count] = AM_;//进行赋值
		count++;//增加路径数目
	}

	return count;
}

//打印开销
void print_cost(char PlaceName[MaxVertices][100], int distance_[MaxVertices]) {
	printf("\n从%s到其他景点的少路费为:\n", PlaceName[0]);
	for (int i = 0; i < MaxVertices; ++i) {
		printf("\t到%s的最少路费为%d元.\n", PlaceName[i], distance_[i]);
	}
}


//打印最短路径
void print_path(char PlaceName[MaxVertices][100], const int path_[]) {
	int n = MaxVertices;
	printf("\n从%s到其他景点的前一地点为:\n",PlaceName[0]);
	for (int i = 1; i < n; ++i) {
		int Previous_Place, flag = i;
		if (path_[flag] != -1) {
			printf("\t到景点%s的路径为: %s", PlaceName[i], PlaceName[i]);
			Previous_Place = path_[flag];
			while (Previous_Place != -1) {
				printf("<-%s", PlaceName[Previous_Place]);
				Previous_Place = path_[Previous_Place];
			}
		}
		printf("\n");
	}
}

