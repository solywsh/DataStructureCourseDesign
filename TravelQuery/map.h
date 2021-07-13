#pragma once

#include <stdio.h>
#include "AdjMGraph.h"
#include "AdjMGraphCreate.h"
#include <string.h>

//#include "windows.h"
//����10���ص�
void CreatePlace(char PlaceName[MaxVertices][100]) {
	system("cls");
	int choose;
	if (PlaceName[0][0] != '\0') {
		printf("��ѯ�����Ѿ������˵���,ȷ���Ե������г�ʼ��?(1.ȷ��;2.�˳�):");
		scanf("%d", &choose);
		if (choose == 2) return;
	}

	//�Ե����������г�ʼ��

	for (int i = 0; i < MaxVertices; ++i) {
		strcpy(PlaceName[i], "\0");
	}
	printf("��ʼ���ɹ�!\n");

	int LetterCode = 65;//����Ӣ�ı��룬A�ı���Ϊ65
	printf("������10����������(�س�Ĭ��ΪA-J)��");

	for (int i = 0; i < MaxVertices; ++i) {
		printf("\n�������%d��������ƣ�", i + 1);
		gets(PlaceName[i]);
		//�ж��Ƿ�����Ϊ�գ�Ҳ����ֱ�ӻس��������Ϊ�ո�ֵ������
		if (PlaceName[i][0] == '\0') {
			PlaceName[i][0] = LetterCode;
			//�ڸ�ֵ��֮�����ֺ����������������Ϊ���Է���һ������һ��������־
			PlaceName[i][1] = '\0';
			LetterCode++;
		}
		printf("������%d������Ϊ:%s", i + 1, PlaceName[i]);
	}

	printf("\n�����ĵ���Ϊ:");
	for (int i = 0; i < MaxVertices; ++i) {
		printf("\t%s", PlaceName[i]);
	}
	printf("\n");
}

//����ͼ
int CreateAdjacencyMatrix(char PlaceName[MaxVertices][100], RowColWeight AM[]) {
	system("cls");
	if (!strcmp(PlaceName[0], "\0")) {
		printf("����û�д���,���ȴ�������!\n");
		system("pause");//ͣ��
		return  0;
	}
	int i = 0, count = 14;//Ĭ��·��������
	int whether = 0;//��������ѡ��

	printf("\n�Ƿ�����Դ���·���Լ�����·��?(1.yes/2.no):");
	scanf("%d", &whether);
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

		printf("·�������ɹ�!\n");
		system("pause");
		return count;
	}


	count = 0;//��ʼ��·������
	while (i < MaxVertices) {
		system("cls");
		int row_ = i, col_ = 0, weight_ = 0;
		printf("\n��ѡ��%s�������ط���·��:\n", PlaceName[i]);

		for (int j = 0; j < MaxVertices; ++j) {
			if (j == i)continue;
			printf("\t%d:%s\n", j + 1, PlaceName[j]);
		}

		printf("\n(����0��������·��������,����99��������·��������):");
		scanf("%d", &col_);
		if (col_ == 0) {
			i++;
			continue;
		}
		if (col_ == 99)break;
		if (col_ < 1 || col_ >10 || --col_ == row_) {
			printf("\n����·�����Ϸ������������롣\n");
			system("pause");
			continue;
		}
		printf("\n�����뾰��%s��%s�Ļ���(����%d����):", PlaceName[row_], PlaceName[col_], MaxWeight);
		scanf("%d", &weight_);
		if (weight_ == MaxWeight)continue;

		RowColWeight AM_ = { row_, col_, weight_ };
		//�ж������Ƿ�Ϸ�
		if (count != 0) {
			for (int j = 0; j < count; ++j) {
				if (AM[j].col == AM_.col && AM[j].row == AM_.row) {
					printf("\n���Ѿ���������ͬ��·��,�Ƿ�ȷ������?(1.����;2.����):");
					scanf("%d", &whether);
					if (whether == 1) {
						AM[j].weight = AM_.weight;
						continue;
					}
					else continue;
				}
			}
		}

		AM[count] = AM_;//���и�ֵ
		count++;//����·����Ŀ
	}
	printf("·�������ɹ�!\n");
	system("pause");
	return count;
}

//��ӡ����
void print_cost(char PlaceName[MaxVertices][100], int distance_[MaxVertices]) {
	printf("\n��%s�������������·��Ϊ:\n", PlaceName[0]);
	for (int i = 0; i < MaxVertices; ++i) {
		if (distance_[i]== MaxWeight)
		{
			printf("\t���ܵ�%s.\n", PlaceName[i]);
			continue;
		}
		printf("\t��%s������·��Ϊ%dԪ.\n", PlaceName[i], distance_[i]);
	}
}


//��ӡ���·��
void print_path(char PlaceName[MaxVertices][100], const int path_[]) {
	int n = MaxVertices;
	printf("\n��%s����������ľ���·��Ϊ:\n", PlaceName[0]);
	for (int i = 1; i < n; ++i) {
		int Previous_Place, flag = i;
		if (path_[flag] != -1) {
			printf("\t������%s��·��Ϊ: %s", PlaceName[i], PlaceName[i]);
			Previous_Place = path_[flag];
			while (Previous_Place != -1) {
				printf("<-%s", PlaceName[Previous_Place]);
				Previous_Place = path_[Previous_Place];
			}
		}
		printf("\n");
	}
}

//����ĳһ���ص����Ϣ���Ҵ�ӡ
void find_one(char PlaceName[MaxVertices][100], int distance_[MaxVertices], const int path_[]) {
	int flag = -1;
	char name_[100];
	printf("��������Ҫ���ҵľ��������:");
	gets(name_);
	for (int i = 0; i < MaxVertices; ++i) {
		if (!strcmp(name_, PlaceName[i]))flag = i;
	}
	if (flag == -1) {
		printf("û���ҵ���������!\n");
		system("pause");//ͣ��
		return;
	}
	printf("\n��%s��%s����·��Ϊ:%dԪ\n", PlaceName[0], PlaceName[flag], distance_[flag]);
	printf("\n��%s����������ľ���·��Ϊ:\n", PlaceName[0]);
	for (int i = 1; i < MaxVertices; ++i) {
		int Previous_Place, flag_ = i;
		if (path_[flag_] != -1 && i == flag) {
			printf("\t������%s��·��Ϊ: %s", PlaceName[i], PlaceName[i]);
			Previous_Place = path_[flag_];
			while (Previous_Place != -1) {
				printf("<-%s", PlaceName[Previous_Place]);
				Previous_Place = path_[Previous_Place];
			}
		}
		printf("\n");
	}
	system("pause");
}
