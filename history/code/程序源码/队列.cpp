#include<stdio.h>
#include<stdlib.h>
static int len;
typedef struct queue {
	int * pBase;
	int front;
	int rear;
}QUEUE;
void init_queue(QUEUE *);///初始化
bool empty_queue(QUEUE *);
bool full_queue(QUEUE *);
bool in_queue(QUEUE *, int);
bool out_queue(QUEUE *, int *);
void traverse_queue(QUEUE *);


int main() {
	QUEUE Q;
	int val;
	//init_queue(&Q);
	//traverse_queue(&Q);
	//out_queue(&Q, &val);
//	in_queue(&Q, 1);	in_queue(&Q, 2);	in_queue(&Q, 3);	in_queue(&Q, 4);
//	in_queue(&Q, 5);	in_queue(&Q, 6);	in_queue(&Q, 7);	in_queue(&Q, 8);
//	out_queue(&Q, &val); 
//	traverse_queue(&Q);

	return 0;
}
void traverse_queue(QUEUE *pQ) {
	int t = pQ->front;
	while (t != pQ->rear) {
		printf("%d  ", pQ->pBase[t]);
		t = (t + 1) % (len + 1);
	}
	return;
}
void init_queue(QUEUE * pQ) {
	printf("请确定队列最大容纳量：");
	scanf_s("%d", &len);
	pQ->pBase = (int *)malloc(sizeof(int)*(len + 1));
	pQ->front = pQ->rear = 0;
}
bool in_queue(QUEUE * pQ, int val) {
	if (full_queue(pQ)) {
		printf("队列已满！\n");
		return false;
	}
	pQ->pBase[pQ->rear] = val;
	pQ->rear = (pQ->rear + 1) % (len + 1);
	return true;
}
bool out_queue(QUEUE * pQ, int * val) {
	if (empty_queue(pQ)) {
		printf("队列为空！\n");
		return false;
	}
	
	*val = pQ->front;
	pQ->front = (pQ->front + 1) % (len + 1);
	return true;
}
bool empty_queue(QUEUE *pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
bool full_queue(QUEUE * pQ) {
	if ((pQ->rear + 1) % (len + 1) == pQ->front)
		return true;
	else
		return false;
}