#include <cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<Windows.h>
using namespace std;

class gasoline {
public:
	gasoline() {}
	gasoline(int a, int b) {
		unlead = a; lead = b;
	}
	int getTotal(int a, int b) {
		return total = a * unlead + b * lead;
	}
private: int unlead, lead, total;
};

/*
class student {
public:
	student() {}
	void setstudent(int a, int b) {
		English = a;
		computer = b;
		total = a + b;
	}
	int getScore() {
		return total;
	}

	void display() {
		printf("%d\n", total);
	}

	int English, computer, total;
}st[10000];

bool cmp(  student & lhs, student & rhs) {
	return lhs.total < rhs.total;
}
class car;
class boat {
public:
	friend int calcu(car&, boat&);
	boat(int a) { weight = a; }
private: int weight;
};
class car {
public:
	friend int calcu(car&, boat&);
	car(int a) { weight = a; }
private: int weight;

};
int calcu(car & a, boat & b) {
	return a.weight + b.weight;
}
class Time {
public:
	Time(int a, int b) { minute = a; sec = b; }
	void calc() {
		minute += sec / 60;
		sec %= 60;
	}
	void display() {
		sec++;
		calc();
		printf("MINUTE: %d SEC: %d\n", minute, sec);
	}
private:
	int minute, sec;
};

*/

class student {
public:
	student():English(0), computer(0), total(0) {};
	student(int a, int b) :English(a), computer(b) { total = English + computer; }
	void getscore(int a, int b) {
		English = a;
		computer = b;
		total = English + computer;
	}
	void display() {
		cout << "总分：" << total << endl;
	}
	int sort() { return English+computer; }
	//void sort(student *);
private:
	int English, computer, total;


};
int main() {

/*	gasoline today(16, 17);
	printf("%d\n", today.getTotal(200, 100));
	puts("---------------------------------------------------------------------");
	st[0].setstudent(50, 80); st[0].display();
	st[1].setstudent(60, 86); st[1].display();
	st[2].setstudent(66, 90); st[2].display();
	sort(st, st + 3, cmp);
	puts("Sort finished!");
	st[0].display();
	st[1].display();
	st[2].display();

	puts("---------------------------------------------------------------------");
	car tiger(75);
	boat bism(1000);
	printf("%d\n", calcu(tiger, bism));
	puts("---------------------------------------------------------------------");
	Time now(0, 0);
	for (;;) {
		now.display();
		Sleep(1000);
	//	system("cls");
	}
	int n; scanf_s("%d", &n);
*/

	student st[3];
	int arr[3]{ 0 }, tem;
	st[0].getscore(67, 80); st[0].display();
	
	st[1].getscore(60, 86); st[1].display();
	st[2].getscore(66, 90); st[2].display();
	
	arr[0] = st[0].sort();
	arr[1] = st[1].sort();
arr[2] = st[2].sort();
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2 - i; ++j) {
			if (arr[j] < arr[j+1]) {
				tem= arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tem;
			}
		}
	}
	cout << arr[0] << "\\" << arr[1] << "\\" << arr[2] << endl;
	system("pause");
}

/*
class student
{
public:
	void setscore(int en, int co)
	{
		english = en;
		computer = co;
	}
	int getscore()
	{
		total = english + computer;
		return total;
	};
	void display(int i)
	{
		cout << "学生" << i + 1 << "的成绩：\n";
		cout << "英语：" << english << endl;
		cout << "计算机：" << computer << endl;
	}
private:
	int english, computer, total;
};
void main()
{
	int i, total[3], english, computer, temp;
	student stu[3];
	cout << "成绩：英语 计算机\n";
	for (i = 0; i < 3; i++)
	{
		cin >> english >> computer;
		stu[i].setscore(english, computer);
	}
	for (i = 0; i < 3; i++)
	{
		stu[i].display(i);
		total[i] = stu[i].getscore();
	}
	if (total[0] < total[1])
	{
		temp = total[0];
		total[0] = total[1];
		total[1] = temp;
	}
	if (total[0] < total[2])
	{
		temp = total[0];
		total[0] = total[2];
		total[2] = temp;
	}
	if (total[1] < total[2])
	{
		temp = total[1];
		total[1] = total[2];
		total[2] = temp;
	}
	for (i = 0; i < 3; i++)
		cout << total[i] << " ";
	cout << endl; system("pause");
}*/


