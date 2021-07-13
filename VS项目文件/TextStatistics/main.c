#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"
//文本处理头文件
#include "r.h"

int main(void) {
	int flag = -1;
	//创建顺序表
	SeqList myList;
	//创建用于存储文本统计信息的结构体
	TextInformation tl;
	char word[MaxSize];

	while (1)
	{
		int choice;
		system("cls");
		printf("================================================================================\n");
		printf("                                 文字统计分析\n");
		printf("================================================================================\n");
		printf("\n");
		printf("                                 1.输入文字\n");
		printf("                                 2.存入线性表\n");
		printf("                                 3.统计文字信息\n");
		printf("                                 4.打印文字信息\n");
		printf("                                 5.退出\n");
		printf("\n");
		printf("================================================================================\n");
		printf("================================================================================\n");
		printf("请选择对应功能:");
		scanf("%d", &choice);
		getchar();
		while (choice < 1 || choice >5) {
			printf("输入数字不正确，请重新输入1-5:");
			scanf("%d", &choice);
		}

		switch (choice) {
		case 1:
			//初始化word,然后输入赋值
			strcpy(word, "\0");
			printf("请输入一段文字：");
			gets(word);
			flag = 0;
			system("pause");//停顿
			break;
		case 2:
			//初始化并把字符串传入顺序表
			if (flag != 0) {
				printf("没有输入文字或者已经存入顺序表!\n");
				system("pause");//停顿
				break;
			}

			ListInitiate(&myList);
			for (int i = 0; word[i] != '\0'; ++i) {
				ListInsert(&myList, i, word[i]);
			}
			printf("字符存入线性表成功!\n");
			flag = 1;
			system("pause");//停顿
			break;
		case 3:
			//对文本进行检查
			if (flag != 1) {
				printf("还没有存入线性表或者已经对文本进行检查!\n");
				system("pause");//停顿
				break;
			}
			TextCheck(myList, &tl);
			printf("文本检查成功!\n");
			flag = 2;
			system("pause");
			break;
		case 4:
			//打印
			if (flag != 2) {
				printf("没有进行文本检查!\n");
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


