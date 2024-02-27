/**
* @file 		YoneticiListesiNode.hpp
* @description  Yonetici listesi düğümü için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef YONETICILISTESINODE_HPP
#define YONETICILISTESINODE_HPP

#include "SatirListesi.hpp"

class YoneticiListesiNode
{
	public:
		SatirListesi* data;
		YoneticiListesiNode *next;
		YoneticiListesiNode *prev;
		double average;
		
		YoneticiListesiNode(SatirListesi* data, YoneticiListesiNode *next, YoneticiListesiNode *prev);
		YoneticiListesiNode(SatirListesi* data, YoneticiListesiNode *next);
		YoneticiListesiNode(SatirListesi* data);
		double averageCalculate();
};


#endif