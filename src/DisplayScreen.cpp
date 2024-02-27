/**
* @file 		DisplayScreen.cpp
* @description  Ekrana yazdırmak için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "DisplayScreen.hpp"

DisplayScreen::DisplayScreen(YoneticiListesi *yoneticilistesi)
{
	this->yoneticilistesi = yoneticilistesi;
	
	if (this->yoneticilistesi->Count() < listOfPage) 
	{
        this->lastList = this->yoneticilistesi->Count();
    } 
	else 
	{
        this->lastList = listOfPage;
    }
	
	this->firstList = 0;
}

void DisplayScreen::setCurrentPage()
{
	int currentPage = this->currentList / listOfPage;
	this->firstList = listOfPage * currentPage;
    this->lastList = listOfPage * (currentPage + 1);
    if (this->lastList >= this->yoneticilistesi->Count()) 
	{
        this->lastList = this->yoneticilistesi->Count();
	}
}

void DisplayScreen::setCurrentList(int nextOrPrevList)
{
	 
	if (nextOrPrevList == 0) 
	{
        if (currentList <= 0)	return;
        --currentList;
        setCurrentPage();
    } 	
	else if (nextOrPrevList == 1) 
	{
        if (currentList >= this->yoneticilistesi->Count() - 1) 
			return;
		
        ++currentList;
        setCurrentPage();
    }
	else if (nextOrPrevList == 2) 
	{
        setCurrentPage();
    }
}

void DisplayScreen::setPage(int nextOrPrevPage)
{
	if(nextOrPrevPage == 0)
	{
		for(int i = 0; i < listOfPage; ++i)
		{
			this->setCurrentList(0);
		}
	}
	else if(nextOrPrevPage == 1)
	{
		for(int i = 0; i < listOfPage; ++i)
		{
			this->setCurrentList(1);
		}
	}
}

void DisplayScreen::printSelectedSatirListesi(int x, int y) 
{
    this->yoneticilistesi->elementAt(this->currentList)->printSatirListesi(x, y);
}

void DisplayScreen::printYoneticiListesi()
{
	if(this->yoneticilistesi->elementAt(this->currentList)->isEmpty())
	{
		this->yoneticilistesi->removeAt(this->currentList);
		this->setCurrentList(2);
	}
	int count = yoneticilistesi->Count();
	system("CLS");
	if (count == 0) 
	{
        cout << "Goruntulenecek bir Yonetici listesi yok\n";
        exit(1);
        return;
    }
	
	ConsolePosition.gotoxy(0, 0);
	if (this->firstList == 0) 
	{
        cout << "<---ilk";
    } 
	else 
	{
        cout << "<---geri";
    }
	
	int NodeCount = this->lastList - this->firstList;
	NodeCount *= 13;
	
	ConsolePosition.gotoxy(NodeCount, 0);
	if (this->lastList == this->yoneticilistesi->Count()) 
	{
        cout<<"  son--->";
    } 
	else 
	{
        cout<<"  ileri--->";
    }
	
	for(int i = this->firstList; i < this->lastList; ++i)
	{
		int index = i % listOfPage;
		this->yoneticilistesi->printIndexOfYonetici(i, 15 * index, 1);
	}
	this->printSelectedSatirListesi((this->currentList % listOfPage) * 15, 9);
}

int DisplayScreen::DisplayRandomSelectedNode()
{
        int randomSelected = this-> yoneticilistesi->randomGenerator(this->currentList);
        int xPosition = ((this->currentList % listOfPage) + 1) * 15;
        int yPosition = (randomSelected) * 7;
        yPosition += 14;
		
        ConsolePosition.gotoxy(xPosition, yPosition);
        cout << "<--silinecek";
        yPosition = this->yoneticilistesi->elementAt(this->currentList)->Count() * 6 + 12;

        ConsolePosition.gotoxy(0, yPosition - 1);	
        return randomSelected;
}

void DisplayScreen::DeleteYoneticiListesiNode() 
{
    this->yoneticilistesi->removeAt(this->currentList);
    this->setCurrentList(2);
      
    if(this->currentList==this->lastList)		
		this->currentList--;
    
	this->setCurrentList(2);
}

void DisplayScreen::DeleteRandomSelectedNode(int randomIndex)
{
    this->yoneticilistesi->randomRemoveAtSatirListesi(this->currentList, randomIndex);
}