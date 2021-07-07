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
	char all_words[100], cn_words[100], en_words[100],num_words[1000];

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
		//printf("%c", temporary);//�Զ�ȡ���ַ��������
		//�ж��Ƿ�Ϊ�ո�
		if (temporary == 32){
			SPA_number++;
			//������
			all_words[TotalWords] = temporary;
			TotalWords++;
			continue;
		}
		//�ж��Ƿ�Ϊ���ģ�C���Դ�������ʱ��GBK���ת��Ϊ������Ȼ����unsigned����Ϊ����127�ı���
		if ((unsigned char) temporary > 127) {
			cn_words[CN_number] = temporary;
			CN_number++;
			//������
			all_words[TotalWords] = temporary;
			TotalWords++;
			continue;
		}
		//�ж�����
		if (temporary >= 48&&temporary<=57 ) {
			num_words[NUM_number] = temporary;
			NUM_number++;
			//������
			all_words[TotalWords] = temporary;
			TotalWords++;
		}
		//�ж�Ӣ�ģ���Ϊa-z��A-Z
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90)){
			en_words[EN_number] = temporary;
			EN_number++;
			//������
			all_words[TotalWords] = temporary;
			TotalWords++;
		}

	}

	printf("\n");
	printf("��������%d\n%s\n", TotalWords,all_words);
	printf("����������%d\n%s\n", CN_number / 2,cn_words);
	printf("Ӣ��������%d\n%s\n", EN_number,en_words);
	printf("����������%d\n%s\n", NUM_number,num_words);
	printf("�ո�������%d\n", SPA_number);

	return 0;
}


