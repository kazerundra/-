// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int time1, time2, time3;

//１－２３から数字が入力されたかどうか確認するために
void checkTime(int time)
{
	int temp = 0;
	cin >> temp;
	while (temp <1 || temp >23) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		printf("1-23数字を入力してください\n");
		cin >> temp;
	}
	if (time == 1) {
		time1 = temp;
	}
	else if (time == 2) 
	{
		time2 = temp;
	}
	else if(time ==3)
	{
		time3 =temp;
	}
}
//時刻の間を確認する
bool checkBetween() 
{
	if (time3 == time1) 
	{
		return true;
	}
	else if(time1 < time2) 
	{
		if ((time1<time3) && (time3<time2)) 
		{		
			return true;		
		}
		else
		{		
			return false;
		}
	}
	else //(time1 > time2) 
	{
		if (time3 > time1 || time3 < time2) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
int main()
{
	same:
	printf("開始時刻を入力してください\n");
	checkTime(1);
	printf("終了時刻を入力してください\n");
	checkTime(2);
	if (time1 == time2) 
	{
		printf("開始時刻と終了時刻が同じですもう一度\n");
		goto same;
	}
	test:
	printf("確認したい時間を入力してください\n");
	checkTime(3);
	if (checkBetween())
	{
		printf("その時間は開始時刻と終了時刻の間に入ってます\n");
	}
	else 
	{
		printf("その時間は開始時刻と終了時刻の間に入ってません\n");
	}
	goto test;
    return 0;
}


