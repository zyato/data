/*���岢ʵ��һ�������࣬�г������������ԣ��ɳ�Ա����������ε������*/
#include<iostream>
using namespace std;

class JuXing {
private:
	double lenth;
	double width;
public:
	JuXing()
	{
		lenth = 0.0;
		width = 0.0;
	}
	void ShowResult() {
		cout << "��Ϊ" << lenth << "��Ϊ" << width << "�ľ��ε������" << CalaArea() << endl;
	}
	inline void SetData(double a, double b);
	inline double CalaArea() {
		return lenth * width;
	}
};
void JuXing::SetData(double a, double b) {
	lenth = a;
	width = b;
}
int main() {

	JuXing num1;
	num1.ShowResult();
	JuXing num2;
	num2.SetData(4.4, 2);
	num2.ShowResult();

	system("pause");
	return 0;
}