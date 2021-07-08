#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"
//文本处理头文件
#include "r.h"

int main(void) {
	int flag = 1;
	//创建顺序表
	SeqList myList;
	//创建用于存储文本统计信息的结构体
	TextInformation tl;
	char word[MaxSize] = "\0";

	while (flag) {
		//初始化界面
		system("cls");

		//初始化word,然后输入赋值
		strcpy(word,"\0");

		printf("请输入一段文字：");
		gets(word);

		//初始化并把字符串传入顺序表
		ListInitiate(&myList);
		for (int i = 0; word[i] != '\0'; ++i) {
			ListInsert(&myList, i, word[i]);
		}

		//对文本进行检查
		TextCheck(myList, &tl);
		//打印
		TextPrint(tl);

		printf("\n是否继续?(1.继续;2.退出):");
		scanf("%d", &flag);
		if (flag==2){
			return 0;
		} else flag = 1;

		//吸收回车
		getchar();
		//system("pause");
	}
}


