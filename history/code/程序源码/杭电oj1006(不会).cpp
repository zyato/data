#include<iostream>
#include <iomanip>
using namespace std;
struct Segment//����ṹ
{
	double a, b;
};
//����������������ǵĽ�����
Segment operator *(Segment S1, Segment S2) {
	Segment seg;
	seg.a = S1.a > S2.a ? S1.a : S2.a;
	seg.b = S1.b < S2.b ? S1.b : S2.b;
	if (seg.a > seg.b)
		seg.a = seg.b = 0.0;
	return seg;

}
//������ʱ�⡱�ٽ�Ƕ�
double D;
//��D<=bS-a<=D1 �н������
Segment makeSeg1(double, double);
//��D<=a-bS<=D1
Segment makeSeg2(double, double);

int main() {
	while (cin >> D, D != -1)
	{
		double toLen = 0.0;//������ʱ�⡱�ܳ���
		//ö��ʱ����
		for (int H = 0; H < 12; H++)
		{
			for (int M = 0; M < 60; M++)
			{
				Segment S[3][2];
				//��û���������
				double a, b;
				a = 30.0*H - 5.5*M;
				b = 11.0 / 120;//ʱ��-����
				S[0][0] = makeSeg1(a, b);
				S[0][1] = makeSeg2(a, b);
				a = 30.0*H + 0.5*M;
				b = 719.0 / 120;//����-ʱ��
				S[1][0] = makeSeg1(a, b);
				S[1][1] = makeSeg2(a, b);
				a = 6.0*M;
				b = 5.9;//����-����
				S[2][0] = makeSeg1(a, b);
				S[2][1] = makeSeg2(a, b);
				//���⼯ת��Ϊ����Ĳ������ۼơ�����ʱ�⡱�ĳ���
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
//��D<=bS-a<=D1�н��
Segment makeSeg1(double a, double b) {
	Segment seg;
	seg.a = (D + a) / b, seg.b = (360.0 - D + a) / b;
	if (seg.a < 0.0) seg.a = 0.0;
	if (seg.b > 60.0)seg.b = 60.0;
	if (seg.a >= seg.b)
		seg.a = seg.b = 0.0;
	return seg;
}
//��D<=a-bS<=D1�н������
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
����Happy, ����������Happy����������������ת����������Happy��ʱ�䡣

�����ֻҪ���ý��ٶ���������⣬Ȼ��������ڽ�������

����, ÿ����ת��360�ȣ�

����, ÿСʱת��360�ȣ�ÿ����ת360 / 60 = 6�ȣ�

ʱ�룬һ��Сʱת30�ȣ���ôÿ����ת30 / 60 = 0.5�ȣ�

���ٶȱ� = ��ʱ�룺���룺���� = 0.5:6 : 30 = 1 / 120 : 0.1 : 6

���ڶ��壺

V_SEC 6 ������ٶȣ�

V_MIN 0.1 ������ٶȣ�

V_HOU 1 / 120 ʱ����ٶ�

�赱ǰ��ʱ��ΪH : M:S, ����0 <= H < 12, 0 <= M < 60, 0 <= S < 60, H, M��Ϊ������SΪʵ��������ʱ�롢���롢���������ʱ��0 : 0 : 0��ת�Ƿֱ�Ϊ��

	A_SEC 6S  ������Ϊ���룬Ҫվ������ĽǶ�˼�����⣬60��ת360�ȣ���ôÿ��ת6�ȣ���S���ת6S��

	A_MIN 6M + 0.1S  ������Ϊ���룬Ҫվ�ڷ���ĽǶȿ������⣬60����ת360�ȣ�ÿ����ת6��  ��6M

	1����ת6�ȼ�60����ת6�ȣ���ôÿ�����ת0.1��  ��0.1S

	A_HOU 30H + 0.5M + S / 120  ͬ���֪����

	����Ŀ�е��ٽ�н�ΪD���򡰿���ʱ�⡱��ͬʱ�������²���ʽ�Ľ⣺

	D<=|A_HOU - A_MIN|<=360 - D;  ��1��

	D<=|A_HOU - A_SEC|<=360 - D;  ��2��

	D<=|A_MIN - A_SEC|<=360 - D;  ��3��

	��������������������Ĳ����������ŷ�����

	����ľ���ֵ�е���ʽһ�����Ի�ΪbS - a, (a, bΪ����)���ʣ�

	D <= bS - a <= 360 - D  ���[(a + D) / b, (a + 360 - D) / b]

	D - 360 <= bS - a <= -D ���[(a + D - 360) / b, (a - D) / b]

	�ʽ����ʽΪ��[(a + D) / b, (a + 360 - D) / b]����[(a + D - 360) / b, (a - D) / b]������������Ĳ�����

	����ʽ��1���õ��Ľ⼯ΪS11��S12, ��ô������ʱ�⡱��ʱ����ȷ��������£�����Ľ⼯Ϊ

	[0, 60]����S11��S12����(S21��S22)��(S31��S32)

	����ļ������׻���S1��S2��S3��S4��S5��S6��S7��S8����ʽ������S1��S2��...��Ϊ�����䡣

	������Ĳ����ܳ���û�����ѣ�������ܳ��Ⱦ�����ʱ����ȷ���ġ�����ʱ�⡱�ĳ��ȡ�

	A_HOU - A_MIN = 30H + 0.5M + S / 120 - ��6M + 0.1S�� = ��30H - 5.5M�� - (11S / 120) = a - bS

	A_HOU - A_SEC = (30H + 0.5M + S / 120) - 6S = (30H + 0.5M) - (719S / 120) = a - bS

	A_MIN - A_SEC = 6M + 0.1S - (6S) = (6M) - 5.9S = a - bS

	���Ǵ���������ˡ�



*/