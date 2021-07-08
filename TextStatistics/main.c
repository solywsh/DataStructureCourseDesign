#include <stdio.h>

#define MaxSize 1000
typedef char DataType;
#include "SeqList.h"
//文本处理头文件
#include "r.h"

int main(void) {
	//创建顺序表
	SeqList myList;
	//创建用于存储文本统计信息的结构体
	TextInformation tl;

	//测试用
	//char *word = "一个幽灵，共产主义的幽灵，在欧洲游荡。为了对这个幽灵进行神圣的围剿，旧欧洲的一切势力，教皇和沙皇、梅特涅和基佐、法国的激进派和德国的警察，都联合起来了。A ghost, the ghost of communism, wanders Europe. In order to carry out a sacred encirclement and suppression of this ghost, all the powers of old Europe, the Pope and the Tsar, Metternich and Kizo, the French radicals and the German police, united.";
	char word[MaxSize]="\0";
	printf("请输入一段文字：");
	gets(word);

	//初始化并把字符串传入顺序表
	ListInitiate(&myList);
	for (int i = 0; word[i] != '\0'; ++i) {
		ListInsert(&myList, i, word[i]);
	}

	//对文本进行检查
	TextCheck(myList,&tl);
	//打印
	TextPrint(tl);

	return 0;
}


