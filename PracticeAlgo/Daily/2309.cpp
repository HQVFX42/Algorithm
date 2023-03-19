#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }
void fastIO() { ios::sync_with_stdio(false); cin.tie(nullptr); }

string split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);

	string output;
	for (auto& i : ret)
	{
		output += i;
	}
	return output;
}

struct Node
{
	int color; // 방의 색 (0: 흰색, 1: 빨간색, 2: 파란색)
	vector<int> adj; // 인접한 방의 번호
};

vector<Node> nodes;
int n, m;

int bfs(int start)
{
	queue<int> q;
	vector<bool> visited(n + 1, false);
	int Cnt = 0;
	q.push(start);
	visited[start] = true;
	nodes[start].color = 1;
	Cnt++;

	while (!q.empty()) 
	{
		int cur = q.front();
		q.pop();

		for (int next : nodes[cur].adj)
		{
			if (!visited[next])
			{
				if (nodes[cur].color == 1) 
				{
					nodes[next].color = 2;
				}
				else if (nodes[cur].color == 2) 
				{
					nodes[next].color = 1;
					Cnt++;
				}

				q.push(next);
				visited[next] = true;
			}
		}
	}

	return Cnt;
}

const int MAX_USERS = 8;
const int MAX_TIME = 99;

struct User 
{
    int team;
    int time;
};

void simulate(vector<User>& users) 
{
    int max_score = 0;
    vector<int> winning_teams;
    for (int t = 1; t <= MAX_USERS; t++) 
    {
        int score = 0;
        for (int i = 0; i < MAX_USERS; i++) 
        {
            if (users[i].team == t) 
            {
                if (users[i].time != -1) 
                {
                    int rank = MAX_USERS;
                    for (int j = 0; j < MAX_USERS; j++) 
                    {
                        if (i != j && users[j].time != -1 && users[j].time < users[i].time) 
                        {
                            rank--;
                        }
                    }
                    score += rank;
                }
                else 
                {
                    for (int time = 1; time <= MAX_TIME; time++) 
                    {
                        int rank = MAX_USERS;
                        for (int j = 0; j < MAX_USERS; j++) 
                        {
                            if (i != j && users[j].time != -1 && users[j].time < time)
                            {
                                rank--;
                            }
                        }
                        int temp_score = score + rank;
                        if (temp_score > max_score) 
                        {
                            max_score = temp_score;
                            winning_teams.clear();
                            winning_teams.push_back(t);
                        }
                        else if (temp_score == max_score) 
                        {
                            winning_teams.push_back(t);
                        }
                    }
                    //break;
                }
            }
        }
        if (score > max_score) 
        {
            max_score = score;
            winning_teams.clear();
            winning_teams.push_back(t);
        }
        else if (score == max_score)
        {
            winning_teams.push_back(t);
        }
    }
    
    winning_teams.erase(unique(winning_teams.begin(), winning_teams.end()), winning_teams.end());
    for (int i = 0; i < winning_teams.size(); i++) 
    {
        cout << winning_teams[i];
    }
}

int main() {
    vector<User> users(MAX_USERS);
    for (int i = 0; i < MAX_USERS; i++) 
    {
        cin >> users[i].team >> users[i].time;
    }
    simulate(users);

    return 0;
}