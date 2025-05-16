#pragma once

#include <vector>

template<typename T, typename Predicate = std::less<T>>
class CaPriorityQueue
{
public:
	// O(log n) time complexity for push
	void push(const T& value)
	{
		_heap.push_back(value);

		// 맨 끝 노드부터 맞는 위치를 찾을 때까지
		// Move up the last element until it is in the correct position
		int now = static_cast<int>(_heap.size()) - 1;
		while (now > 0)
		{
			// 부모노드와 비교
			// compare with the parent node
			int next = (now - 1) / 2;
			//if (_heap[now] < _heap[next])
			//{
			//	break;
			//}
			if (_predicate(_heap[now], _heap[next]))
			{
				break;
			}

			// 부모노드가 더 작다면 스왑
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

			// 최하단 리프에 도달한 경우
			if (left >= static_cast<int>(_heap.size()))
			{
				break;
			}

			int next = now;
			// 왼쪽부터 비교해보자
			// Check if the left child is greater than the current node
			if (_heap[next] < _heap[left])
			{
				next = left;
			}

			// 두 노드 중 큰 값을 오른쪽과 비교
			// Check if the right child exists and is greater than the current node
			//if (right < static_cast<int>(_heap.size()) && _heap[next] < _heap[right])
			//{
			//	next = right;
			//}
			if (right < static_cast<int>(_heap.size()) && _predicate(_heap[next], _heap[right]))
			{
				next = right;
			}

			// 좌,우 모두 현재노드보다 작다면 바꿀필요가 없으므로 종료
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
	Predicate _predicate;
};
