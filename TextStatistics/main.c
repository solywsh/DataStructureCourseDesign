#include <stdio.h>

#define MaxSize 1000
typedef char DataType;

#include "SeqList.h"


int main(void) {

	SeqList myList;
	//������
	//char *word = "һ�����飬������������飬��ŷ���ε���Ϊ�˶�������������ʥ��Χ�ˣ���ŷ�޵�һ���������̻ʺ�ɳ�ʡ�÷�����ͻ����������ļ����ɺ͵¹��ľ��죬�����������ˡ�";
	char word[MaxSize]="\0";
	int TotalWords = 0, CN_number = 0, EN_number = 0, NUM_number = 0, SPA_number = 0;

	printf("������һ�����֣�");
	gets(word);

	//��ʼ�������ַ�������˳���
	ListInitiate(&myList);
	for (int i = 0; word[i] != '\0'; ++i) {
		ListInsert(&myList, i, word[i]);
	}
	printf("\n");

	char temporary;//����һ����ʱ����
	//get˳�������ݣ���ÿ���ַ����м��
	for (int i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &temporary);
		printf("%c", temporary);//�Զ�ȡ���ַ��������
		//�ж��Ƿ�Ϊ�ո�
		if (temporary == 32)SPA_number++;
		//�ж��Ƿ�Ϊ���ģ�C���Դ�������ʱ��GBK���ת��Ϊ������Ȼ����unsigned����Ϊ����127�ı���
		if ((unsigned char) temporary > 127) CN_number++;
		//�ж�����
		if (temporary >= 48&&temporary<=57 ) NUM_number++;
		//�ж�Ӣ�ģ���Ϊa-z��A-Z
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90))EN_number++;
		//������
		TotalWords++;
	}

	printf("\n");
	printf("��������%d\n", TotalWords);
	printf("����������%d\n", CN_number / 2);
	printf("Ӣ��������%d\n", EN_number);
	printf("����������%d\n", NUM_number);
	printf("�ո�������%d\n", SPA_number);
	return 0;

}


