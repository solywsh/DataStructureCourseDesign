#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"
//�ı�����ͷ�ļ�
#include "r.h"

int main(void) {
	int flag = 1;
	//����˳���
	SeqList myList;
	//�������ڴ洢�ı�ͳ����Ϣ�Ľṹ��
	TextInformation tl;
	char word[MaxSize] = "\0";

	while (flag) {
		//��ʼ������
		system("cls");

		//��ʼ��word,Ȼ�����븳ֵ
		strcpy(word,"\0");

		printf("������һ�����֣�");
		gets(word);

		//��ʼ�������ַ�������˳���
		ListInitiate(&myList);
		for (int i = 0; word[i] != '\0'; ++i) {
			ListInsert(&myList, i, word[i]);
		}

		//���ı����м��
		TextCheck(myList, &tl);
		//��ӡ
		TextPrint(tl);

		printf("\n�Ƿ����?(1.����;2.�˳�):");
		scanf("%d", &flag);
		if (flag==2){
			return 0;
		} else flag = 1;

		//���ջس�
		getchar();
		//system("pause");
	}
}


