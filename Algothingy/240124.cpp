#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

static bool OOB(int x, int y, int n, int m) { return x < 0 or x >= n or y < 0 or y >= m; }

void fastIO()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

vector<int> solution1(string& R, vector<int>& V)
{
    int a = 0;
    int b = 0;
    int mnA = 0;
    int mnB = 0;

    for (size_t i = 0; i < R.size(); i++)
    {
        if (R[i] == 'B')
        {
            a -= V[i];
            b += V[i];
        }
        else
        {
            a += V[i];
            b -= V[i];
        }

        mnA = min(mnA, a);
        mnB = min(mnB, b);
    }

    return { abs(mnA), abs(mnB) };
}

struct Pizza
{
    string name;
    int price_S;
    int price_M;
    int price_L;
};

struct OrderItem
{
    string name;
    string size;
    int quantity;
};

int applyDiscount1(vector<Pizza>& menu, vector<OrderItem>& order) {
    int totalCost = 0;

    for (const OrderItem& item : order) {
        // Find the corresponding pizza in the menu
        auto pizza = find_if(menu.begin(), menu.end(), [&](const Pizza& p) {
            return p.name == item.name;
            });

        if (pizza != menu.end()) {
            int price = 0;
            if (item.size == "Small") {
                price = pizza->price_S;
            }
            else if (item.size == "Medium") {
                price = pizza->price_M;
            }
            else if (item.size == "Large") {
                price = pizza->price_L;
            }

            totalCost += price * item.quantity;
        }
    }

    int discountQuantity = 0;
    for (const OrderItem& item : order) {
        if (item.quantity >= 3) {
            discountQuantity += item.quantity / 3;
        }
    }

    int cheapestPizzaPrice = INT_MAX;
    for (const Pizza& pizza : menu) {
        cheapestPizzaPrice = min(cheapestPizzaPrice, pizza.price_S);
        cheapestPizzaPrice = min(cheapestPizzaPrice, pizza.price_M);
        cheapestPizzaPrice = min(cheapestPizzaPrice, pizza.price_L);
    }

    int discountAmount = discountQuantity * cheapestPizzaPrice;
    totalCost -= discountAmount;

    totalCost = max(totalCost, 0);

    return totalCost;
}

int solution(vector<Pizza>& menu, vector<OrderItem>& order) {
    return applyDiscount1(menu, order);
}

vector<int> dr = { -1, 1, 0, 0 };
vector<int> dc = { 0, 0, -1, 1 };

// 건물 계획을 저장하는 2D 배열
vector<string> plan;

// 방문한 영역을 체크하기 위한 배열
vector<vector<bool>> visited;

// DFS를 사용하여 로봇이 청소할 수 있는 방의 개수를 계산하는 함수
int dfs(int r, int c) {
    // 현재 위치를 방문한 것으로 표시
    visited[r][c] = true;

    int result = 0; // 현재 방을 청소한 결과

    // 상, 하, 좌, 우로 이동
    for (int d = 0; d < 4; d++) {
        int nr = r + dr[d];
        int nc = c + dc[d];

        // 이동한 위치가 유효하고, 청소 가능한 영역이면 DFS 호출
        if (nr >= 0 && nr < plan.size() && nc >= 0 && nc < plan[0].size() && plan[nr][nc] != '#' && !visited[nr][nc]) {
            result += dfs(nr, nc);
        }
    }

    return result + 1; // 현재 방을 청소하고 방문한 방의 개수를 반환
}

// 건물 계획을 기반으로 최소 실행 횟수를 계산하는 함수
int solution3(vector<string>& p) {
    plan = p;
    visited.assign(p.size(), vector<bool>(p[0].size(), false));

    int minRuns = 0;

    for (int r = 0; r < p.size(); r++) {
        for (int c = 0; c < p[0].size(); c++) {
            // 청소 가능한 영역이고, 방문하지 않은 영역일 때 DFS 호출
            if (plan[r][c] == '*' && !visited[r][c]) {
                int cleanedRooms = dfs(r, c);
                minRuns += (cleanedRooms - 1);
            }
        }
    }

    return minRuns;
}

int main()
{
	fastIO();

    //** 1 */
    //// 테스트 케이스 1
    //string R1 = "BAABA";
    //vector<int> V1 = { 2, 4, 1, 1, 2 };
    //vector<int> result1 = solution1(R1, V1);
    //cout << "Test Case 1: [" << result1[0] << ", " << result1[1] << "]" << endl;

    //// 테스트 케이스 2
    //string R2 = "ABAB";
    //vector<int> V2 = { 10, 5, 10, 5 };
    //vector<int> result2 = solution1(R2, V2);
    //cout << "Test Case 2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    //// 테스트 케이스 3
    //string R3 = "B";
    //vector<int> V3 = { 100 };
    //vector<int> result3 = solution1(R3, V3);
    //cout << "Test Case 3: [" << result3[0] << ", " << result3[1] << "]" << endl;

    //** 2 */
    vector<Pizza> menu = {
        {"greek", 7, 5, 10},
        {"texas", 8, 9, 13},
        {"european", 5, 10, 13}
    };

    vector<OrderItem> order = {
        {"texas", "Medium", 1},
        {"european", "Small", 2}
    };

    int result = solution(menu, order);
    cout << "Total Cost: " << result << endl;

    //** 3 */
    //vector<string> plan1 = { "..####", "..#.*#", "###*.#", "#.####","#.#...","###..." };
    //cout << solution3(plan1) << endl; // 1

    //vector<string> plan2 = { "..####","..#.*#","###..#","#*####","#.#...","###..." };
    //cout << solution3(plan2) << endl; // 2

    //vector<string> plan3 = { "##########","#....*.**#","##########" };
    //cout << solution3(plan3) << endl; // 1

    return 0;
}