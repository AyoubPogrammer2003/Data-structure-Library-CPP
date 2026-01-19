#pragma once
#include"clsMyQueueArr.h"

template <class T >
class clsMyStackArr :public clsMyQueueArr <T>
{

	void push(T Item)
	{
		clsMyQueueArr<T>::_MyList.InsertAtBeginning(Item);
	}

	T Top()
	{
		return clsMyQueue <T>::front();
	}

	T Bottom()
	{
		return clsMyQueue <T>::back();
	}

};

