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
//�����ߣ���ʼ���ߵ�λ��
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
		printf("��");
		tail = tail->next;
	}
}

//�ж����Ƿ���������ײ
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
		bit = bit->next; //��������ֻҪ��ͷ�����������һ�ڵ������غϣ��ʹ�����ײ��
	}
	return 0;
}

//����ʳ���λ�ò�������
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
			free(food);   //һ���Ե���ʳ�ɾ����
			CreatFood();   //���´���һ��ʳ��
		}
		p = p->next;
	}
	Init_cursor(food->x, food->y);
	FOOD = food;
	printf("*");
}

//������Ϸ
void EndGame()
{
	system("cls");
	Init_cursor(70, 39);
	if (Crash == 1)
		printf("�����ײǽ�ˣ�\n");
	if (bititself == 1)
		printf("�����ҧ���Լ��ˣ�\n");
	if (Esc == 1)
		printf("�����˳���Ϸ!");
	exit(0);
}

//�ж��Ƿ�ײǽ
int Strike()
{
	if (head->y == 23 || head->y == 0 || head->x == 54 || head->x == 0)
	{
		Crash = 1;
		EndGame();
	}
	return 0;
}

//��ʼ�ƶ���
void MoveSnake()
{
	snake *nexthead;
	Strike();
	nexthead = (snake *)malloc(sizeof(snake));
	if (status == 1)  //��ʱ�߻������ƶ�
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1; //������y�����һ

		if (nexthead->x == FOOD->x && nexthead->y == FOOD->y) //�Ե�ʳ���ˣ������һ������
		{
			nexthead->next = head;
			head = nexthead; //ͷ�巨
			p = head;
			while (p != NULL)
			{
				Init_cursor(p->x, p->y);
				printf("��");
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
				printf("��");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	if (status == 4) //��ʱ�������ƶ�
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
				printf("��");
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
				printf("��");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	if (status == 2) //��ʱ�������ƶ�
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
				printf("��");
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
				printf("��");
				p = p->next;
			}
			Init_cursor(p->next->x, p->next->y);
			printf(" ");
			free(p->next);
			p->next = NULL;
		}
	}
	if (status == 3) //��ʱ�������ƶ�
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
				printf("��");
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
				printf("��");
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

//��ͣ��Ϸ
void Pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
			break;
	}
}

//����̰����
void Contrl()
{
	Init_cursor(70, 20);
	printf("����ײǽ������ҧ���Լ�");
	Init_cursor(70, 21);
	printf("�������ҿ����ƶ�");
	Init_cursor(70, 22);
	printf("ESC �˳���Ϸ���ո���ͣ��Ϸ");
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

//��ʼ����
void WelcomeToGame()
{
	Init_cursor(40, 12);
	system("title  welcome to game");
	printf("��ӭ����̰������Ϸ");
	Init_cursor(40, 25);
	system("pause");
	system("cls");
	Init_cursor(25, 12);
	printf("���������ҿ����ƶ�");
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