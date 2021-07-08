#pragma once
#include <stdio.h>
#include "SeqList.h"
#include <string.h>

typedef struct {
	int ALL_number, CN_number, EN_number, NUM_number, SPA_number;
	char all_words[100], cn_words[100], en_words[100], num_words[1000];
} TextInformation;

//��ʼ��
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
	//��ʼ��
	TextInformationInitiate(tl_);
	//����һ����ʱ����
	char temporary;
	//get˳�������ݣ���ÿ���ַ����м��
	for (int i = 0; i < ListLength(myList_); i++) {
		ListGet(myList_, i, &temporary);
		//printf("%c", temporary);//�Զ�ȡ���ַ��������
		//�ж��Ƿ�Ϊ�ո�
		if (temporary == 32) {
			tl_->SPA_number++;
			//������
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
		//�ж��Ƿ�Ϊ���ģ�C���Դ�������ʱ��GBK���ת��Ϊ������Ȼ����unsigned����Ϊ����127�ı���
		if ((unsigned char) temporary > 127) {
			tl_->cn_words[tl_->CN_number] = temporary;
			tl_->CN_number++;
			//������
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
		//�ж�����
		if (temporary >= 48 && temporary <= 57) {
			tl_->num_words[tl_->NUM_number] = temporary;
			tl_->NUM_number++;
			//������
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
		//�ж�Ӣ�ģ���Ϊa-z��A-Z
		if ((temporary >= 97 && temporary <= 122) || (temporary >= 65 && temporary <= 90)) {
			tl_->en_words[tl_->EN_number] = temporary;
			tl_->EN_number++;
			//������
			tl_->all_words[tl_->ALL_number] = temporary;
			tl_->ALL_number++;
			continue;
		}
	}

	//���ַ�����ӽ������ţ��Է�ֹ������δ��ʼ�����ڴ浼��ĩβ����������
	tl_->all_words[tl_->ALL_number] = '\0';
	tl_->cn_words[tl_->CN_number] = '\0';
	tl_->en_words[tl_->EN_number] = '\0';
	tl_->num_words[tl_->NUM_number] = '\0';

}

void TextPrint(TextInformation tl_){

	printf("\n");
	printf("��������%d\n%s\n", tl_.ALL_number, tl_.all_words);
	printf("����������%d\n%s\n", tl_.CN_number / 2, tl_.cn_words);
	printf("Ӣ��������%d\n%s\n", tl_.EN_number, tl_.en_words);
	printf("����������%d\n%s\n", tl_.NUM_number, tl_.num_words);
	printf("�ո�������%d\n", tl_.SPA_number);

}
