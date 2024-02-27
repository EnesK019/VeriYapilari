/**
* @file 		YoneticiListesiNode.cpp
* @description  Yonetici listesi düğümü için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "YoneticiListesiNode.hpp"

YoneticiListesiNode::YoneticiListesiNode(SatirListesi* data, YoneticiListesiNode *next, YoneticiListesiNode *prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average = averageCalculate();
}
	
YoneticiListesiNode::YoneticiListesiNode(SatirListesi* data, YoneticiListesiNode *next)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average = averageCalculate();
}
		
YoneticiListesiNode::YoneticiListesiNode(SatirListesi* data)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average = averageCalculate();
}
	
double YoneticiListesiNode::averageCalculate()
{
	double result = 0;
	if(this->data->isEmpty())
		return result;
	
	int count = this->data->Count();
	for(int i = 0; i < count; i++)
	{
		result += this->data->elementAt(i);
	}
	return result / count;
}