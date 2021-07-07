#include <stdio.h>
#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"


int main(void) {

	SeqList myList;
	//测试用
	//char *word = "一个幽灵，共产主义的幽灵，在欧洲游荡。为了对这个幽灵进行神圣的围剿，旧欧洲的一切势力，教皇和沙皇、梅特涅和基佐、法国的激进派和德国的警察，都联合起来了。A ghost, the ghost of communism, wanders Europe. In order to carry out a sacred encirclement and suppression of this ghost, all the powers of old Europe, the Pope and the Tsar, Metternich and Kizo, the French radicals and the German police, united.";
	char word[MaxSize]="\0";
	int TotalWords = 0, CN_number = 0, EN_number = 0, NUM_number = 0, SPA_number = 0;
	char all_words[100], cn_words[100], en_words[100],num_words[1000];

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
		//printf("%c", temporary);//对读取的字符进行输出
		//判断是否为空格
		if (temporary == 32){
			SPA_number++;
			//总字数
			all_words[TotalWords] = temporary;
			TotalWords++;
			continue;
		}
		//判断是否为中文，C语言处理中文时，GBK码会转化为负数，然后用unsigned处理为超过127的编码
		if ((unsigned char) temporary > 127) {
			cn_words[CN_number] = temporary;
			CN_number++;
			//总字数
			all_words[TotalWords] = temporary;
			TotalWords++;
			continue;
		}
		//判断数字
		if (temporary >= 48&&temporary<=57 ) {
			num_words[NUM_number] = temporary;
			NUM_number++;
			//总字数
			all_words[TotalWords] = temporary;
			TotalWords++;
		}
		//判断英文，分为a-z，A-Z
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90)){
			en_words[EN_number] = temporary;
			EN_number++;
			//总字数
			all_words[TotalWords] = temporary;
			TotalWords++;
		}

	}

	printf("\n");
	printf("总字数：%d\n%s\n", TotalWords,all_words);
	printf("中文字数：%d\n%s\n", CN_number / 2,cn_words);
	printf("英文字数：%d\n%s\n", EN_number,en_words);
	printf("数字字数：%d\n%s\n", NUM_number,num_words);
	printf("空格字数：%d\n", SPA_number);

	return 0;
}


