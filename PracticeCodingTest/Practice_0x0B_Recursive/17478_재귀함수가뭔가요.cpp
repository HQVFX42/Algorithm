#include <bits/stdc++.h>
using namespace std;

int input;

void underBar(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "____";
	}
}

void chatRecursive(int cnt)
{
	if (cnt == 0)
	{
		cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	}

	underBar(cnt);
	cout << "\"����Լ��� ������?\"\n";
	if (cnt == input)
	{
		underBar(cnt);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else
	{
		underBar(cnt);
		cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		underBar(cnt);
		cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		underBar(cnt);
		cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		chatRecursive(cnt + 1);
	}
	underBar(cnt);
	cout << "��� �亯�Ͽ���.\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> input;	
	chatRecursive(0);
}