#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	double Pi = acos(-1);
	cout << Pi << endl;
	//1
	cout.width(10);cout << Pi << endl;//���ÿ��>=10��ǰ��ո���䣨Ĭ���Ҷ��룩  ����Ӱ�������������һ
										//�������������Ȼָ�Ĭ��ֵ��
	//2
	cout << setw(10) << Pi << endl;//�ȼ���cout.width(10) ����Ӱ�������������һ�������������Ȼָ�Ĭ��ֵ��
	//3
	cout.fill('*'); cout << setw(10) << Pi << endl;//���������š�������ʽѡ�����Ч�� ֱ�������ı䡿
	//4
	cout<< setfill('*') << setw(10) << Pi << endl; //�ȼ���3���˸�ʽѡ�����Ч�� ֱ�������ı䡿
	//5
	cout << setw(10) << setiosflags(ios_base::left)<< Pi << endl;
	cout << setw(10) << setprecision(2) << Pi << endl;
	return 0;
}

















/*#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int num = 1;
	int temp = 1;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp += (i + 1) * 2;
			num += temp;
		}
	}
	int **array = new int *[n];//����һ����ά����
	for (int i = 0; i < n; i++)
		array[i] = new int[n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			array[i][j] = 0;
	array[n / 2][n / 2] = 1;

	//Ϊ��ά���鸳ֵ
	int k;
	int t = 2;
	for (int i = 1; i <= n / 2 && t <= n * n; i++)
	{
		k = n / 2 + i - 1;
		int t1, t2, t3, t4;
		//��2*i
		for (t1 = 0; t1 < 2 * i; t1++) {
			array[k - t1][k + 1] = t++;
		}
		//��2*i
		for (t2 = 0; t2 < 2 * i; t2++) {
			array[k - t1 + 1][k - t2] = t++;
		}
		//��2*i
		for (t3 = 0; t3 < 2 * i; t3++) {
			array[k - t1 + t3 + 2][k - t2 + 1] = t++;
		}
		//��2*i--
		for (t4 = 0; t4 < 2 * i; t4++) {
			array[k + 1][k + t4 - t2 + 2] = t++;
		}
	}
	//��ӡ����
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}*/
	//cout << num;


	// �������� 
	/*for (int i = 0; i < n; ++i)
	{
		delete array[i];
	}
	delete[] array;
	return 0;
}*/
/*
#include<iostream>
#include<iomanip>
#include<algorithm>

#include<cstring>

#include<cstdio>

using namespace std;

int main()

{

	int n, i, j, k, cnt = 1, sum = 0, f, ff;

	int a[101][101];


	scanf_s("%d", &n);
	for (int c = 0; c < n; ++c) {
		for (int d = 0; d < n; ++d)
			a[c][d] = 0;
		cout << endl;
	}
	cout << endl;
	k = n * n; f = 0;

	j = i = n / 2; a[i][j] = cnt++;

	while (cnt <= k)

	{

		f += 2;//ÿ�μӴ�һȦ�ͼӴ�2

		j++;

		ff = f;

		//����ͼ��֪���ظ���·��

		while (ff--) {

			a[i][j] = cnt++;

			if (ff)i--;

		}
		for (int c = 0; c < n; ++c){
			for (int d = 0; d < n; ++d) 
				cout << setw(4) << a[c][d];
			cout << endl;
			}
		cout << endl;

		ff = f;

		j--;

		while (ff--) {

			a[i][j] = cnt++;

			if (ff)j--;

		}
		for (int c = 0; c < n; ++c) {
			for (int d = 0; d < n; ++d)
				cout << setw(4) << a[c][d];
			cout << endl;
		}
		cout << endl;

		ff = f;

		i++;

		while (ff--) {

			a[i][j] = cnt++;

			if (ff)i++;

		}
		for (int c = 0; c < n; ++c) {
			for (int d = 0; d < n; ++d)
				cout << setw(4) << a[c][d];
			cout << endl;
		}
		cout << endl;
		ff = f;

		j++;

		while (ff--) {

			a[i][j] = cnt++;

			if (ff)j++;

		}
		for (int c = 0; c < n; ++c) {
			for (int d = 0; d < n; ++d)
				cout << setw(4) << a[c][d];
			cout << endl;
		}
		cout << endl;
	}

	for (i = 0; i < n; ++i)

	{

		for (j = 0; j < n; ++j)

		{

			printf("%d ", a[i][j]);

			if (i == j)sum += a[i][j];

			if (i == n - j)sum += a[i][n - i];

		}

		printf("\n");

	}

	printf("%d\n", sum);

	return 0;

}*/
/*
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	return a % b == 0 ? b : gcd(b, a%b);
}
int main()
{
	int count = 0;
	int a, b;
	int x, y;
	cin >> x >> y;
	for (int i = 1; i <= y / x; ++i) {
		a = i * x;
		if (y%a == 0) {
			b = x * y / a;
			if (b < a)
				break;
			if (gcd(a, b) == x)
				count += 2;
		}
	}
	cout << count << endl;
	
	return 0;
}*/