/**
* @file 		YoneticiListesi.hpp
* @description  Yonetici listesi için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SatirListesi.hpp"
#include "YoneticiListesiNode.hpp"
#include "ConsolePosition.hpp"

class YoneticiListesi
{
	private: 
		YoneticiListesiNode *head;
		int size;
		
		YoneticiListesiNode* FindPreviousByPosition(int index);
		
	public:
		YoneticiListesi();
		int Count() const;
		bool isEmpty() const;
		void add(SatirListesi*& item);
		void insert(int index, SatirListesi*& item);
		SatirListesi*& first();
		SatirListesi*& last();
		int indexOf(SatirListesi*& item);
		void remove(SatirListesi*& item);
		void removeAt(int index);
		bool find(SatirListesi*& item);
		SatirListesi*& elementAt(int index);
		void clear();
		void averageCalculate(int index);
		int randomGenerator(int index);
		void randomRemoveAtSatirListesi(int index, int inlineIndex);		
		void nodePlacement(int fplace, int lplace);
		void sortByAverage();
		void printIndexOfYonetici(int index, int x, int y);
		~YoneticiListesi();
};

#endif