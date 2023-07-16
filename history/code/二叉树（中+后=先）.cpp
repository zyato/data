#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
typedef char ElemType;
//声明二叉树结构体
typedef struct node
{
	ElemType data;
	struct node *lchild, *rchild;
}BitTree;

BitTree *createBinTreeByPostIn(char *post, char *in, int number)
{
	if (number == 0) return NULL;
	char c = post[number - 1];
	int i = 0;
	while (in[i] != c && i < number)i++;
	int leftNumber = i;
	int rightNumber = number - i - 1;
	BitTree *node = (BitTree *)malloc(sizeof(BitTree));
	node->data = c;
	node->lchild = createBinTreeByPostIn(&post[0], &in[0], leftNumber);
	node->rchild = createBinTreeByPostIn(&post[leftNumber], &in[i + 1], rightNumber);
	return node;
}

void PreOrder(BitTree *bt)
{
	if (bt != NULL)
	{
		printf("%c ", bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
int main(int argc, char **argv)
{
	char a[SIZE], b[SIZE];
	BitTree *p;
	while (scanf("%s%s", a, b) != EOF)
	{
		p = createBinTreeByPostIn(a, b, strlen(a));
		PreOrder(p);
		printf("\n");
	}
	return 0;
}