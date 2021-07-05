#include <stdio.h>
#include "r.h"

#define MaxSize 1000
typedef char DataType;

#include "SeqList.h"

char *r_chinese = "[\\u4e00-\\u9fa5]";//中文正则表达式
char *r_english = "[A-Za-z]";//英文正则表达式
char *r_number = "[0-9]";//数字正则表达式
char *r_space = "\\s";//空格正则表达式

int main(void) {
	SeqList myList;
	char word[1000] = "ahrfu32312 ihfu放  大时I12 23123312F好受很111 123212331多fo iu肺癌风还123是符号案发后啊擦拭好难看";
	int TotalWords = 0, CN_number = 0, EN_number = 0, NUM_number = 0, SPA_number = 0;

//	printf("请输入一段文字：");
//	scanf("%s",word);

	//初始化并把字符串传入顺序表
	ListInitiate(&myList);
	for (int i = 0; word[i] != '\0'; ++i) {
		ListInsert(&myList, i, word[i]);
	}

	char temporary;//定义一个临时变量
	//get顺序表的内容，对每个字符进行检查
	for (int i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &temporary);
		CN_number += r(&temporary, r_chinese);
		EN_number += r(&temporary, r_english);
		EN_number += r(&temporary, r_number);
		SPA_number += r(&temporary, r_space);
		TotalWords++;
	}
	printf("总字数：%d\n",TotalWords);
	printf("中文字数：%d\n",CN_number);
	printf("英文字数：%d",EN_number);
	printf("数字字数：%d",NUM_number);
	printf("空格字数：%d",CN_number);
}
