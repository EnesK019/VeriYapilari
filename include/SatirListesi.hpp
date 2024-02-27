/**
* @file 		SatirListesi.hpp
* @description  Satir listesi için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "SatirListesiNode.hpp"
#include "ConsolePosition.hpp"
#include <iomanip>

class SatirListesi
{
	private:
		SatirListesiNode *head;
		int size;
		
		SatirListesiNode* FindPreviousByPosition(int index);
	public:
		SatirListesi();
		int Count() const;
		bool isEmpty() const;
		void add(const int& item);
		void insert(int index, const int& item);
		int indexOf(const int& item);
		void remove(const int& item);
		void removeAt(int index);
		bool find(const int& item);
		const int& elementAt(int index);
		void printSatirListesi(int x,int y);
		void clear();
		~SatirListesi();
};

#endif