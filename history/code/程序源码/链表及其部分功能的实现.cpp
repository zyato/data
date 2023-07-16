#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {//����Ķ���
	int data;
	struct ListNode * pNext;
}NODE, *PNODE;
PNODE creat_list_node();/*����һ������*/
void traverse_list(PNODE pHead);//��������
bool is_empty_list(PNODE);///�ж������Ƿ�Ϊ��
int length_list(PNODE);////��ȡ�������Ч����
void sort_list(PNODE pHead);
bool delete_list(PNODE pHead, int pos, int tem);
bool insert_list(PNODE pHead, int pos, int val);
int main(void) {

	PNODE pHead = NULL;
	pHead = creat_list_node();
	printf("����ǰ������\n");
	traverse_list(pHead);
	if (is_empty_list(pHead))
		printf("����Ϊ�գ�\n");
	else
		printf("����Ϊ�գ�\n");
	printf("����ĳ����ǣ�%d\n", length_list(pHead));
	printf("����������\n");
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
	printf("ɾ�����ǣ�%d\n", tem);
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
	//�ж��Ƿ����ɹ���
	pNew->data = val;
	pNew->pNext = p->pNext;
	p->pNext = pNew;
	return true;
}
void sort_list(PNODE pHead) {//����С�׵������㷨
	/*��һ�֣����˽�ʲô����
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
	//�ڶ��֣�ð������
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
	//���ڵ�ð���ݣ�
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
		printf("����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	printf("����������ڵ�ĸ�����");
	scanf_s("%d", &len);
	for (i = 0; i < len; ++i) {
		printf("�������%d���ڵ��������ֵ��", i + 1);
		scanf_s("%d", &temp);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew) {
			printf("����ʧ�ܣ�������ֹ��\n");
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