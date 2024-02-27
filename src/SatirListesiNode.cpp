/**
* @file 		SatirListesiNode.cpp
* @description  Satir listesi düğümleri için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "SatirListesiNode.hpp"

SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next, SatirListesiNode *prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data, SatirListesiNode *next)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}
SatirListesiNode::SatirListesiNode(const int data)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}