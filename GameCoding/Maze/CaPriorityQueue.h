#pragma once

#include <vector>

template<typename T>
class CaPriorityQueue
{
public:
	void push(const T& value)
	{
		_heap.push_back(value);

		int now = static_cast<int>(_heap.size()) - 1;
		while (now > 0)
		{
			int next = (now - 1) / 2;
			if (_heap[now] < _heap[next])
			{
				break;
			}
			std::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;
		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2;

			// Check if the left child exists
			if (left >= static_cast<int>(_heap.size()))
			{
				break;
			}

			int next = now;
			// Check if the left child is greater than the current node
			if (_heap[next] < _heap[left])
			{
				next = left;
			}

			// Check if the right child exists and is greater than the current node
			if (right < static_cast<int>(_heap.size()) && _heap[next] < _heap[right])
			{
				next = right;
			}

			// If the current node is greater than both children, break
			if (next == now)
			{
				break;
			}

			std::swap(_heap[now], _heap[next]);
		}
	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

private:
	std::vector<T> _heap;
};

