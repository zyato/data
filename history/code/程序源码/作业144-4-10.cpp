/***********************************************************************
*���һ���������¹���ġ���Ա���ࡣ���ڿ��ǵ�ͨ���ԣ�����ֻ�����������
*����Ա�����е����ԣ���š��Ա𡢳������ڡ����֤�ŵȡ����С��������ڡ�
*����Ϊһ�������ڡ�����Ƕ�Ӷ����ó�Ա����ʵ�ֶ���Ա��Ϣ��¼�����ʾ��
*Ҫ����������캯�����������������ƹ��캯����������Ա��������Ĭ���β�ֵ��
*��Ա�����������ϡ�*******************************/
#include<iostream>
#include<string>
using namespace std;
//����������
class Date {
private:
	int year, month, day;
public:
	Date() {
		year = 2000;
		month = 1;
		day = 1;
		cout << "����������Ĺ��캯����" << endl;
	}
	~Date() {
		cout << "���������������������" << endl;
	}
	Date(const Date & a) {
		year = a.year;
		month = a.month;
		day = a.day;
		cout << "����������ĸ��ƹ��캯����" << endl;
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
	cout << "�������ڣ�" << year << "��" << month << "��" << day << "��" << endl;
}
//������Ա�ࣺ
class Member{
private:
	string Number;
	string Sex;
	Date Birthday;
	string Id;
public:
	Member() {
		Number = "000";
		Sex = "���в�Ů";
		Id ="000000000000000000";
		cout << "������Ա��Ĺ��캯����" << endl;
	}
	~Member() {
		cout << "������Ա�������������" << endl;
	}
	Member(const Member & a) : Birthday(a.Birthday){
		Number = a.Number;
		Sex = a.Sex;
		//Birthday = a.Birthday;
		Id = a.Id;

		cout << "������Ա��ĸ��ƹ��캯����" << endl;
	}
	void SetMember(string, string, int, int, int, string);
	void ShowInformation() {
		cout << "��ţ�" << Number << endl << "�Ա�:" << Sex << endl;
		Birthday.ShowDate();
		cout << "���֤�ţ�" << Id << endl;
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
	mem1.SetMember("110", "Ů", 1998, 1, 30, "412725199801308888");
	mem1.ShowInformation();
	Member mem2=mem1;
	mem2.ShowInformation();
	system("pause");

	return 0;
}