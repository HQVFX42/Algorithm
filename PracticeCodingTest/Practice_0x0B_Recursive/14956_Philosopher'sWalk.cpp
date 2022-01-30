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
		case 1:
			return { 1,1 };
		case 2:
			return { 1,2 };
		case 3:
			return { 2,2 };
		case 4:
			return { 2,1 };
		default:
			break;
		}
		/*if (walk == 1)
		{
			return { 1, 1 };
		}
		if (walk == 2)
		{
			return { 1, 2 };
		}
		if (walk == 3)
		{
			return { 2, 2 };
		}
		if (walk == 4)
		{
			return { 2, 1 };
		}*/
	}

	int half = side * 0.5;
	int quadrant1 = half * half * 3;
	int quadrant2 = half * half * 2;
	int quadrant3 = half * half;
	int quadrant4 = half * half * 4;
	int quadrant = (half * half);
	//if (walk <= quadrant1) // quadrant 1
	//{
	//	pair<int, int> coord = HilbertCurveRecursive(half, walk - quadrant2);
	//	return { coord.second + half, coord.first + half };
	//}
	//else if (walk <= quadrant2) // quadrant 2
	//{
	//	pair<int, int> coord = HilbertCurveRecursive(half, walk - quadrant3);
	//	return { coord.second, coord.first + half };
	//}
	//else if (walk <= quadrant3) // quadrant 3
	//{
	//	pair<int, int> coord = HilbertCurveRecursive(half, walk);
	//	return { coord.second, coord.first };
	//}
	//else	// quadrant 4
	//{
	//	pair<int, int> coord = HilbertCurveRecursive(half, walk - quadrant1);
	//	return { 2 * half - coord.second + 1, half - coord.first + 1 };
	//}
	pair<int, int> coord;
	switch (walk / quadrant)
	{
	case 0:
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { coord.second, coord.first };
	case 1:
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { coord.first, coord.second + half };
	case 2:
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { coord.first + half, coord.second + half };
	case 3:
		coord = HilbertCurveRecursive(half, walk % quadrant);
		return { 2 * half - coord.second + 1, half - coord.first + 1 };
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int side, walk;
	cin >> side >> walk;
	pair<int, int> ans = HilbertCurveRecursive(side, walk);
	cout << ans.first << ' ' << ans.second;
}