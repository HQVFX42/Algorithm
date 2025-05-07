#pragma once
#include <assert.h>

class CaVector
{
	using T = int;

public:
	explicit CaVector()
	{
	}
	~CaVector()
	{
		if (_buffer)
		{
			delete[] _buffer;
		}
	}

	void clear()
	{
		if (_buffer)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}
		_size = 0;
	}

	void push_back(const T& data)
	{
		if (_size == _capacity)
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)	// capacity가 0이나 1인경우
			{
				newCapacity++;
			}

			reserve(newCapacity);
		}

		_buffer[_size] = data;
		_size++;
	}

	void pop_back()
	{
		_size--;
	}

	T& back()
	{
		assert(_size > 0);
		return _buffer[_size - 1];
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
		{
			return;
		}

		_capacity = capacity;

		T* newData = new T[_capacity];
		for (int i = 0; i < _size; i++)
		{
			newData[i] = _buffer[i];
		}

		if (_buffer)
		{
			delete[] _buffer;
		}

		_buffer = newData;
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
	int _size = 0;		// 데이터의 개수
	int _capacity = 0;	// 할당한 전체 크기
};

