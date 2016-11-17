#pragma once
#include "Node.hpp"

template<typename T> class List
{
public:
	List()
	{
		this->First = new Node<T>();
		this->Last = First;

		this->Count = 0;
	}

	int GetCount()
	{
		return this->Count;
	}

	void AddItem(T Item)
	{
		Node<T> *New = new Node<T>();
		New->SetValue(Item);
		New->SetPrevious(this->Last);

		this->Last->SetNext(New);
		this->Last = New;
		this->Count++;
	}

	T GetItem(int Index)
	{
		if (Index < 0 || Index >= this->Count)
			return T();
		else
		{
			Node<T> *C = this->First->GetNext();
			for (int i = 0; i < Index; i++)
				C = C->GetNext();
			return C->GetValue();
		}
	}
private:
	int Count;
	Node<T> *First, *Last;
};