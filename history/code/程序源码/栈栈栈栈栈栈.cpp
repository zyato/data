#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
	int data;
	struct NODE * pNext;
}NODE , *PNODE;
typedef struct STACK {
	PNODE pTop;
	PNODE pBOTTOM;
}STACK, *PSTACK;
void initStack(PSTACK ps);
bool traverseStack(PSTACK ps);
void pushStack(PSTACK ps, int a);
bool isEmpty(PSTACK ps);
void popStack(PSTACK ps, int *p);
void popStack(PSTACK ps);//出战函数重载
void clear(PSTACK ps);
int main(void) {

	STACK S;
	int val = 0;
	initStack(&S);
	traverseStack(&S);
	pushStack(&S, 1);
	pushStack(&S, 2);
	pushStack(&S,3);
	pushStack(&S, 4);
	pushStack(&S, 5);
	traverseStack(&S);
	popStack(&S, &val);
	printf("%d出栈\n", val);
	traverseStack(&S);
	clear(&S);
	traverseStack(&S);
	return 0;
}
void clear(PSTACK ps) {
	if (isEmpty(ps))
		return;
	while (ps->pBOTTOM != ps->pTop) {
		popStack(ps);
	}
}
void popStack(PSTACK ps, int *p) {
	PNODE t = ps->pTop;
	ps->pTop = t->pNext;
	*p = t->data;
	free(t);
	t = NULL;
}
void popStack(PSTACK ps) {
	PNODE t = ps->pTop;
	ps->pTop = t->pNext;
	free(t);
	t = NULL;
}
void pushStack(PSTACK ps, int val) {
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = ps->pTop;
	ps->pTop = pNew;
}
void initStack(PSTACK ps) {
	ps->pBOTTOM = (PNODE)malloc(sizeof(NODE));
	if (ps->pBOTTOM == NULL)
	{
		printf("创建失败， 程序终止！\n");
		exit(-1);
	}
	ps->pTop = ps->pBOTTOM;
}
bool isEmpty(PSTACK ps) {
	if (ps->pBOTTOM == ps->pTop)
		return true;
	else
		return false;
}
bool traverseStack(PSTACK ps) {
	if (isEmpty(ps)) {
		printf("栈为空！\n");
		return false;

	}
		
	PNODE p = ps->pTop;
	while (p != ps->pBOTTOM) {
		printf("%d  ", p->data);
		p = p->pNext;
	}
	printf("\n");
}