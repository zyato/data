#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <graphics.h>

#include <windows.h>

//define

#define E 1

#define C 3

#define B 4

#define P 5

#define W 6

#define T 7

#define PP p_position

//define

//ImagePointer

IMAGE box;

IMAGE player;

IMAGE target;

IMAGE complete;

IMAGE wall;

IMAGE empty;

//ImagePointer

int PP[2];//玩家位置

int map[10][15][15];//地图

int map_or[10][15][15];//地图备份

int winJ[10];//箱子数

int level_ = 0;//关卡读取计数

int level = 0;//游玩关卡计数

int levelnumber = 0;//关卡总数

//函数定义

int graphics(void);

int ImageLoader(void);

int readMap(void);

int readMap_Judge(int);

int getposition(void);

int move(void);

int winJudge(void);

int targetJudge(void);

int exchange(int);

int prinf(int, int, int);

//函数定义

int main(void)

{

	/***Preprocessing***/

	readMap();

	getposition();

	initgraph(1280, 720);

	loadimage(NULL, L"C:\\Users\\ROOOT\\Pictures\\empty.jpg");

	ImageLoader();

	settextstyle(18, 8, L"黑体");

	settextcolor(LIGHTBLUE);

	graphics();

	/***Preprocessing***/

	int i, j;

	for (;;)

	{

		for (i = 0; i < 15; i++)

		{

			for (j = 0; j < 15; j++)

			{

				prinf(map[level][i][j], i, j);

			}

		}

		move();

		winJudge();

		targetJudge();

	}

	return 0;

}

int readMap(void)

{

	FILE *fp = fopen("D:\\BOXLEVEL.txt","r");

	if (!fp)

	{

		initgraph(300, 300);

		settextcolor(LIGHTRED);

		outtextxy(0, 0, L"FILE \"D:\\BOXLEVEL.txt\" NOT EXIST!!");

		getch();

		closegraph();

		exit(0);

	}

	int i, j, q = 0;

	for (i = 0, j = 0;;)

	{

		int k = exchange(fgetc(fp));

		if (k == EOF)

		{

			return 0;

		}

		else if (k == '\n')

		{

			i++;

			j = 0;

			continue;

		}

		else if (k == 2)

		{

			level_++;

			levelnumber++;

			i = 0;

			j = 0;

			continue;

		}

		else if (!readMap_Judge(k))

		{

			closegraph();

			exit(0);

		}

		if (k == T || k == C)

		{

			winJ[level_]++;

		}

		map[level_][i][j] = k;

		map_or[level_][i][j] = k;

		j++;

	}

	fclose(fp);

	return 0;

}

int readMap_Judge(int i)

{

	if (i != 1 && i != 3 && i != 4 && i != 5 && i != 6 && i != 7)

	{

		return 0;

	}

	return 1;

}

int getposition(void)

{

	int i, j;

	for (i = 0; i < 15; i++)

	{

		for (j = 0; j < 15; j++)

		{

			if (map[level][i][j] == 5)

			{

				PP[0] = i;

				PP[1] = j;

			}

		}

	}

	return 0;

}

int move(void)

