#include<iostream>
using namespace std;

class T//���������Թ��е�ǰλ�õĽṹ����
{
public:
	int x;//x����ǰλ�õ�������
	int y;//y����ǰλ�õ�������
	int dir;//0:��Ч,1:��,2:��,3:��,4:��
};

class LinkNode//������
{
	friend class Stack;
public:
	T data;
	LinkNode *next;
};

class Stack
{
private:
	LinkNode *top;//ָ���һ������ջ��ָ��
public:
	Stack();//���캯�����ÿ�ջ
	~Stack()//��������
	{}
	void Push(T e);//Ԫ��data��ջ��
	T Pop();//ջ��Ԫ�س�ջ
	T GetPop();//ȡ��ջ��Ԫ��
	void Clear();//��ջ���
	bool empty();//�ж�ջ�Ƿ�Ϊ�գ����Ϊ���򷵻�1�����򷵻�0
};

Stack::Stack()//���캯�����ÿ�ջ
{
	top = NULL;
}

void Stack::Push(T e)//Ԫ��x��ջ��
{
	LinkNode *P;
	P = new LinkNode;
	P->data = e;
	P->next = top;
	top = P;
}

T Stack::Pop()//ջ��Ԫ�س�ջ
{
	T Temp;
	LinkNode *P;
	P = top;
	top = top->next;
	Temp = P->data;
	delete P;
	return Temp;
}

T Stack::GetPop()//ȡ��ջ��Ԫ��
{
	return top->data;
}

void Stack::Clear()//��ջ���
{
	top = NULL;
}

bool Stack::empty()//�ж�ջ�Ƿ�Ϊ�գ����Ϊ���򷵻�1�����򷵻�0
{
	if (top == NULL) return 1;
	else return 0;
}

