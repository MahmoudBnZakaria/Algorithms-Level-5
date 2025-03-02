#pragma once

#include <iostream>
#include "clsMyQueue.h"
using namespace std;
template <class T>

class  clsMyStack:public   clsMyQueue <T>
{

public :
	
	void push(T Item) {
		clsMyQueue<T>::_MyList.InsertAtBeginning(Item);
	}
	
	T Top() {
		return clsMyQueue<T>::_MyList.front();
	}

	T Bottom() {
		return clsMyQueue<T>::_MyList.back();
	}
};

