/*
ʱ	  �䣺2019��4��3�գ�22��26��
���ܣ�
Ŀ�ģ�
����������N����Χ��һȦ���ӵ�һ���˿�ʼ����������m���˳�Ȧ��ʣ�µ��˼�����1��ʼ����������m���˳�Ȧ��
		���������ֱ�������˳�Ȧ����ģ��˹��̣������Ȧ���˵���ţ�

*/
#include<iostream>
using namespace std;
int a(int n, int m) {
	if (n == 1)
		return 0;
	else
		return (a(n - 1, m) + m) % n;
}
int main() {
	int n;
	cin >> n;
	const int m = 3;
	cout << a(n, 3) + 1 << endl;;
	int s = 0;
	for (int i = 2; i <= n; ++i)
		s = (s + m) % i;
	cout << s + 1;

	return 0;
}
/*
��vs2017���������ǣ�

�ջ������㷨������
*/