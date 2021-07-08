#pragma once

#include <stdio.h>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

////����10���ص�
//void CreatePlace(char PlaceName[MaxVertices][100]) {
//
//	int LetterCode = 65;//����Ӣ�ı��룬a�ı���Ϊ65
//	printf("������10���ص���(����0Ĭ��ΪA-J)��");
//
//	for(int i = 0; i < MaxVertices; ++i) {
//		printf("\n�������һ���ص�����ƣ�");
//		gets(PlaceName[i]);
//		//�ж��Ƿ�����Ϊ�գ�Ҳ����ֱ�ӻس��������Ϊ�ո�ֵ������
//		if (PlaceName[i][0] == '0') {
//			PlaceName[i][0] = LetterCode;
//			//�ڸ�ֵ��֮�����ֺ����������������Ϊ���Է���һ������һ��������־
//			PlaceName[i][1] = '\0';
//			LetterCode++;
//		}
//	}
//
//}

//�����ڽӾ���
int CreateAdjacencyMatrix(char PlaceName[], RowColWeight AM[]) {
	int i = 0, count = 14;//Ĭ��·��������
	int whether = 0;//��������ѡ��

	printf("�Ƿ����Ĭ��·��?(1.yes/2.no):");
	scanf("%d",&whether);
	if (whether == 1) {
		//����һ����ʼ����AM_���ڸ������AM��ֵ
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
		//���и�ֵ
		for (int j = 0; j < count; ++j) {
			AM[j] = AM_[j];
		}

		return count;
	}

	count = 0;//��ʼ��·������
	while (i < MaxVertices) {
		int row_ = i, col_ = 0, weight_ = 0;
		printf("\n��ѡ��%c�������ط���·��:\n(", PlaceName[i]);

		for (int j = 0; j < MaxVertices - 1; ++j) {
			if (j == i)continue;
			printf("%d:%c,", j + 1, PlaceName[j]);
		}

		printf(")\n(����0��������·��������,����99��������·��������):");
		scanf("%d",&col_);
		if (col_ == 0) {
			i++;
			continue;
		}
		if (col_ == 99)break;
		if (col_<1 || col_ >10 || --col_ == row_){
			printf("����·�����Ϸ������������롣\n");
			continue;
		}
		printf("\n�����뾰��%c��%c�Ļ���:",PlaceName[row_],PlaceName[col_]);
		scanf("%d",&weight_);


		RowColWeight AM_ = {row_, col_, weight_};
		//�ж������Ƿ�Ϸ�
		if (count!=0){
			for (int j = 0; j < count; ++j) {
				if (AM[j].col==AM_.col && AM[j].row == AM_.row){
					printf("���Ѿ���������ͬ��·��,�Ƿ�ȷ������?(1.����;2.����):");
					scanf("%d",&whether);
					if (whether==1){
						AM[j].weight = AM_.weight;
						continue;
					} else continue;
				}
			}
		}

		AM[count] = AM_;//���и�ֵ
		count++;//����·����Ŀ
	}

	return count;
}

//��ӡ����
void print_cost(AdjMGraph g_, int distance_[MaxVertices]) {
	printf("\n��%c�������������·��Ϊ:\n", g_.Vertices.list[0]);
	for (int i = 0; i < MaxVertices; ++i) {
		printf("\t��%c������·��Ϊ%dԪ.\n", g_.Vertices.list[i], distance_[i]);
	}
}


//��ӡ���·��
void print_path(AdjMGraph g_, const int path_[]) {
	int n = MaxVertices;
	printf("\n��%c�����������ǰһ�ص�Ϊ:\n", g_.Vertices.list[0]);
	for (int i = 1; i < n; ++i) {
		int Previous_Place, flag = i;
		if (path_[flag] != -1) {
			printf("\t������%c��·��Ϊ: %c", g_.Vertices.list[i], g_.Vertices.list[i]);
			Previous_Place = path_[flag];
			while (Previous_Place != -1) {
				printf("<-%c", g_.Vertices.list[Previous_Place]);
				Previous_Place = path_[Previous_Place];
			}
		}
		printf("\n");
	}
}

