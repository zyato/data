#include<stdio.h>
void hanoi(int len, char A, char B, char C) {//��len�����ӣ���A����B�ƶ���C
	if (1 == len) {
		printf("��%d������ֱ�Ӵ�%c�ƶ���%c\n", len, A, C);
	}
	else {
		hanoi(len - 1, A, C, B);
		printf("��%d������ֱ�Ӵ�%c�ƶ���%c\n", len, A, C);
		hanoi(len - 1, B, A, C);
	}
}
int main(void) {
	//char ch1 = 'A';
//	char ch2 = 'B';
	//char ch3 = 'C';
	int len;
	printf("��������Ҫ�ƶ����ӵĸ�����");
	scanf_s("%d", &len);
	hanoi(len, 'A', 'B', 'C');

	return 0;
}
