#include <stdio.h>

#define MaxSize 1000
typedef char DataType;

#include "SeqList.h"


int main(void) {

	SeqList myList;
	char *word = "dasjdg123usaig��gdyag��  �涨UI  ����˾����a312312gfduiagdi  �����Ĺ��ι涨UI���ϵ�ydg2132189361 ";
	int TotalWords = 0, CN_number = 0, EN_number = 0, NUM_number = 0, SPA_number = 0;

//	printf("������һ�����֣�");
//	scanf("%s",word);

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
		printf("%c", temporary);

		if (temporary == 32)SPA_number++;
		if ((unsigned char) temporary > 127) CN_number++;
		if (temporary >= 48&&temporary<=57 ) NUM_number++;
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90))EN_number++;
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


