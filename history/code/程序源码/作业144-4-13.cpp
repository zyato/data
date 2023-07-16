/*定义一个Circle类，有数据成员radius（半径），成员函数getArea（），计算圆的面积，构造一个Circle的对象进行测试*/
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
	cout << "circle1的面积是：" << circle1.getArea() << endl;
	Circle circle2;
	circle2.setData(5);
	cout << "circle2的面积是：" << circle2.getArea() << endl;

	system("pause");
	return 0;
}