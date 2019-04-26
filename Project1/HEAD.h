#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>



typedef struct Snake{
	int x; 
	int y;
	//ÉßµÄ×ø±ê
	Snake *next;
}snake;

//snake *head;
//snake *p;
//snake *FOOD;



void Init_cursor(int x, int y);
void Creat_Map();
void INIT_SNAKE();
int BitItSelf();
void CreatFood();
void MoveSnake();
void StartGame();
void Contrl();
void EndGame();
int Strike();
void WelcomeToGame();
void Pause();