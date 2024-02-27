/**
* @file 		ConsolePosition.hpp
* @description  Ekrana yazdıracağım değerlerin konumları için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef CONSOLEPOSITION_HPP
#define CONSOLEPOSITION_HPP

#include <windows.h>

static class ConsolePosition 
{
	public:

		static void gotoxy(int x, int y) 
		{
			COORD coordinate;
			coordinate.X = x;
			coordinate.Y = y;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
		}
}
	ConsolePosition;
#endif