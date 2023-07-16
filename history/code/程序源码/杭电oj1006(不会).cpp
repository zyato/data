#include<iostream>
#include <iomanip>
using namespace std;
struct Segment//区间结构
{
	double a, b;
};
//由两个区间求出它们的交区间
Segment operator *(Segment S1, Segment S2) {
	Segment seg;
	seg.a = S1.a > S2.a ? S1.a : S2.a;
	seg.b = S1.b < S2.b ? S1.b : S2.b;
	if (seg.a > seg.b)
		seg.a = seg.b = 0.0;
	return seg;

}
//“快乐时光”临界角度
double D;
//从D<=bS-a<=D1 中解出区间
Segment makeSeg1(double, double);
//从D<=a-bS<=D1
Segment makeSeg2(double, double);

int main() {
	while (cin >> D, D != -1)
	{
		double toLen = 0.0;//“快乐时光”总长度
		//枚举时、分
		for (int H = 0; H < 12; H++)
		{
			for (int M = 0; M < 60; M++)
			{
				Segment S[3][2];
				//获得基本解区间
				double a, b;
				a = 30.0*H - 5.5*M;
				b = 11.0 / 120;//时针-分针
				S[0][0] = makeSeg1(a, b);
				S[0][1] = makeSeg2(a, b);
				a = 30.0*H + 0.5*M;
				b = 719.0 / 120;//秒针-时针
				S[1][0] = makeSeg1(a, b);
				S[1][1] = makeSeg2(a, b);
				a = 6.0*M;
				b = 5.9;//秒针-分针
				S[2][0] = makeSeg1(a, b);
				S[2][1] = makeSeg2(a, b);
				//将解集转化为区间的并，并累计“快乐时光”的长度
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
						for (int k = 0; k < 2; k++)
						{
							Segment TS = S[0][i] * S[1][j] * S[2][k];
							toLen += TS.b - TS.a;

						}

			}

		}
		cout << setprecision(3) << fixed << toLen / 432.0 << endl;
	}
	return 0;
}
//从D<=bS-a<=D1中解出
Segment makeSeg1(double a, double b) {
	Segment seg;
	seg.a = (D + a) / b, seg.b = (360.0 - D + a) / b;
	if (seg.a < 0.0) seg.a = 0.0;
	if (seg.b > 60.0)seg.b = 60.0;
	if (seg.a >= seg.b)
		seg.a = seg.b = 0.0;
	return seg;
}
//从D<=a-bS<=D1中解出区间
Segment makeSeg2(double a, double b) {
	Segment seg;
	seg.a = (a + D - 360.0) / b, seg.b = (a - D) / b;
	if (seg.a < 0.0)
		seg.a = 0.0;
	if (seg.b > 60.0)
		seg.b = 60.0;
	if (seg.a >= seg.b)
		seg.a = seg.b = 0.0;
	return seg;
}


/*
三针Happy, 即三针两两Happy。所以这个问题可以转化成求两针Happy的时间。

这道题只要利用角速度来进行求解，然后配合周期进行运算

秒针, 每分钟转动360度；

分针, 每小时转动360度，每分钟转360 / 60 = 6度；

时针，一个小时转30度，那么每分钟转30 / 60 = 0.5度；

角速度比 = 》时针：分针：秒针 = 0.5:6 : 30 = 1 / 120 : 0.1 : 6

现在定义：

V_SEC 6 秒针角速度；

V_MIN 0.1 分针角速度；

V_HOU 1 / 120 时针角速度

设当前的时间为H : M:S, 其中0 <= H < 12, 0 <= M < 60, 0 <= S < 60, H, M皆为整数，S为实数，于是时针、分针、秒针相对于时刻0 : 0 : 0的转角分别为：

	A_SEC 6S  这是因为秒针，要站在秒针的角度思考问题，60秒转360度，那么每秒转6度，故S秒会转6S；

	A_MIN 6M + 0.1S  这是因为分针，要站在分针的角度考虑问题，60分钟转360度，每分钟转6度  故6M

	1分钟转6度即60秒钟转6度，那么每秒分针转0.1度  故0.1S

	A_HOU 30H + 0.5M + S / 120  同理可知啊；

	设题目中的临界夹角为D，则“快乐时光”是同时满足以下不等式的解：

	D<=|A_HOU - A_MIN|<=360 - D;  （1）

	D<=|A_HOU - A_SEC|<=360 - D;  （2）

	D<=|A_MIN - A_SEC|<=360 - D;  （3）

	唉。。。。。。这个真心不会做，接着分析吧

	上面的绝对值中的形式一定可以化为bS - a, (a, b为常数)，故：

	D <= bS - a <= 360 - D  解得[(a + D) / b, (a + 360 - D) / b]

	D - 360 <= bS - a <= -D 解得[(a + D - 360) / b, (a - D) / b]

	故解的形式为：[(a + D) / b, (a + 360 - D) / b]并上[(a + D - 360) / b, (a - D) / b]即两个闭区间的并集。

	设由式（1）得到的解集为S11并S12, 那么“快乐时光”在时、分确定的情况下，其秒的解集为

	[0, 60]交（S11并S12）交(S21并S22)交(S31并S32)

	上面的集合容易化成S1并S2并S3并S4并S5并S6并S7并S8的形式，其中S1，S2，...皆为闭区间。

	求区间的并的总长度没有困难，而这个总长度就是由时、分确定的“快乐时光”的长度。

	A_HOU - A_MIN = 30H + 0.5M + S / 120 - （6M + 0.1S） = （30H - 5.5M） - (11S / 120) = a - bS

	A_HOU - A_SEC = (30H + 0.5M + S / 120) - 6S = (30H + 0.5M) - (719S / 120) = a - bS

	A_MIN - A_SEC = 6M + 0.1S - (6S) = (6M) - 5.9S = a - bS

	于是代码很明朗了。



*/