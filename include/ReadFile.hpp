/**
* @file 		ReadFile.hpp
* @description  Dosyadan veri okumak için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#ifndef READFILE_HPP
#define READFILE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"

class ReadFilee
{
	private:
		string fileName;
		SatirListesi **Lines;
		int lineCount();
		void readLine();
		
	public:
		ReadFilee(string fileName);		
		YoneticiListesi* WriteYoneticiListesi();
		~ReadFilee();
};
#endif