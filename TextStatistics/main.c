#include <stdio.h>

#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"


int main(void) {

	SeqList myList;
	//������
	//char *word = "һ�����飬������������飬��ŷ���ε���Ϊ�˶�������������ʥ��Χ�ˣ���ŷ�޵�һ���������̻ʺ�ɳ�ʡ�÷�����ͻ����������ļ����ɺ͵¹��ľ��죬�����������ˡ�A ghost, the ghost of communism, wanders Europe. In order to carry out a sacred encirclement and suppression of this ghost, all the powers of old Europe, the Pope and the Tsar, Metternich and Kizo, the French radicals and the German police, united.";
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



	return 0;
}