int mov[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//���嵱ǰλ���ƶ���4������

void PrintPath(Stack p)//���·��
{
	cout << "�Թ���·��Ϊ\n";
	cout << "�����ڵ����ݷֱ��ʾΪ(������,������,���ֻ�����,����)\n";
	Stack t;//����һ��ջ��������ڵ����ڴ�ȡ·��
	int a, b;
	T data;
	LinkNode *temp;
	temp = new LinkNode;//��ȡ�ռ�
	temp->data = p.Pop();//ȡջp�Ķ���Ԫ�أ�����һ��λ��
	t.Push(temp->data);//��һ��λ����ջt
	delete temp;//�ͷſռ�
	while (!p.empty())//���ջp�ǿգ��򷴸�ת��
	{
		temp = new LinkNode;
		temp->data = p.Pop();//��ȡ��һ��λ��
		//�õ����߷���
		a = t.GetPop().x - temp->data.x;//�����귽��
		b = t.GetPop().y - temp->data.y;//�����귽��
		if (a == 1) temp->data.dir = 1;//�������£���1��ʾ
		else if (b == 1) temp->data.dir = 2;//�������ң���2��ʾ
		else if (a == -1) temp->data.dir = 3;//�������ϣ���3��ʾ
		else if (b == -1) temp->data.dir = 4;//����������4��ʾ
		t.Push(temp->data);//����λ����ջ
		delete temp;
	}//���·�������������꣬�����꣬��һ��λ�÷���
	while (!t.empty())//ջ�ǿգ��������
	{
		data = t.Pop();
		cout << '(' << data.x << ',' << data.y << ',' << data.dir << ",";//��������꣬������
		switch (data.dir)//�����Ӧ�ķ��� 
		{
		case 1:cout << "��)\n"; break;
		case 2:cout << "��)\n"; break;
		case 3:cout << "��)\n"; break;
		case 4:cout << "��)\n"; break;
		case 0:cout << ")\n"; break;
		}
	}
}

void Restore(int **maze, int m, int n)//�ָ��Թ�
{
	int i, j;
	for (i = 0; i < m + 2; i++)//����ָ��
		for (j = 0; j < n + 2; j++)
		{
			if (maze[i][j] == -1)//�ָ�̽����λ�ã�����-1�ָ�Ϊ0
				maze[i][j] = 0;
		}
}

int** GetMaze(int &m, int &n)//���ش�ȡ�Թ��Ķ�άָ��
{
	int **maze;//�����άָ���ȡ�Թ�
	int i = 0, j = 0;
	cout << "�������Թ��ĳ��Ϳ�:";
	int a, b; cin >> a >> b;//�����Թ��ĳ��Ϳ�
	cout << "�������Թ�����:(0Ϊͨ·��1Ϊǽ)\n";
	m = a;
	n = b;//m,n�ֱ�����Թ�������������
	maze = new int *[m + 2];//��ȡ���ȵ���������2�Ķ���ָ��
	for (i = 0; i < m + 2; i++)//ÿ����άָ��Ŀռ�
	{
		maze[i] = new int[n + 2];
	}
	for (i = 1; i <= m; i++)//�����Թ������ݣ�0�����ͨ��1����ͨ
		for (j = 1; j <= n; j++)
			cin >> maze[i][j];
	for (i = 0; i < m + 2; i++)
		maze[i][0] = maze[i][n + 1] = 1;
	for (i = 0; i < n + 2; i++)
		maze[0][i] = maze[m + 1][i] = 1;
	return maze;//���ش����Թ��Ķ�άָ��maze
};

bool Mazepath(int **maze, int m, int n)//Ѱ���Թ�maze�дӣ�0��0������m,n����·��
{
	Stack q, p;//����ջp��q,�ֱ��̽���Թ��Ĺ��̺ʹ洢·��
	T Temp1, Temp2;
	int x, y, loop;
	Temp1.x = 1;
	Temp1.y = 1;
	q.Push(Temp1);//�����λ����ջ
	p.Push(Temp1);
	maze[1][1] = -1;//��־���λ���ѵ����
	while (!q.empty())//ջq�ǿգ��򷴸�̽��
	{
		Temp2 = q.GetPop();//��ȡջ��Ԫ��
		if (!(((p.GetPop().x) == (q.GetPop().x)) && ((p.GetPop().y) == (q.GetPop().y))))
			p.Push(Temp2);
		//�������λ����ջ�������һ��̽����λ�ô���ջp
		for (loop = 0; loop < 4; loop++)//̽����ǰλ�õ�4������λ��
		{
			x = Temp2.x + mov[loop][0];//�������λ��xλ��ֵ
			y = Temp2.y + mov[loop][1];//�������λ��yλ��ֵ
			if (maze[x][y] == 0)//�ж���λ���Ƿ�ɴ�
			{
				Temp1.x = x;
				Temp1.y = y;
				maze[x][y] = -1;//��־��λ���ѵ����
				q.Push(Temp1);//��λ����ջ
			}
			if ((x == (m)) && (y == (n)))//�ɹ��������
			{
				Temp1.x = m;
				Temp1.y = n;
				Temp1.dir = 0;
				p.Push(Temp1);//�����һ��λ����ջ
				PrintPath(p);//���·��
				Restore(maze, m, n);//�ָ�·��
				return 1;//��ʾ�ɹ��ҵ�·��
			}
		}
		if (p.GetPop().x == q.GetPop().x&&p.GetPop().y == q.GetPop().y)//���û����λ����ջ���򷵻ص���һ��λ��
		{
			p.Pop();
			q.Pop();
		}
	}
	return 0;//��ʾ����ʧ�ܣ����Թ���·��
}

int main()
{
	int m = 0, n = 0;//�����Թ��ĳ��Ϳ�
	int **maze;//�����άָ���ȡ�Թ�
	maze = GetMaze(m, n);//����GetMaze(int &m,int &n)�������õ��Թ�
	if (Mazepath(maze, m, n))//����Mazepath(int **maze,int m,int n)������ȡ·��
		cout << "�Թ�·��̽���ɹ�!\n";
	else cout << "·��������!\n";
	
	return 0;
}