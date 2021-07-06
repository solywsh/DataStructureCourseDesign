#include <stdio.h>

#define MaxSize 1000
typedef char DataType;

#include "SeqList.h"


int main(void) {

	SeqList myList;
	//测试用
	//char *word = "一个幽灵，共产主义的幽灵，在欧洲游荡。为了对这个幽灵进行神圣的围剿，旧欧洲的一切势力，教皇和沙皇、梅特涅和基佐、法国的激进派和德国的警察，都联合起来了。";
	char word[MaxSize]="\0";
	int TotalWords = 0, CN_number = 0, EN_number = 0, NUM_number = 0, SPA_number = 0;

	printf("请输入一段文字：");
	gets(word);

	//初始化并把字符串传入顺序表
	ListInitiate(&myList);
	for (int i = 0; word[i] != '\0'; ++i) {
		ListInsert(&myList, i, word[i]);
	}
	printf("\n");

	char temporary;//定义一个临时变量
	//get顺序表的内容，对每个字符进行检查
	for (int i = 0; i < ListLength(myList); i++) {
		ListGet(myList, i, &temporary);
		printf("%c", temporary);//对读取的字符进行输出
		//判断是否为空格
		if (temporary == 32)SPA_number++;
		//判断是否为中文，C语言处理中文时，GBK码会转化为负数，然后用unsigned处理为超过127的编码
		if ((unsigned char) temporary > 127) CN_number++;
		//判断数字
		if (temporary >= 48&&temporary<=57 ) NUM_number++;
		//判断英文，分为a-z，A-Z
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90))EN_number++;
		//总字数
		TotalWords++;
	}

	printf("\n");
	printf("总字数：%d\n", TotalWords);
	printf("中文字数：%d\n", CN_number / 2);
	printf("英文字数：%d\n", EN_number);
	printf("数字字数：%d\n", NUM_number);
	printf("空格字数：%d\n", SPA_number);
	return 0;

}


