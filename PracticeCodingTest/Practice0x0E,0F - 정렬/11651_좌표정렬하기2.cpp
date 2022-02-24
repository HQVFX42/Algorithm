//#include <bits/stdc++.h>
//using namespace std;
//
//bool compareX(pair<int, int> a, pair<int, int> b)
//{
//	return a.first < b.first;
//}
//bool compareY(pair<int, int> a, pair<int, int> b)
//{
//	return a.second < b.second;
//}
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n;
//	cin >> n;
//	vector<pair<int, int>> ans(n);
//	for (auto& i : ans)
//	{
//		cin >> i.first >> i.second;
//	}
//	stable_sort(ans.begin(), ans.end(), compareX);
//	stable_sort(ans.begin(), ans.end(), compareY);
//	for (auto i : ans)
//	{
//		cout << i.first << ' ' << i.second << '\n';
//	}
//}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	pair<int, int> ans[100001];
	for (int i = 0; i < n; i++)
	{
		cin >> ans[i].second >> ans[i].first;
	}
	sort(ans, ans + n);
	for (int i = 0; i < n; i++)
	{
		cout << ans[i].second << ' ' << ans[i].first << '\n';
	}
}