#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {//链表的定义
	int data;
	struct ListNode * pNext;
}NODE, *PNODE;
PNODE creat_list_node();/*创建一个链表*/
void traverse_list(PNODE pHead);//遍历链表
bool is_empty_list(PNODE);///判断链表是否为空
int length_list(PNODE);////获取链表的有效长度
void sort_list(PNODE pHead);
bool delete_list(PNODE pHead, int pos, int tem);
bool insert_list(PNODE pHead, int pos, int val);
int main(void) {

	PNODE pHead = NULL;
	pHead = creat_list_node();
	printf("排序前的链表：\n");
	traverse_list(pHead);
	if (is_empty_list(pHead))
		printf("链表为空！\n");
	else
		printf("链表不为空！\n");
	printf("链表的长度是：%d\n", length_list(pHead));
	printf("排序后的链表：\n");
	sort_list(pHead);
	traverse_list(pHead);
	int p = 0;
	delete_list(pHead, 3, p);
	traverse_list(pHead);
	insert_list(pHead, 1, 5);
	traverse_list(pHead);

	return 0;
}
bool delete_list(PNODE pHead, int pos, int tem) {
	int i = 0;
	PNODE p = pHead;
	while (NULL != p->pNext && i < pos - 1) {
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p->pNext)
		return false;
	PNODE t = p->pNext;
	p->pNext = p->pNext->pNext;
	tem = t->data;
	printf("删除的是：%d\n", tem);
	free(t);
	return true;
}
bool insert_list(PNODE pHead, int pos, int val) {
	int i = 0;
	PNODE p = pHead;
	while (NULL != p && i < pos - 1) {
		p = p->pNext;
		++i;
	}
	if (i > pos - 1 || NULL == p)
		return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	//判断是否分配成功！
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
void sort_list(PNODE pHead) {//超级小白的排序算法
	/*第一种（忘了叫什么排序）
	PNODE p ;
	PNODE q ;
	int i, j, t;
	int len = length_list(pHead);
	for(i = 0, p=pHead->pNext; i < len - 1; ++i,p=p->pNext ){
		//p = p->pNext;
		for (j = i+1, q=p->pNext; j < len; ++j, q=q->pNext) {

			if (p->data > q->data) {
				t = p->data;
				p->data = q->data;
				q->data = t ;
			}
		}
	}*/
	//第二种（冒泡排序）
/*	PNODE p, q;
	int i, j, t;
	int len = length_list(pHead);
	for (i = 0; i < len - 1; ++i) {
		for (j = 0, p=pHead->pNext, q=p->pNext; j < len - i - 1; ++j, p=p->pNext, q=q->pNext) {
			if (p->data>q->data) {
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}*/
	//正宗的冒泡泡！
	PNODE p, q;
	q = pHead;
	p = pHead->pNext;
	while (q->pNext != NULL) {
		while (p->pNext != NULL) {
			if (p->data > p->pNext->data) {
				int temp = p->data;
				p->data = p->pNext->data;
				p->pNext->data = temp;
			}
			p = p->pNext;
		}
		q = q->pNext;
		p = pHead->pNext;
	}
}
bool is_empty_list(PNODE pHead) {
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
}
PNODE creat_list_node() {
	int i, len, temp;
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead) {
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("请输入链表节点的个数：");
	scanf_s("%d", &len);
	for (i = 0; i < len; ++i) {
		printf("请输入第%d个节点数据域的值：", i + 1);
		scanf_s("%d", &temp);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data = temp;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}
void traverse_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
	return;
}
int length_list(PNODE pHead) {
	PNODE p = pHead->pNext;
	int count=0;
	while (NULL != p)
	{
		count++;
		p = p->pNext;
	}
	return count;
}