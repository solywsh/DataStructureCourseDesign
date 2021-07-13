#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef char DataType;

#include "CollectionProcessing.h"
#include "LinList.h"

int main() {
	int count = 0;//记录数字的
	//char Set1[] ="012oper4a6tion",Set2[] = "error data";
	char Set1[] = "magazine", Set2[] = "paper";
	SLNode *h1, *h2, *h3;
	ListInitiate(&h1);
	ListInitiate(&h2);
	ListInitiate(&h3);
	//把字符插入到链表
	for (int i = 0; i < strlen(Set1); ++i) {
		ListInsert(h1, i, Set1[i]);
	}
	for (int i = 0; i < strlen(Set2); ++i) {
		ListInsert(h2, i, Set2[i]);
	}

	//求并集
	ListInitiate(&h3);
	count = Union(h1, h2, h3);
	Sort(h3);//排序
	printf("\n并集之后字符数：%d\n", count);
	print_node(*h3, count);

	//求交集
	ListInitiate(&h3);
	count = Intersection(h1, h2, h3);
	Sort(h3);//排序
	printf("\n交集之后字符数：%d\n", count);
	print_node(*h3, count);



	//求差集
	ListInitiate(&h3);
	count = Subtraction(h1, h2, h3);
	Sort(h3);//排序
	printf("\n差集之后字符数：%d\n", count);
	print_node(*h3, count);



	//撤销单链表，对内存清理
	Destroy(&h1);
	Destroy(&h2);
	Destroy(&h3);

}