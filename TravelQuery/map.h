#include <stdio.h>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

//创建10个地点
void CreatePlace(char *PlaceName[MaxVertices]) {

	int LetterCode = 65;//创建英文编码，a的编码为65
	printf("请输入10个地点名(回车默认为A-J)：")

	for (int i = 0; i < MaxVertices; ++i) {
		printf("\n请输入第一个地点的名称：")
		gets(PlaceName[i]);
		//判断是否输入为空（也就是直接回车），如果为空赋值给数组
		if (PlaceName[i][0] == '\0') {
			PlaceName[i][0] =
			char(LetterCode);
			LetterCode++;
		}
	}

}

//创建邻接矩阵
int CreateAdjacencyMatrix(char *PlaceName[MaxVertices], RowColWeight AM[]) {
	int flag = 1, i = 0, count = 14;//默认路径的条数
	int whether = 0;//用于数字选择

	printf("是否采用默认路径?(1.yes/2.no):");
	whether = getchar();

	if (whether == 2) {
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
	while (flag && i < MaxVertice) {
		RowColWeight AM_[];
		int row_ = i, col_ = 0, weight_ = 0;
		printf("\n请选择%s到其它地方的路径:\n(", PlaceName[i]);
		for (int j = 0; j < MaxVertices - 1; ++j) {
			if (j == i)continue;
			printf("%d:%s,", j + 1, PlaceName[j]);
		}
		printf(")\n(输入0结束这条路径的输入,输入99结束所有路径的输入):");

		col_ = getchar();
		if (whether == 0) {
			i++;
			continue;
		}
		if (whether == 99)break;


		printf("请输入这条路径的花费:");
		weight_ = getchar();

		AM_[i] = {row_, col_, weight_};//进行赋值
		count++;//增加路径数目
	}

	return count;
}

