#pragma once

#include <assert.h>

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr) {}
	Iterator(T* ptr) : _ptr(ptr) {}

	// 전위형++(++it)
	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}
	// 후위형++(it++)
	Iterator& operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}
	Iterator& operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	bool operator==(const Iterator& other)
	{
		return _ptr == other._ptr;
	}
	bool operator!=(const Iterator& other)
	{
		return _ptr != other._ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr = nullptr;
};

template<typename T>
class CaVector
{
	//using T = Pos;

public:
	using iterator = Iterator<T>;

	iterator begin() { return iterator(&_buffer[0]); }
	iterator end() { return begin() + _size; }

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
		 //TODO : delete?
		_size--;
	}

	T& back()
	{
		assert(_size > 0);
		return _buffer[_size - 1];
	}

	// forcefully change size
	void resize(int size)
	{
		// TODO :
		reserve(size);
		_size = size;
	}

	// allocate
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

	bool empty()
	{
		return _size == 0;
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
	int _size = 0;		// 데이터 개수
	int _capacity = 0;	// 할당한 전체 크기
};

