#pragma once
#include "List.hpp"

template<typename T> class Queue
{
public:
	Queue() : items() { }

	int GetCount() { return items.GetCount(); }
	void Enqueue(T Item) { items.AddItem(Item); }
	T Dequeue()
	{
		if (items.GetCount() > 0)
		{
			T Item = items.GetItem(0);
			items.RemoveAt(0);

			return Item;
		}
		else
			return T();
	}

private:
	List<T> items;
};