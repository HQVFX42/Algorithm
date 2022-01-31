#include <bits/stdc++.h>
using namespace std;
// R : 0.5s, 512MB
// N = 2^k, M = 2^2k (0 < k <= 15)
pair<int, int> HilbertCurveRecursive(int side, int walk)
{
	// 가장 작은 사각형의 길이는 N = 2^1
	if (side == 2)
	{
		switch (walk)
		{
		case 0:
			return { 1,1 };
		case 1:
			return { 1,2 };
		case 2:
			return { 2,2 };
		case 3:
			return { 2,1 };
		default:
			cout << "unknown type" << walk << '\n';
			break;
		}
	}

	int half = side * 0.5;
	int quadrant = (half * half);

	pair<int, int> coord;
	switch (walk / quadrant)
	{
	case 0:	// quadrant 3
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { coord.second, coord.first };
	case 1:	// quadrant 2
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { coord.first, coord.second + half };
	case 2:	// quadrant 1
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { coord.first + half, coord.second + half };
	case 3:	// quadrant 4
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { 2 * half - coord.second + 1, half - coord.first + 1};
	default:
		cout << "unknown type" << walk / quadrant << '\n';
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int side, walk;
	cin >> side >> walk;
	pair<int, int> ans = HilbertCurveRecursive(side, walk - 1);
	cout << ans.first << ' ' << ans.second;
}