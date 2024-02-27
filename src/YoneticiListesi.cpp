/**
* @file 		YoneticiListesi.cpp
* @description  Yonetici listesi için oluşturduğum sınıf
* @course 		2.Öğretim - A Grubu
* @assignment   1.Ödev
* @date Kodu 	04.11.2022
* @author 		Enes Kartancı
*/

#include "YoneticiListesi.hpp"

YoneticiListesiNode* YoneticiListesi::FindPreviousByPosition(int index)
{
	if (index < 0 || index > size) throw "No Such Element";
    YoneticiListesiNode *prv = head;
    int i = 1;
    for (YoneticiListesiNode *itr = head; itr->next != NULL && i != index; itr = itr->next, i++) 
	{
        prv = prv->next;
    }
    return prv;
}

YoneticiListesi::YoneticiListesi()
{
	head = NULL;
	size = 0;
}

int YoneticiListesi::Count() const
{
	return size;
}

bool YoneticiListesi::isEmpty() const
{
	return size == 0;
}

void YoneticiListesi::add(SatirListesi*& item)
{
	insert(size, item);
}

void YoneticiListesi::insert(int index, SatirListesi*& item)
{
	if (index < 0 || index > size) throw "Index out of Range";
    if (index == 0) 
	{
        head = new YoneticiListesiNode(item, head);
        if (head->next != NULL) head->next->prev = head;
    } 
	else 
	{
        YoneticiListesiNode *prv = FindPreviousByPosition(index);
        prv->next = new YoneticiListesiNode(item, prv->next, prv);
        if (prv->next->next != NULL) prv->next->next->prev = prv->next;
    }
    size++;
}

SatirListesi*& YoneticiListesi::first()
{
	if (isEmpty()) throw "No Such Element";
    return head->data;
}

SatirListesi*& YoneticiListesi::last()
{
	if (isEmpty()) throw "No Such Element";
    return FindPreviousByPosition(size)->data;
}

int YoneticiListesi::indexOf(SatirListesi*& item)
{
	int index = 0;
    for (YoneticiListesiNode *itr = head; itr != NULL; itr = itr->next) 
	{
        if (itr->data == item) return index;
        index++;
    }
    throw "No Such Element";
}

void YoneticiListesi::remove(SatirListesi*& item)
{
	int index = indexOf(item);
    removeAt(index);
}

void YoneticiListesi::removeAt(int index)
{
	if (index < 0 || index >= size) throw "Index out of Range";
	
    YoneticiListesiNode *del;
    if (index == 0) 
	{
        del = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } 
	else 
	{
        YoneticiListesiNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if (del->next != NULL) del->next->prev = prv;
    }
    size--;
    delete del;
}

bool YoneticiListesi::find(SatirListesi*& item)
{
	for (YoneticiListesiNode *itr = head; itr != NULL; itr = itr->next) 
	{
        if (itr->data == item) return true;
    }
    return false;
}

SatirListesi*& YoneticiListesi::elementAt(int index)
{
	if (index < 0 || index >= size) throw "No Such Element";
    if (index == 0) return head->data;
    return FindPreviousByPosition(index)->next->data;
}

void YoneticiListesi::averageCalculate(int index)
{
	YoneticiListesiNode* yoneticiListesi = this->FindPreviousByPosition(index+1);
    if (yoneticiListesi == NULL) 
	{
        throw "List is Empty";
    }

    double result = 0;
    if (yoneticiListesi->data->isEmpty()) 
	{
        yoneticiListesi->average = result;
        return;
    }

    int count = yoneticiListesi->data->Count();
    for (int i = 0; i < count; ++i) 
	{
        result += yoneticiListesi->data->elementAt(i);
    }
    yoneticiListesi->average = result / count;
}

int YoneticiListesi::randomGenerator(int index)
{
	int count = this->Count();
	if (index < 0 || index >= count) throw "No Such Element";
	
	srand(time(NULL));
	SatirListesi* satirListesi = this->elementAt(index);
	int randomSize = satirListesi->Count();
	if(randomSize == 0)
	{
		throw "No Such Element";
	}
	
	int randomNumber = rand() % randomSize;
	return randomNumber;
}

void YoneticiListesi::randomRemoveAtSatirListesi(int index, int randomNumber)
{
	int count = this->Count();
	if (index < 0 || index >= count) throw "No Such Element";
	
	SatirListesi* satirListesi = this->elementAt(index);
	satirListesi->removeAt(randomNumber);
	averageCalculate(index);
}

void YoneticiListesi::clear()
{
	while(!isEmpty())
		removeAt(0);
}

void YoneticiListesi::nodePlacement(int fplace, int lplace)
{
	if (fplace < 0 || fplace >= size) throw "Index out of range";
	YoneticiListesiNode *del;
	if(fplace == 0)
	{
		del = head;
		head = head->next;
		if(head != NULL) head->prev = NULL;
	}
	else
	{
		YoneticiListesiNode *prv = FindPreviousByPosition(fplace);
		del = prv->next;
		prv->next = del->next;
		if(del->next != NULL) del->next->prev = prv;
	}
	size--;
	
	if (lplace < 0 || lplace > size) throw "Index out of range";
	if(lplace == 0)
	{
		del->next = head;
		del->prev = NULL;
		head = del;
		if(head->next != NULL) head->next->prev = head;
	}
	else
	{
		YoneticiListesiNode *prv = FindPreviousByPosition(lplace);
		del->next = prv->next;
		del->prev = prv;
		prv->next = del;
		if(prv->next->next != NULL) prv->next->next->prev = prv->next;
	}
	size++;
}

void YoneticiListesi::sortByAverage()
{
	if(this->size <=1) return;
	
	for(int index = 0; index < size; ++index)
	{
		for(int i = 0; i < size-1-index; ++i)
		{
			YoneticiListesiNode *tmp1 = this->FindPreviousByPosition(i+1);
			YoneticiListesiNode *tmp2 = tmp1->next;
			
			if(tmp1->average > tmp2->average)
				this->nodePlacement(i+1, i);
		}
	}
}

void YoneticiListesi::printIndexOfYonetici(int index, int x, int y)
{
	YoneticiListesiNode *tmp = this->FindPreviousByPosition(index+1);
		
	ConsolePosition.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout <<" "<<setw(2)<< tmp << "\n";
	
    ConsolePosition.gotoxy(x, y + 1);
    cout << "-----------\n";
	
    ConsolePosition.gotoxy(x, y + 2);
  //  cout << "|" << tmp->prev << setw(3) << "|\n";
	if(tmp->prev == NULL)
	{
		cout<<"|"<<setw(1)<<"000000000"<<setw(1)<<"|"<<endl;
	}
	else
	{
		cout<<"|"<<tmp->prev<<setw(1)<<"|"<<endl;
	}
	
    ConsolePosition.gotoxy(x, y + 3);
    cout << "-----------\n";
	
    ConsolePosition.gotoxy(x, y + 4);
    cout << "|" <<setw(2) << " "<< tmp->average <<" "<< setw(2) << "|" << endl;
	
    ConsolePosition.gotoxy(x, y + 5);
    cout << "-----------\n";
	
    ConsolePosition.gotoxy(x, y + 6);
	if(tmp->next == NULL)
	{
		cout<<"|"<<setw(1)<<"000000000"<<setw(1)<<"|"<<endl;
	}
	else
	{
		cout<<"|"<<setw(1)<<tmp->next<<setw(1)<<"|"<<endl;
	}
	
    ConsolePosition.gotoxy(x, y + 7);
    cout << "-----------\n\n";
}

YoneticiListesi::~YoneticiListesi()
{
	clear();
}