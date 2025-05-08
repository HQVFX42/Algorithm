#pragma once

#include "CaVector.h"

/**
 * empty : [front/back][][][][][].
 * push : [front][back][][][][][].
 */
template<typename T>
class CaQueue
{
public:
	CaQueue()
	{
		_container.resize(100);
	}

	void push(const T& value)
	{
		// TODO : check if full
		if (_size == _container.size())
		{

		}

		_container[_back] = value;
		_back = (_back + 1) % _container.size();	// circular
		_size++;
	}

	void pop()
	{
		_front = (_front + 1) % _container.size();	// circular
		_size--;
	}

	T& front()
	{
		return _container[_front];
	}

	bool empty()
	{
		return _size == 0;;
	}

private:
	CaVector<T> _container;

	int _front = 0;
	int _back = 0;
	int _size = 0;
};

