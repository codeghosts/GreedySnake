#include "HEAD.h"
snake *head;
snake *p;
snake *FOOD;
int Crash = 0;
int bititself = 0;
int Esc = 0;
int status;
int score = 0;
int sleeptime = 200;
//画出蛇，初始化蛇的位置
void INIT_SNAKE()
{
	snake *tail;
	int i = 0;
	tail = (snake *)malloc(sizeof(snake));
	tail->x = 10;
	tail->y = 10;
	tail->next = NULL;
	for (i = 1; i <= 4; i++)
	{
		head = (snake *)malloc(sizeof(snake));
		head->next = tail;
		head->x = 10 + 2 * i;
		head->y = 10;
		tail = head;
	}
	while (tail != NULL)
	{
		Init_cursor(tail->x, tail->y);
		printf("□");
		tail = tail->next;
	}
}

//判断蛇是否与自身相撞
int BitItSelf()
{
	snake *bit;
	bit = head->next;
	while (bit != NULL)
	{
		if (bit->x == head->x && bit->y == head->y)
		{ 
			bititself = 1;
			EndGame();
		}
		bit = bit->next; //遍历蛇身，只要蛇头的坐标和任意一节的坐标重合，就代表相撞了
	}
	return 0;
}

//创建食物的位置并画出来
void CreatFood()
{
	snake *food;
	srand((unsigned)time(NULL));
	food = (snake*)malloc(sizeof(snake));
	while ((food->x % 2) != 0)
	{
		food->x = rand() % 50 + 2;
	}
	food->y = rand() % 20 + 2;
	p = head;
	while (p->next == NULL)
	{
		if (p->x == food->x && p->y == food->y)
		{
			free(food);   //一旦吃到了食物，删除它
			CreatFood();   //重新创建一个食物
		}
		p = p->next;
	}
	Init_cursor(food->x, food->y);
	FOOD = food;
	printf("*");
}

//结束游戏
void EndGame()
{
	system("cls");
	Init_cursor(70, 39);
	if (Crash == 1)
		printf("你的蛇撞墙了！\n");
	if (bititself == 1)
		printf("你的蛇咬到自己了！\n");
	if (Esc == 1)
		printf("主动退出游戏!");
	exit(0);
}

//判断是否撞墙
int Strike()
{
	if (head->y == 23 || head->y == 0 || head->x == 54 || head->x == 0)
	{
		Crash = 1;
		EndGame();
	}
	return 0;
}

//开始移动蛇
void MoveSnake()
{
	snake *nexthead;
	Strike();
	nexthead = (snake *)malloc(sizeof(snake));
	if (status == 1)  //此时蛇会往上移动
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1; //向上走y坐标减一

		if (nexthead->x == FOOD->x && nexthead->y == FOOD->y) //吃到食物了，就添加一个方块
		{
			nexthead->next = head;
			head = nexthead; //头插法
			p = head;
			while (p != NULL)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			CreatFood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			p = head;
			while (p->next->next != NULL)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	if (status == 4) //此时蛇向下移动
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
		if (nexthead->x == FOOD->x && nexthead->y == FOOD->y)
		{
			nexthead->next = head;
			head = nexthead;
			p = head;
			while (p)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			CreatFood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			p = head;

			while (p->next->next != NULL)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	if (status == 2) //此时蛇向左移动
	{
		nexthead->x = head->x - 2;
		nexthead->y = head->y;
		if (nexthead->x == FOOD->x && nexthead->y == FOOD->y)
		{
			nexthead->next = head;
			head = nexthead;
			p = head;

			while (p)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			CreatFood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			p = head;

			while (p->next->next != NULL)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	if (status == 3) //此时蛇向右移动
	{
		nexthead->x = head->x + 2;
		nexthead->y = head->y;
		if (nexthead->x == FOOD->x && nexthead->y == FOOD->y)
		{
			nexthead->next = head;
			head = nexthead;
			p = head;

			while (p)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			CreatFood();
		}
		else
		{
			nexthead->next = head;
			head = nexthead;
			p = head;

			while (p->next->next != NULL)
			{
				Init_cursor(p->x, p->y);
				printf("□");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	BitItSelf();
}

//暂停游戏
void Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
			break;
	}
}

//控制贪吃蛇
void Contrl()
{
	Init_cursor(70, 20);
	printf("不能撞墙，不能咬到自己");
	Init_cursor(70, 21);
	printf("上下左右控制移动");
	Init_cursor(70, 22);
	printf("ESC 退出游戏；空格暂停游戏");
	status = 1;
	while(1)
	{ 
	   if (GetAsyncKeyState(VK_UP) && status != 4)
	   {
		  status = 1;
	   }
	   else if (GetAsyncKeyState(VK_DOWN) && status != 1)
	   {
		   status = 4;
	   }
	   else if (GetAsyncKeyState(VK_LEFT) && status != 3)
	   {
		   status = 2;
	   }
	   else if (GetAsyncKeyState(VK_RIGHT) && status != 2)
	   {
		   status = 3;
	   }
	   else if (GetAsyncKeyState(VK_SPACE))
	   {
		   Pause();
	   }
	   else if (GetAsyncKeyState(VK_ESCAPE))
	  {
		Esc = 1;
		EndGame();
		break;
	   }
	   Sleep(sleeptime);
	   MoveSnake();
    }
}

//开始界面
void WelcomeToGame()
{
	Init_cursor(40, 12);
	system("title  welcome to game");
	printf("欢迎来到贪吃蛇游戏");
	Init_cursor(40, 25);
	system("pause");
	system("cls");
	Init_cursor(25, 12);
	printf("用上下左右控制移动");
	system("pause");
	system("cls");
}

void StartGame()
{
	system("mode con cols = 100 lines = 30");
	WelcomeToGame();
	Creat_Map();
	INIT_SNAKE();
	CreatFood();
}