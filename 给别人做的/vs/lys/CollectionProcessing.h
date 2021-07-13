#pragma once
#include <string.h>
#include <stdio.h>
#include "LinList.h"

//进行并集操作传入h1,h2_。h3用于储存
int Union(SLNode* h1_, SLNode* h2_, SLNode* h3_) {
	//定义存储三个链表长度的变量
	int h1_length, h2_length, h3_length = 0;
	int flag = 0;//定义标志，用来检查是否已经存入h3
	//得到三个链表的长度
	h1_length = ListLength(h1_);
	h2_length = ListLength(h2_);

	//定义两个临时变量
	DataType temporary, temporary_;
	//先将h1赋值给h3
	for (int i = 0; i < h1_length; ++i) {
		flag = 0;
		//得到h1的子元素
		ListGet(h1_, i, &temporary);
		//如果是英文并且小写，则进行并集操作
		if (temporary >= 97 && temporary <= 122) {
			for (int j = 0; j < h3_length; ++j) {
				ListGet(h3_, j, &temporary_);
				if (temporary == temporary_) {
					//检查到有相同的，直接跳过
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

	//将h2赋值给h3
	for (int i = 0; i < h2_length; ++i) {
		flag = 0;
		//得到h1的子元素
		ListGet(h2_, i, &temporary);
		//如果是英文并且小写，则进行并集操作
		if (temporary >= 97 && temporary <= 122) {
			for (int j = 0; j < h3_length; ++j) {
				ListGet(h3_, j, &temporary_);
				if (temporary == temporary_) {
					//检查到有相同的，直接跳过
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

//求交集
int Intersection(SLNode* h1_, SLNode* h2_, SLNode* h3_) {
	//定义存储三个链表长度的变量
	int h1_length, h2_length, h3_length = 0;
	int flag = 0;//定义标志，用来检查是否已经存入h3
	//得到三个链表的长度
	h1_length = ListLength(h1_);
	h2_length = ListLength(h2_);

	//定义临时变量
	DataType temporary_1, temporary_2, temporary_3;

	for (int i = 0; i < h1_length; ++i) {
		flag = 0;
		//取h1的一个函数
		ListGet(h1_, i, &temporary_1);

		for (int j = 0; j < h2_length; ++j) {
			//取h2的一个函数
			ListGet(h2_, j, &temporary_2);
			//如果两个函数相等，并且为**小写字母**
			if (temporary_1 == temporary_2 && temporary_1 >= 97 && temporary_1 <= 122) {
				//检查h3里边是否已经存在
				for (int k = 0; k < h3_length; ++k) {
					ListGet(h3_, k, &temporary_3);
					//如果有一样的，令flag=1
					if (temporary_1 == temporary_3) {
						flag = 1;
					}
				}
				//如果h3里边没有存在，则往h3插入temporary_1
				if (flag == 0) {
					ListInsert(h3_, h3_length, temporary_1);
					h3_length++;
				}
			}
		}
	}
	return h3_length;
}


//求差集
int Subtraction(SLNode* h1_, SLNode* h2_, SLNode* h3_) {
	//定义存储三个链表长度的变量
	int h1_length, h2_length, h3_length = 0;
	int flag = 0, flag_ = 0;//定义标志，用来检查是否已经存入h3
	//得到三个链表的长度
	h1_length = ListLength(h1_);
	h2_length = ListLength(h2_);

	//定义临时变量
	DataType temporary_1, temporary_2, temporary_3;
	//先将h1赋值给h3
	for (int i = 0; i < h1_length; ++i) {
		flag = 0;
		flag_ = 0;
		//取h1的一个函数
		ListGet(h1_, i, &temporary_1);
		for (int j = 0; j < h2_length; ++j) {
			//取h2的一个函数
			ListGet(h2_, j, &temporary_2);
			//如果出现两个相等的，则标记flag=1
			if (temporary_1 == temporary_2) {
				flag = 1;
			}
		}
		if (flag == 0) {
			//如果出现了h1有的但是h2没有的，检查h3是否已经存入这个元素
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

//排序
void Sort(SLNode* h_) {
	int h_length, i;
	h_length = ListLength(h_);
	char temporary, word[100];

	//先将链表信息存入数组
	for (i = 0; i < h_length; ++i) {
		ListGet(h_, i, &temporary);
		word[i] = temporary;
	}

	char temp;//定义临时变量
	//进行冒泡排序
	for (i = 0; i < h_length; ++i) {
		// 之前的循环已经将i个元素送到末尾，不需要再次比较，故减去，因为跟后一个元素比较，为了避免溢出，故减一
		for (int j = 0; j < h_length - i - 1; ++j) {
			// 如果当前的元素比后一个元素小，就交换
			if (word[j] > word[j + 1]) {
				temp = word[j];
				word[j] = word[j + 1];
				word[j + 1] = temp;
			}
		}
	}

	//再将数组word的数据存入线性表
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