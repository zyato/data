/***********************************************************************
*设计一个用于人事管理的“人员”类。由于考虑到通用性，这里只抽象出所有类
*型人员都具有的属性：编号、性别、出生日期、身份证号等。其中“出生日期”
*声明为一个“日期”类内嵌子对象。用成员函数实现对人员信息的录入和显示。
*要求包括：构造函数和析构函数、复制构造函数、内联成员函数、带默认形参值的
*成员函数、类的组合。*******************************/
#include<iostream>
#include<string>
using namespace std;
//创建日期类
class Date {
private:
	int year, month, day;
public:
	Date() {
		year = 2000;
		month = 1;
		day = 1;
		cout << "调用日期类的构造函数！" << endl;
	}
	~Date() {
		cout << "调用日期类的析构函数！" << endl;
	}
	Date(const Date & a) {
		year = a.year;
		month = a.month;
		day = a.day;
		cout << "调用日期类的复制构造函数！" << endl;
	}
	inline void SetDate(int, int, int);
	inline void ShowDate();
};
void Date::SetDate(int _year, int _month, int _day) {
	year = _year;
	month = _month;
	day = _day;
}
void Date::ShowDate() {
	cout << "出生日期：" << year << "年" << month << "月" << day << "日" << endl;
}
//创建人员类：
class Member{
private:
	string Number;
	string Sex;
	Date Birthday;
	string Id;
public:
	Member() {
		Number = "000";
		Sex = "不男不女";
		Id ="000000000000000000";
		cout << "调用人员类的构造函数！" << endl;
	}
	~Member() {
		cout << "调用人员类的析构函数！" << endl;
	}
	Member(const Member & a) : Birthday(a.Birthday){
		Number = a.Number;
		Sex = a.Sex;
		//Birthday = a.Birthday;
		Id = a.Id;

		cout << "调用人员类的复制构造函数！" << endl;
	}
	void SetMember(string, string, int, int, int, string);
	void ShowInformation() {
		cout << "编号：" << Number << endl << "性别:" << Sex << endl;
		Birthday.ShowDate();
		cout << "身份证号：" << Id << endl;
	}


};
void Member::SetMember(string _Number, string _Sex, int a, int b, int c, string _Id){
	Number = _Number;
	Sex = _Sex;
	Birthday.SetDate(a, b, c);
	Id = _Id;
}

int main() {
	Member mem1;
	mem1.ShowInformation();
	mem1.SetMember("110", "女", 1998, 1, 30, "412725199801308888");
	mem1.ShowInformation();
	Member mem2=mem1;
	mem2.ShowInformation();
	system("pause");

	return 0;
}