#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node * pNext;
}NODE, *PNODE;
PNODE creatList();
void traverseList(PNODE);
void sortList(PNODE);
int lengthList(PNODE pHead);
int main(void) {

	PNODE pHead;
	pHead = creatList();
	traverseList(pHead);
	cout << "总长度：" << lengthList(pHead) << endl;
	sortList(pHead);
	traverseList(pHead);
	return 0;
}
int lengthList(PNODE pHead) {
	int len = 0;
	while (pHead->pNext != NULL)
	{
		len++;
		pHead = pHead->pNext;
	}
	return len;
}
void sortList(PNODE pHead) {
	/*PNODE p = pHead->pNext;//p指向首节点
	PNODE q = p->pNext;//q指向第二个节点
	while (q != NULL) {
		while (q != NULL) {
			if (p->data > q->data) {
				int temp;
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			p = p->pNext;
			q = q->pNext;
		}
		p = pHead->pNext;
		//q =q->pNext;
	}*/
	int i,j;
	PNODE p;
	PNODE q;
	for (i = 0; i < lengthList(pHead)-1; ++i) {
		for (j = 0, p = pHead->pNext, q=p->pNext; j < lengthList(pHead)-i-1; ++j, p = p->pNext, q=q->pNext) {
			if (p->data > q->data) {
				int t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
}
void traverseList(PNODE pHead) {
	PNODE p = pHead->pNext;
	while (NULL != p) {
		cout << p->data << endl;
		p = p->pNext;
	}

}
PNODE creatList() {
	int len, temp;
	cout << "请输入节点个数：" << endl;
	cin >> len;
	PNODE pHead = (PNODE)new NODE;
	if (pHead == NULL) {
		cout << "创建失败，程序退出！" << endl;
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;
	for (int i = 0; i < len; ++i) {
		cout << "请输入第" << i + 1 << "个节点的值：";
		cin >> temp;
		PNODE pNew = (PNODE)new NODE;
		if (pNew->pNext == NULL) {
			cout << "分配失败，程序退出！" << endl;
			exit(-1);
		}
		pNew->data = temp;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}
	return pHead;
}