#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsMyDynamicArray
{

protected:
    int _Size = 0;
    T* _TempArray;

public:
    T* OriginalArray;

    clsMyDynamicArray(int Size = 0)
    {
        if (Size < 0)
            Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];

    }

    ~clsMyDynamicArray()
    {

        delete[]  OriginalArray;

    }

    bool SetItem(int index, T Value)
    {

        if (index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[index] = Value;
        return true;

    }


    int Size()
    {
        return _Size;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false);

    }

    void PrintList()
    {

        for (int i = 0; i <= _Size - 1; i++)
        {
            cout << OriginalArray[i] << " ";
        }

        cout << "\n";

    }

    void Resize(short New_size)
    {
        if (New_size <= 0) { New_size = 0; }

        if (New_size == _Size) { return; }

        T* _TempArray = new T[New_size];

        int Limit = (New_size < _Size) ? New_size : _Size;
      
        for (int i = 0; i < Limit; i++)
        {
            _TempArray[i] = OriginalArray[i];
        };
        
        delete[] OriginalArray;
        OriginalArray = _TempArray;
        _Size = New_size;
    }

    T GetItem(int Index)
    {
     //   if (Index < 0 || Index > _Size - 1) { return; }
        return OriginalArray[Index];
    }

    void Reverse()
    {
        _TempArray = new T[_Size];
        for (int i = 0; i < _Size; i++)
        {
            _TempArray[i] = OriginalArray[(_Size - 1) - i];
        }
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

    bool DeleteItemAt(int Index)
    {

        if (Index < 0 || Index >= _Size)
        {
            return false;
        };


        _Size--;
        _TempArray = new T[_Size];

        //copy all  before index 
        for (int i = 0; i < Index; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        //copy all after index
        for (int i = Index + 1; i < _Size + 1; i++)
        {
            _TempArray[i - 1] = OriginalArray[i];
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

        
    }

    bool DeleteFirstItem()
    {
        return DeleteItemAt(0);
    }
       
    bool DeleteLastItem()
    {
        return DeleteItemAt(_Size - 1);
    }

    int Find(T Value)
    {
        for (int i = 0; i < _Size; i++)
        {
            if (OriginalArray[i] == Value)
                return i;
        }
        return -1;
    }
    
    bool DeleteItemByValue(T Value)
    {
        int Index = Find(Value);

        if (Index == -1)
        {
            return false;
        }
        DeleteItemAt(Index);
        return true;
    }
    
    bool InsertAt(int Index, T Value)
    {
        if (Index < 0 || Index > _Size)
            return false;

        _Size++;

        _TempArray = new T[_Size];

        int i = 0;
        //copy all  before index 
        for (i = 0; i < Index; i++)
            _TempArray[i] = OriginalArray[i];

        _TempArray[i] = Value;

        //copy all after index
        for (int j = Index ; j < _Size ; j++)
            _TempArray[j + 1] = OriginalArray[j];

        delete[] OriginalArray;
        OriginalArray = _TempArray;
        return true;

    }

    void InsertAtBeginning(T value)
    {

        InsertAt(0, value);

    }


    bool InsertBefore(int index, T value)
    {
        if (index < 1)
            return InsertAt(0, value);
        else
            return InsertAt(index - 1, value);

    }

    bool InsertAfter(int index, T value)
    {
        if (index >= _Size)
            return InsertAt(_Size , value);
        else
            return InsertAt(index + 1, value);;

    }

    bool InsertAtEnd(T value)
    {

        return InsertAt(_Size, value);

    }

};
