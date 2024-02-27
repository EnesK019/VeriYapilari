/**
* @file 		SatirListesi.cpp
* @description  Satir listesi için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "SatirListesi.hpp"

SatirListesiNode* SatirListesi::FindPreviousByPosition(int index)
{
	if(index < 0 || index > size) throw "No Such Element";
	SatirListesiNode *prv = head;
	int i = 1;
	for(SatirListesiNode *itr = head; itr->next != NULL && i!= index; itr->next, i++)
	{
		prv = prv->next;
	}
	return prv;
}

SatirListesi::SatirListesi()
{
	head = NULL;
	size = 0;
}

int SatirListesi::Count() const
{
	return size;
}

bool SatirListesi::isEmpty() const
{
	return size == 0;
}
void SatirListesi::add(const int& item) 
{
    insert(size, item);
}

void SatirListesi::insert(int index, const int& item) 
{
    if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) 
	{
        head = new SatirListesiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } 
	else 
	{
        SatirListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new SatirListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL) prv->next->next->prev = prv->next;
    }
    size++;
}

int SatirListesi::indexOf(const int& item)
{
    int index = 0;
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next) 
	{
        if (itr->data == item) return index;
        index++;
    }
    throw "No Such Element";
}

void SatirListesi::remove(const int& item) 
{
    int index = indexOf(item);
    removeAt(index);
}

void SatirListesi::removeAt(int index) 
{
    if (index < 0 || index >= size) throw "Index out of Range";
	
    SatirListesiNode *del;
    if (index == 0) 
	{
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } 
	else 
	{
        SatirListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}

bool SatirListesi::find(const int& item) 
{
    for (SatirListesiNode *itr = head; itr != NULL; itr = itr->next) 
	{
        if (itr->data == item) return true;
    }
    return false;
}

const int& SatirListesi::elementAt(int index)
{
    if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void SatirListesi::printSatirListesi(int x,int y)
{
    int yIndex=y; 
    ConsolePosition.gotoxy(x,++yIndex);
    cout<<"vvvvvvvvvvv\n"; 
	++yIndex;
    for (SatirListesiNode *itr = this->head; itr != NULL; itr = itr->next) 
	{   
		ConsolePosition.gotoxy(x,++yIndex);
        cout<<" "<<setw(2)<<itr<<"\n";
		
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"-----------\n";
		
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"|"<<setw(5)<<itr->data<<setw(5)<<"|"<<endl;
		
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"-----------\n";
		
        ConsolePosition.gotoxy(x,++yIndex);
        if(itr->next == NULL)
		{
			cout<<"|"<<setw(1)<<"000000000"<<setw(1)<<"|"<<endl;
		}
		else
		{
			cout<<"|"<<setw(1)<<itr->next<<setw(1)<<"|"<<endl;
		}
		
        ConsolePosition.gotoxy(x,++yIndex);
        cout<<"-----------\n\n";
		++yIndex;
    }
}

void SatirListesi::clear() 
{
    while (!isEmpty())
        removeAt(0);
}

SatirListesi::~SatirListesi()
{
	clear();
}