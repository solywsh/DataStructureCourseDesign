#pragma once
#include <string.h>
#include <stdio.h>
#include "LinList.h"

//���в�����������h1,h2_��h3���ڴ���
int Union(SLNode* h1_, SLNode* h2_, SLNode* h3_) {
	//����洢���������ȵı���
	int h1_length, h2_length, h3_length = 0;
	int flag = 0;//�����־����������Ƿ��Ѿ�����h3
	//�õ���������ĳ���
	h1_length = ListLength(h1_);
	h2_length = ListLength(h2_);

	//����������ʱ����
	DataType temporary, temporary_;
	//�Ƚ�h1��ֵ��h3
	for (int i = 0; i < h1_length; ++i) {
		flag = 0;
		//�õ�h1����Ԫ��
		ListGet(h1_, i, &temporary);
		//�����Ӣ�Ĳ���Сд������в�������
		if (temporary >= 97 && temporary <= 122) {
			for (int j = 0; j < h3_length; ++j) {
				ListGet(h3_, j, &temporary_);
				if (temporary == temporary_) {
					//��鵽����ͬ�ģ�ֱ������
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				ListInsert(h3_, h3_length, temporary);
				h3_length++;
			}
		}
	}

	//��h2��ֵ��h3
	for (int i = 0; i < h2_length; ++i) {
		flag = 0;
		//�õ�h1����Ԫ��
		ListGet(h2_, i, &temporary);
		//�����Ӣ�Ĳ���Сд������в�������
		if (temporary >= 97 && temporary <= 122) {
			for (int j = 0; j < h3_length; ++j) {
				ListGet(h3_, j, &temporary_);
				if (temporary == temporary_) {
					//��鵽����ͬ�ģ�ֱ������
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				ListInsert(h3_, h3_length, temporary);
				h3_length++;
			}
		}
	}

	return h3_length;
}

//�󽻼�
int Intersection(SLNode* h1_, SLNode* h2_, SLNode* h3_) {
	//����洢���������ȵı���
	int h1_length, h2_length, h3_length = 0;
	int flag = 0;//�����־����������Ƿ��Ѿ�����h3
	//�õ���������ĳ���
	h1_length = ListLength(h1_);
	h2_length = ListLength(h2_);

	//������ʱ����
	DataType temporary_1, temporary_2, temporary_3;

	for (int i = 0; i < h1_length; ++i) {
		flag = 0;
		//ȡh1��һ������
		ListGet(h1_, i, &temporary_1);

		for (int j = 0; j < h2_length; ++j) {
			//ȡh2��һ������
			ListGet(h2_, j, &temporary_2);
			//�������������ȣ�����Ϊ**Сд��ĸ**
			if (temporary_1 == temporary_2 && temporary_1 >= 97 && temporary_1 <= 122) {
				//���h3����Ƿ��Ѿ�����
				for (int k = 0; k < h3_length; ++k) {
					ListGet(h3_, k, &temporary_3);
					//�����һ���ģ���flag=1
					if (temporary_1 == temporary_3) {
						flag = 1;
					}
				}
				//���h3���û�д��ڣ�����h3����temporary_1
				if (flag == 0) {
					ListInsert(h3_, h3_length, temporary_1);
					h3_length++;
				}
			}
		}
	}
	return h3_length;
}


//��
int Subtraction(SLNode* h1_, SLNode* h2_, SLNode* h3_) {
	//����洢���������ȵı���
	int h1_length, h2_length, h3_length = 0;
	int flag = 0, flag_ = 0;//�����־����������Ƿ��Ѿ�����h3
	//�õ���������ĳ���
	h1_length = ListLength(h1_);
	h2_length = ListLength(h2_);

	//������ʱ����
	DataType temporary_1, temporary_2, temporary_3;
	//�Ƚ�h1��ֵ��h3
	for (int i = 0; i < h1_length; ++i) {
		flag = 0;
		flag_ = 0;
		//ȡh1��һ������
		ListGet(h1_, i, &temporary_1);
		for (int j = 0; j < h2_length; ++j) {
			//ȡh2��һ������
			ListGet(h2_, j, &temporary_2);
			//�������������ȵģ�����flag=1
			if (temporary_1 == temporary_2) {
				flag = 1;
			}
		}
		if (flag == 0) {
			//���������h1�еĵ���h2û�еģ����h3�Ƿ��Ѿ��������Ԫ��
			for (int j = 0; j < h3_length; ++j) {
				ListGet(h3_, j, &temporary_3);
				if (temporary_3 == temporary_1)flag_ = 1;
			}
			if (flag_ == 0) {
				ListInsert(h3_, h3_length, temporary_1);
				h3_length++;
			}
		}
	}
	return h3_length;
}

//����
void Sort(SLNode* h_) {
	int h_length, i;
	h_length = ListLength(h_);
	char temporary, word[100];

	//�Ƚ�������Ϣ��������
	for (i = 0; i < h_length; ++i) {
		ListGet(h_, i, &temporary);
		word[i] = temporary;
	}

	char temp;//������ʱ����
	//����ð������
	for (i = 0; i < h_length; ++i) {
		// ֮ǰ��ѭ���Ѿ���i��Ԫ���͵�ĩβ������Ҫ�ٴαȽϣ��ʼ�ȥ����Ϊ����һ��Ԫ�رȽϣ�Ϊ�˱���������ʼ�һ
		for (int j = 0; j < h_length - i - 1; ++j) {
			// �����ǰ��Ԫ�رȺ�һ��Ԫ��С���ͽ���
			if (word[j] > word[j + 1]) {
				temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
		}
	}

	//�ٽ�����word�����ݴ������Ա�
	for (int j = 0; j < h_length; ++j) {
		ListInsert(h_, j, word[j]);
	}
}

void print_node(SLNode h_, int count_) {
	char temporary_;
	for (int i = 0; i < count_; ++i) {
		ListGet(&h_, i, &temporary_);
		printf("%c", temporary_);
	}
	printf("\n");
}