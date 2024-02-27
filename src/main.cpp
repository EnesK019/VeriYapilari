/**
* @file 		main.cpp
* @description  Programı çalıştırmak için oluşturduğum kaynak kodu
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "ReadFile.hpp"
#include <cstdlib>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "DisplayScreen.hpp"
using namespace std;

int main() 
{
    ReadFilee *readFile = new ReadFilee("veriler.txt");

	YoneticiListesi *yoneticiListesi = readFile->WriteYoneticiListesi();

    DisplayScreen *console = new DisplayScreen(yoneticiListesi);
    yoneticiListesi->sortByAverage();
    string choice = "";
	
    do 
	{
        console->printYoneticiListesi();
        cin>>choice;
        if (choice == "c") 
		{
            console->setCurrentList(1);
        } 
		else if (choice == "z") 
		{
            console->setCurrentList(0);
        } 
		else if (choice == "k") 
		{
            int randomIndex = 0;
            try 
			{
                randomIndex = console->DisplayRandomSelectedNode();
            } 
			catch (...) 
			{
                continue;
            }
            cin>>choice;
            if (choice == "k") 
			{
                console->DeleteRandomSelectedNode(randomIndex);
                yoneticiListesi->sortByAverage();
            }
        } 
		else if (choice == "p") 
		{
            console->DeleteYoneticiListesiNode();
        } 
		else if (choice == "d") 
		{
            console->setPage(1);
        } 
		else if (choice == "a") 
		{
            console->setPage(0);
        }
    }while (choice != "q");

    return 0;
}