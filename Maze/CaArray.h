#pragma once
#include <assert.h>

class CaArray
{
	using T = int;

public:
	explicit CaArray(int capacity = 100)
		: _capacity(capacity)
	{
		_buffer = new T[_capacity];
	}
	~CaArray()
	{
		delete[] _buffer;
	}

	void push_back(const T& data)
	{
		if (_size == _capacity)
		{
			return;
		}

		_buffer[_size] = data;
		_size++;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < _size);
		return _buffer[index];
	}

	int size()
	{
		return _size;
	}
	int capacity()
	{
		return _capacity;
	}

private:
	T* _buffer = nullptr;
	int _size = 0;		// �������� ����
	int _capacity = 0;	// �Ҵ��� ��ü ũ��
};

