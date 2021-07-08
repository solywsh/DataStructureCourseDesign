#pragma once
#include <stdio.h>
#include "SeqList.h"
#include <string.h>

typedef struct {
	int ALL_number, CN_number, EN_number, NUM_number, SPA_number;
	char all_words[100], cn_words[100], en_words[100], num_words[1000];
} TextInformation;

//初始化
void TextInformationInitiate(TextInformation *tl_) {

	tl_->ALL_number = 0;
	tl_->CN_number = 0;
	tl_->EN_number = 0;
	tl_->NUM_number = 0;
	tl_->SPA_number = 0;

	strcpy(tl_->all_words,"\0");
	strcpy(tl_->cn_words,"\0");
	strcpy(tl_->en_words,"\0");
	strcpy(tl_->num_words,"\0");

}


void TextCheck(SeqList myList_, TextInformation *tl_) {
	//初始化
	TextInformationInitiate(tl_);
	//定义一个临时变量
	char temporary;
	//get顺序表的内容，对每个字符进行检查
	for (int i = 0; i < ListLength(myList_); i++) {
		ListGet(myList_, i, &temporary);
		//printf("%c", temporary);//对读取的字符进行输出
		//判断是否为空格
		if (temporary == 32) {
			tl_->SPA_number++;
			//总字数
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
		//判断是否为中文，C语言处理中文时，GBK码会转化为负数，然后用unsigned处理为超过127的编码
		if ((unsigned char) temporary > 127) {
			tl_->cn_words[tl_->CN_number] = temporary;
			tl_->CN_number++;
			//总字数
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
		//判断数字
		if (temporary >= 48 && temporary <= 57) {
			tl_->num_words[tl_->NUM_number] = temporary;
			tl_->NUM_number++;
			//总字数
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
		//判断英文，分为a-z，A-Z
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90)) {
			tl_->en_words[tl_->EN_number] = temporary;
			tl_->EN_number++;
			//总字数
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
	}

	//对字符串添加结束符号，以防止出现有未初始化的内存导致末尾有乱码的情况
	tl_->all_words[tl_->ALL_number] = '\0';
	tl_->cn_words[tl_->CN_number] = '\0';
	tl_->en_words[tl_->EN_number] = '\0';
	tl_->num_words[tl_->NUM_number] = '\0';

}

void TextPrint(TextInformation tl_){

	printf("\n");
	printf("总字数：%d\n%s\n", tl_.ALL_number, tl_.all_words);
	printf("中文字数：%d\n%s\n", tl_.CN_number / 2, tl_.cn_words);
	printf("英文字数：%d\n%s\n", tl_.EN_number, tl_.en_words);
	printf("数字字数：%d\n%s\n", tl_.NUM_number, tl_.num_words);
	printf("空格字数：%d\n", tl_.SPA_number);

}
