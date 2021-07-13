#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"
//�ı�����ͷ�ļ�
#include "r.h"

int main(void) {
	int flag = -1;
	//����˳���
	SeqList myList;
	//�������ڴ洢�ı�ͳ����Ϣ�Ľṹ��
	TextInformation tl;
	char word[MaxSize];

	while (1)
	{
		int choice;
		system("cls");
		printf("================================================================================\n");
		printf("                                 ����ͳ�Ʒ���\n");
		printf("================================================================================\n");
		printf("\n");
		printf("                                 1.��������\n");
		printf("                                 2.�������Ա�\n");
		printf("                                 3.ͳ��������Ϣ\n");
		printf("                                 4.��ӡ������Ϣ\n");
		printf("                                 5.�˳�\n");
		printf("\n");
		printf("================================================================================\n");
		printf("================================================================================\n");
		printf("��ѡ���Ӧ����:");
		scanf("%d", &choice);
		getchar();
		while (choice < 1 || choice >5) {
			printf("�������ֲ���ȷ������������1-5:");
			scanf("%d", &choice);
		}

		switch (choice) {
		case 1:
			//��ʼ��word,Ȼ�����븳ֵ
			strcpy(word, "\0");
			printf("������һ�����֣�");
			gets(word);
			flag = 0;
			system("pause");//ͣ��
			break;
		case 2:
			//��ʼ�������ַ�������˳���
			if (flag != 0) {
				printf("û���������ֻ����Ѿ�����˳���!\n");
				system("pause");//ͣ��
				break;
			}

			ListInitiate(&myList);
			for (int i = 0; word[i] != '\0'; ++i) {
				ListInsert(&myList, i, word[i]);
			}
			printf("�ַ��������Ա�ɹ�!\n");
			flag = 1;
			system("pause");//ͣ��
			break;
		case 3:
			//���ı����м��
			if (flag != 1) {
				printf("��û�д������Ա�����Ѿ����ı����м��!\n");
				system("pause");//ͣ��
				break;
			}
			TextCheck(myList, &tl);
			printf("�ı����ɹ�!\n");
			flag = 2;
			system("pause");
			break;
		case 4:
			//��ӡ
			if (flag != 2) {
				printf("û�н����ı����!\n");
				system("pause");
				break;
			}
			TextPrint(tl);
			system("pause");
			break;
		default:
			return 0;
		}
	}
}