{

	if (level > levelnumber)

	{

		closegraph();

		exit(0);

	}

	switch (getch())

	{

	case 'w':

		if (map[level][PP[0] - 1][PP[1]] == B && map[level][PP[0] - 2][PP[1]] == E)//前边是箱子，箱子前面是空的

		{

			map[level][PP[0] - 2][PP[1]] = B;

			map[level][PP[0] - 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]--;

		}

		else if (map[level][PP[0] - 1][PP[1]] == B && map[level][PP[0] - 2][PP[1]] == T)//前面是箱子，箱子前面是目标

		{

			map[level][PP[0] - 2][PP[1]] = C;

			map[level][PP[0] - 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]--;

		}

		else if (map[level][PP[0] - 1][PP[1]] == E)//前面是空的

		{

			map[level][PP[0] - 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]--;

		}

		else if (map[level][PP[0] - 1][PP[1]] == C && map[level][PP[0] - 2][PP[1]] == E)//前面是完成，完成前面是空的

		{

			map[level][PP[0] - 2][PP[1]] = B;

			map[level][PP[0] - 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]--;

		}

		else if (map[level][PP[0] - 1][PP[1]] == C && map[level][PP[0] - 2][PP[1]] == T)//前面是完成，完成前面是目标

		{

			map[level][PP[0] - 2][PP[1]] = C;

			map[level][PP[0] - 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]--;

		}

		else if (map[level][PP[0] - 1][PP[1]] == T)//前面是目标

		{

			map[level][PP[0] - 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]--;

		}

		return 0;

	case 's':

		if (map[level][PP[0] + 1][PP[1]] == B && map[level][PP[0] + 2][PP[1]] == E)//后面是箱子，箱子后面是空的

		{

			map[level][PP[0] + 2][PP[1]] = B;

			map[level][PP[0] + 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]++;

		}

		else if (map[level][PP[0] + 1][PP[1]] == B && map[level][PP[0] + 2][PP[1]] == T)//后面是箱子，箱子后面是目标

		{

			map[level][PP[0] + 2][PP[1]] = C;

			map[level][PP[0] + 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]++;

		}

		else if (map[level][PP[0] + 1][PP[1]] == E)//后面是空的

		{

			map[level][PP[0] + 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]++;

		}

		else if (map[level][PP[0] + 1][PP[1]] == C && map[level][PP[0] + 2][PP[1]] == E)//后面是完成，完成后面是空的

		{

			map[level][PP[0] + 2][PP[1]] = B;

			map[level][PP[0] + 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]++;

		}

		else if (map[level][PP[0] + 1][PP[1]] == C && map[level][PP[0] + 2][PP[1]] == T)//后面是完成，完成后面是目标

		{

			map[level][PP[0] + 2][PP[1]] = C;

			map[level][PP[0] + 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]++;

		}

		else if (map[level][PP[0] + 1][PP[1]] == T)//后面是目标

		{

			map[level][PP[0] + 1][PP[1]] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[0]++;

		}

		return 0;

	case 'a':

		if (map[level][PP[0]][PP[1] - 1] == B && map[level][PP[0]][PP[1] - 2] == E)//左面是箱子，箱子左面是空的

		{

			map[level][PP[0]][PP[1] - 2] = B;

			map[level][PP[0]][PP[1] - 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]--;

		}

		else if (map[level][PP[0]][PP[1] - 1] == B && map[level][PP[0]][PP[1] - 2] == T)//左面是箱子，箱子左面是目标

		{

			map[level][PP[0]][PP[1] - 2] = C;

			map[level][PP[0]][PP[1] - 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]--;

		}

		else if (map[level][PP[0]][PP[1] - 1] == E)//左面是空的

		{

			map[level][PP[0]][PP[1] - 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]--;

		}

		else if (map[level][PP[0]][PP[1] - 1] == C && map[level][PP[0]][PP[1] - 2] == E)//左面是完成，完成左面是空的

		{

			map[level][PP[0]][PP[1] - 2] = B;

			map[level][PP[0]][PP[1] - 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]--;

		}

		else if (map[level][PP[0]][PP[1] - 1] == C && map[level][PP[0]][PP[1] - 2] == T)//左面是完成，完成左面是目标

		{

			map[level][PP[0]][PP[1] - 2] = C;

			map[level][PP[0]][PP[1] - 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]--;

		}

		else if (map[level][PP[0]][PP[1] - 1] == T)//左面是目标

		{

			map[level][PP[0]][PP[1] - 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]--;

		}

		return 0;

	case 'd':

		if (map[level][PP[0]][PP[1] + 1] == B && map[level][PP[0]][PP[1] + 2] == E)//右面是箱子，箱子左面是空的

		{

			map[level][PP[0]][PP[1] + 2] = B;

			map[level][PP[0]][PP[1] + 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]++;

		}

		else if (map[level][PP[0]][PP[1] + 1] == B && map[level][PP[0]][PP[1] + 2] == T)//右面是箱子，箱子右面是目标

		{

			map[level][PP[0]][PP[1] + 2] = C;

			map[level][PP[0]][PP[1] + 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]++;

		}

		else if (map[level][PP[0]][PP[1] + 1] == E)//右面是空的

		{

			map[level][PP[0]][PP[1] + 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]++;

		}

		else if (map[level][PP[0]][PP[1] + 1] == C && map[level][PP[0]][PP[1] + 2] == E)//右面是完成，完成右面是空的

		{

			map[level][PP[0]][PP[1] + 2] = B;

			map[level][PP[0]][PP[1] + 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]++;

		}

		else if (map[level][PP[0]][PP[1] + 1] == C && map[level][PP[0]][PP[1] + 2] == T)//右面是完成，完成右面是目标

		{

			map[level][PP[0]][PP[1] + 2] = C;

			map[level][PP[0]][PP[1] + 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]++;

		}

		else if (map[level][PP[0]][PP[1] + 1] == T)//右面是目标

		{

			map[level][PP[0]][PP[1] + 1] = P;

			map[level][PP[0]][PP[1]] = E;

			PP[1]++;

		}

		return 0;

	case 'q':

		closegraph();

		exit(0);

	default:

		return 0;

	}

}

