/*����һ��Circle�࣬�����ݳ�Աradius���뾶������Ա����getArea����������Բ�����������һ��Circle�Ķ�����в���*/
#include<iostream>
using namespace std;

class Circle {
	double radius;
public:
	Circle() :radius(0.0){}
	void setData(double a){
		radius = a;
	}
	double getArea() {
		const float PI = 3.14f;
		return PI * radius * radius;
    }
};
int main(){

	Circle circle1;
	cout << "circle1������ǣ�" << circle1.getArea() << endl;
	Circle circle2;
	circle2.setData(5);
	cout << "circle2������ǣ�" << circle2.getArea() << endl;

	system("pause");
	return 0;
}