#include<stdio.h>
void hanoi(int len, char A, char B, char C) {//把len个盘子，从A借助B移动到C
	if (1 == len) {
		printf("把%d号盘子直接从%c移动到%c\n", len, A, C);
	}
	else {
		hanoi(len - 1, A, C, B);
		printf("把%d号盘子直接从%c移动到%c\n", len, A, C);
		hanoi(len - 1, B, A, C);
	}
}
int main(void) {
	//char ch1 = 'A';
//	char ch2 = 'B';
	//char ch3 = 'C';
	int len;
	printf("请输入需要移动盘子的个数：");
	scanf_s("%d", &len);
	hanoi(len, 'A', 'B', 'C');

	return 0;
}
