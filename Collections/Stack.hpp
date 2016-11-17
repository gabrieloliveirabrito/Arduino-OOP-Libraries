#pragma once
#include "List.hpp"

template<typename T> class Stack
{
public:
	Stack() : items() { }

	int GetCount() { return items.GetCount(); }
	void Push(T Item) { items.AddItem(Item); }
	T Pop()
	{
		if (items.GetCount() > 0)
		{
			T Item = items.GetItem(items.GetCount() - 1);
			items.RemoveAt(items.GetCount() - 1);

			return Item;
		}
		else
			return T();
	}

private:
	List<T> items;
};