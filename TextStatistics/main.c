#include <stdio.h>

#define MaxSize 1000
typedef char DataType;

#include "SeqList.h"


int main(void) {

	SeqList myList;
	char *word = "dasjdg123usaig按gdyag的  规定UI  啊公司概述a312312gfduiagdi  奥数的挂饰规定UI啊上单ydg2132189361 ";
	int TotalWords = 0, CN_number = 0, EN_number = 0, NUM_number = 0, SPA_number = 0;

//	printf("请输入一段文字：");
//	scanf("%s",word);

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
		printf("%c", temporary);

		if (temporary == 32)SPA_number++;
		if ((unsigned char) temporary > 127) CN_number++;
		if (temporary >= 48&&temporary<=57 ) NUM_number++;
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90))EN_number++;
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


