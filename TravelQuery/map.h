#pragma once
#include <stdio.h>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"

//����10���ص�
void CreatePlace(char *PlaceName[MaxVertices]) {

	int LetterCode = 65;//����Ӣ�ı��룬a�ı���Ϊ65
	printf("������10���ص���(����0Ĭ��ΪA-J)��");

	for(int i = 0; i < MaxVertices; ++i) {
		printf("\n�������һ���ص�����ƣ�");
		gets(PlaceName[i]);
		//�ж��Ƿ�����Ϊ�գ�Ҳ����ֱ�ӻس��������Ϊ�ո�ֵ������
		if (PlaceName[i][0] == '0') {
			PlaceName[i][0] = LetterCode;
			LetterCode++;
		}
	}

}

//�����ڽӾ���
int CreateAdjacencyMatrix(char *PlaceName[MaxVertices], RowColWeight AM[]) {
	int i = 0, count = 14;//Ĭ��·��������
	int whether = 0;//��������ѡ��

	printf("�Ƿ����Ĭ��·��?(1.yes/2.no):");
	whether = getchar();

	if (whether == 2) {
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
		printf("\n��ѡ��%s�������ط���·��:\n(", PlaceName[i]);
		for (int j = 0; j < MaxVertices - 1; ++j) {
			if (j == i)continue;
			printf("%d:%s,", j + 1, PlaceName[j]);
		}
		printf(")\n(����0��������·��������,����99��������·��������):");

		col_ = getchar();
		if (whether == 0) {
			i++;
			continue;
		}
		if (whether == 99)break;

		printf("����������·���Ļ���:");
		weight_ = getchar();

		RowColWeight AM_ = {row_, col_, weight_};
		AM[i] = AM_;//���и�ֵ
		count++;//����·����Ŀ
	}

	return count;
}

//��ӡ����
void print_cost(AdjMGraph g_, int distance_[MaxVertices]){
	printf("��%s�������������·��Ϊ:\n", g_.Vertices.list[0]);
	for (int i = 0; i < MaxVertices; ++i) {
		printf("\t��%s������·��Ϊ%dԪ.\n", g_.Vertices.list[i], distance_[i]);
	}
}


//��ӡ���·��
void print_path(AdjMGraph g_,const int path_[]){
	int n = MaxVertices;
	printf("\n��%s�����������ǰһ�ص�Ϊ:\n", g_.Vertices.list[0]);
	for (int i = 1; i < n; ++i) {
		int Previous_Place, flag = i;
		if (path_[flag] != -1) {
			printf("\t������%s��·��Ϊ: %s", g_.Vertices.list[i], g_.Vertices.list[i]);
			Previous_Place = path_[flag];
			while (Previous_Place != -1 ) {
				printf("<-%s", g_.Vertices.list[Previous_Place]);
				Previous_Place = path_[Previous_Place];
			}
		}
		printf("\n");
	}
}