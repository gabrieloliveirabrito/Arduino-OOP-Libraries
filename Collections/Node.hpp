#pragma once

template<typename T> class Node
{
public:
	Node() : Previous(), Next()
	{

	}

	Node<T> *GetPrevious() { return this->Previous; }
	void SetPrevious(Node<T> *Previous) { this->Previous = Previous; }
	Node<T> *GetNext() { return this->Next; }
	void SetNext(Node<T> *Next) { this->Next = Next; }

	T GetValue() { return this->Value; }
	void SetValue(T Value) { this->Value = Value; }
private:
	Node<T> *Previous, *Next;
	T Value;
};