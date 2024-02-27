/**
* @file 		ReadFile.cpp
* @description  Dosyadan veri okumak için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "ReadFile.hpp"

ReadFilee::ReadFilee(string fileName)
{
	this->fileName = fileName;
	
	int linenumber = lineCount();
	this->Lines = new SatirListesi* [linenumber];
	for(int i = 0; i<linenumber; i++)
	{
		this->Lines[i] = new SatirListesi();
	}
}

int ReadFilee::lineCount()
{
	int count = 0;
	ifstream file(this->fileName);
	string endline;
	while(getline(file,endline))
		count++;
		
	file.close();	
	return count;
}

void ReadFilee::readLine()
{
	ifstream file(this->fileName);
	string satir;
	int numbers;
	int index = 0;
	
	while(getline(file,satir))
	{
		stringstream ss;
		ss<<satir;
		while(ss>>numbers)
		{
			this->Lines[index]->add(numbers);
		}	
		index++;
	}
	file.close();
}

YoneticiListesi* ReadFilee::WriteYoneticiListesi()
{
	readLine();
	YoneticiListesi *liste = new YoneticiListesi();
	int count = lineCount();
	for(int i = 0; i < count; i++)
	{
		liste->add(this->Lines[i]);
	}
	return liste;
}

ReadFilee::~ReadFilee()
{
	if(Lines!=0)
	{
		int count =lineCount();
		for (int i = 0; i < count; i++)
		{
			if(Lines[i]!=0) delete Lines[i];
		}
		delete[] Lines;
	}
}