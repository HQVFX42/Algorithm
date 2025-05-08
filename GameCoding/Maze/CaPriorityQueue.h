#pragma once

#include <vector>

template<typename T>
class CaPriorityQueue
{
public:
	// O(log n) time complexity for push
	void push(const T& value)
	{
		// heap structure is a complete binary tree
		_heap.push_back(value);

		// Move up the last element until it is in the correct position
		int now = static_cast<int>(_heap.size()) - 1;
		while (now > 0)
		{
			// compare with the parent node
			int next = (now - 1) / 2;
			if (_heap[now] < _heap[next])
			{
				break;
			}

			// if the current node is greater than the parent node,
			// swap with the parent node
			std::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(log n) time complexity for pop
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

	// O(1) time complexity for top
	T& top()
	{
		return _heap[0];
	}

	// O(1) time complexity for empty
	bool empty()
	{
		return _heap.empty();
	}

private:
	std::vector<T> _heap;
};

