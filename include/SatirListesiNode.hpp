/**
* @file 		SatirListesiNode.hpp
* @description  Satir listesi düğümleri için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef SATIRLISTESINODE_HPP
#define SATIRLISTESINODE_HPP

#include <iostream>
using namespace std;

class SatirListesiNode
{
	public: 
		int data;
		SatirListesiNode *next;
		SatirListesiNode *prev;
		
		SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev);
		SatirListesiNode(const int data, SatirListesiNode *next);
		SatirListesiNode(const int data);
};
#endif