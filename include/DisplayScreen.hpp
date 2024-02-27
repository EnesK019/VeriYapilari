/**
* @file 		DisplayScreen.hpp
* @description  Ekrana yazdırmak için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef DISPLAYSCREEN_HPP
#define DISPLAYSCREEN_HPP

#include "YoneticiListesi.hpp"
#include "ConsolePosition.hpp"

#define listOfPage 8

class DisplayScreen
{
	private: 
		YoneticiListesi *yoneticilistesi;
		int firstList;
		int lastList;
		int currentList;
		void setCurrentPage();
	public:
		DisplayScreen(YoneticiListesi *yoneticilistesi);
		void setCurrentList(int nextOrPrevList);
		void setPage(int nextOrPrevPage);
		void printSelectedSatirListesi(int x, int y);
		void printYoneticiListesi();
		int DisplayRandomSelectedNode();
		void DeleteYoneticiListesiNode();
		void DeleteRandomSelectedNode(int randomIndex);
};
#endif