int winJudge(void)

{

	int i, j, p = 0;

	for (i = 0; i < 15; i++)

	{

		for (j = 0; j < 15; j++)

		{

			if ((map_or[level][i][j] == T && map[level][i][j] == C) || (map_or[level][i][j] == C && map[level][i][j] == C))

			{

				p++;

			}

		}

	}

	if (p == winJ[level])

	{

		level++;

		getposition();

		cleardevice();

		loadimage(NULL, L"C:\\Users\\ROOOT\\Pictures\\empty.jpg");

	}

	return 0;

}

int targetJudge(void)

{

	int i, j;

	for (i = 0; i < 15; i++)

	{

		for (j = 0; j < 15; j++)

		{

			if ((map_or[level][i][j] == T && map[level][i][j] != P && map[level][i][j] != C) || (map_or[level][i][j] == C && map[level][i][j] != P && map[level][i][j] != C))

			{

				map[level][i][j] = T;

			}

		}

	}

	return 0;

}

int exchange(int i)

{

	if (i == EOF)

	{

		return EOF;

	}

	if (i == 10)

	{

		return '\n';

	}

	return i - 48;

}

int prinf(int judge, int i, int j)

{

	switch (judge)

	{

	case W:

		putimage(j * 50, i * 50, &wall);

		return 0;

	case B:

		putimage(j * 50, i * 50, &box);

		return 0;

	case T:

		putimage(j * 50, i * 50, &target);

		return 0;

	case C:

		putimage(j * 50, i * 50, &complete);

		return 0;

	case P:

		putimage(j * 50, i * 50, &player);

		return 0;

	case E:

		putimage(j * 50, i * 50, &empty);

		return 0;

	}

	return 0;

}

int graphics(void)

{

	{/******全屏******/

		HWND hwnd = GetHWnd();

		SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);

		SetWindowPos(hwnd, HWND_TOP, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);

	}/******全屏******/

	return 0;

}

int ImageLoader(void)

{

	loadimage(&box, L"C:\\Users\\ROOOT\\Pictures\\box.jpg", 50, 50);

	loadimage(&complete, L"C:\\Users\\ROOOT\\Pictures\\complete.jpg", 50, 50);

	loadimage(&wall, L"C:\\Users\\ROOOT\\Pictures\\wall.jpg", 50, 50);

	loadimage(&target, L"C:\\Users\\ROOOT\\Pictures\\target.jpg", 50, 50);

	loadimage(&player, L"C:\\Users\\ROOOT\\Pictures\\player.jpg", 50, 50);

	loadimage(&empty, L"C:\\Users\\ROOOT\\Pictures\\empty.jpg", 50, 50);

	return 0;

}

