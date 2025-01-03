# :spiral_notepad:Note
- 파일분할 및 파일정리 진행중...  
![1%](https://progress-bar.xyz/1/?scale=100&title=progress&width=512&color=babaca&suffix=/100)

## Flow
1. 문제의 최대, 최소 범위를 파악한다
    - 평균 1억, 1000만이하는 OK -> 완전탐색을 써도 된다
	- 만약 최대값이나 최소값을 구하는 문제일 경우 출력값 범위에 해당하지 않는 숫자로 초기화를 해야한다
1. 최대범위 기반, 시간복잡도상 -> 무식하게 풀 수 있다면 무식하게 모든 경우의 수를 생각하면서 풀고(Brute Force)
1. 아니라면 다른 알고리즘
    - ? -> 완탐? -> DP? -> 그리디?
	- ? -> Sorted Array? -> 이분탐색?
	- Counting = Map or Array로 접근
	- 짝짓기, 폭발, 아름다운 괄호만들기 등 = Stack으로 접근
	- Tree의 경우 Root부터 탐색을 하는 것이 좋다
1. 반례를 생각하자

## Tips
- 문제를 먼저 해석하고 손코딩을 해보자
- 지역변수 보다는 전역변수를 사용하자
    - 지역변수로 선언하게 되면 stack에 쌓이는데 OS에서 성능상의 이유로 stack영역에 메모리 제한이 걸림
	- 전역변수에서 int형 배열 100만개 선언도 가능하지만 지역변수에서는 25만까지 가능하다고 알려져 있음

<br>

## 1
-

<br>

## 2
- 이진트리?
    - 자식노드의 수가 2 이하인 것
- `균형 이진트리?`
    - 트리의 모든 노드에 대해, 그 노드의 왼쪽 하위 트리와 오른쪽 하위 트리의 높이 차이가 1 이하인 이진 트리
	- 이러한 균형 덕분에 탐색, 삽입, 삭제 등의 연산에서 시간복잡도가 O(log n)으로 보장
	- AVL, Red-Black Tree(map, set)

<br>

## 3
- `완전탐색?` => 모든 경우의 수를 탐색하는 알고리즘
- 반복문으로 되면 무조건 반복문으로 해결할 것
    - 너무 복잡하거나 조합, 순열, DFS, BFS등은 재귀함수로 하는것이 나음
    - 순서와 관계가 있다 -> 순열
    - 순서와 관계가 없다 -> 조합
- `백트래킹?` => 최대한 가지치기를 하는 완전탐색 = 불필요한 탐색을 피한다
- `원복?` => 방문배열을 통해 방문한 점점은 방문처리를 하면서  
다음 경우의 수에 영향을 미치지 않도록 원상복구를 해줘야한다
	```cpp
	Go(int here)
	{
    	visited[there] = 1;
		v.push_back(there);
		Go(there);
		visited[there] = 0;
		v.pop_back();
	}
	```

---
# :clipboard:Lists

## 1
| Problem | Description | Code | Status |
| :--: | :--: | :--: | :--: |
| [BOJ 1940](https://www.acmicpc.net/problem/1940) | [주몽](#1940-주몽) | [Code](./Algothingy/1940.cpp), [Code-1](./Algothingy/1940-1.cpp) | :ballot_box_with_check: |
| [BOJ 3986](https://www.acmicpc.net/problem/3986) | [좋은단어](#3986-좋은단어) | [Code](./Algothingy/3986.cpp) | :ballot_box_with_check: |

<br>

## 2
| Problem | Description | Code | Status |
| :--: | :--: | :--: | :--: |
| [BOJ 2870](https://www.acmicpc.net/problem/2870) | [수학숙제](#2870-수학숙제) | [Code](./Algothingy/2870.cpp) | :ballot_box_with_check: |
| [BOJ 10709](https://www.acmicpc.net/problem/10709) | [기상캐스터](#10709-기상캐스터) | [Code](./Algothingy/10709.cpp) | :ballot_box_with_check: |
| [BOJ 3474](https://www.acmicpc.net/problem/3474) | [교수가 된 현우](#3474-교수가-된-현우) | [Code](./Algothingy/3474.cpp) | :ballot_box_with_check: |
| [BOJ 2852](https://www.acmicpc.net/problem/2852) | [NBA 농구](#2852-NBA-농구) | [Code](./Algothingy/2852.cpp) | :ballot_box_with_check: |
| [BOJ 1436](https://www.acmicpc.net/problem/1436) | [영화감독 숌](#1436-영화감독-숌) | [Code](./Algothingy/1436.cpp) | :ballot_box_with_check: |
| [BOJ 9012](https://www.acmicpc.net/problem/9012) | [괄호](#9012-괄호) | [Code](./Algothingy/9012.cpp) | :ballot_box_with_check: |
| [BOJ 4949](https://www.acmicpc.net/problem/4949) | [균형잡힌 세상](#4949-균형잡힌-세상) | [Code](./Algothingy/4949.cpp) | :ballot_box_with_check: |
| [BOJ 14502](https://www.acmicpc.net/problem/14502) | [연구소](#14502-연구소) | [Code](./Algothingy/14502.cpp) | :ballot_box_with_check: |
| [BOJ 2636](https://www.acmicpc.net/problem/2636) | [치즈](#2636-치즈) | [Code](./Algothingy/2636.cpp) | :ballot_box_with_check: |
| [BOJ 1068](https://www.acmicpc.net/problem/2636) | [트리](#1068-트리) | [Code](./Algothingy/1068.cpp) |  |
| [BOJ 1325](https://www.acmicpc.net/problem/1325) | [효율적인 해킹](#1325-효율적인-해킹) | [Code](./Algothingy/1325.cpp) | :ballot_box_with_check: |
| [BOJ 17298](https://www.acmicpc.net/problem/17298) | [오큰수](#17298-오큰수) | [Code](./Algothingy/17298.cpp) | :ballot_box_with_check: |

<br>

## 3
| Problem | Description | Code | Status |
| :--: | :--: | :--: | :--: |
| [BOJ 15686](https://www.acmicpc.net/problem/15686) | [치킨 배달](#15686-치킨-배달) | [Code](./Algothingy/15686.cpp) |  |
| [BOJ 1816](https://www.acmicpc.net/problem/1816) | [암호 키](#1816-암호-키) | [Code](./Algothingy/1816.cpp) | :ballot_box_with_check: |
| [BOJ 14568](https://www.acmicpc.net/problem/14568) | [2017 연세대학교 프로그래밍 경시대회](#14568-2017-연세대학교-프로그래밍-경시대회) | [Code](./Algothingy/14568.cpp) | :ballot_box_with_check: |
| [BOJ 19532](https://www.acmicpc.net/problem/19532) | [수학은 비대면강의입니다](#19532-수학은-비대면강의입니다) | [Code](./Algothingy/19532.cpp), [Code-1](./Algothingy/19532-1.cpp) | :ballot_box_with_check: |
| [BOJ 2503](https://www.acmicpc.net/problem/2503) | [숫자 야구](#2503-숫자-야구) | [Code](./Algothingy/2503.cpp) | :ballot_box_with_check: |

<br>

---
# :droplet:Descriptions
## 1
### 1940 주몽
- 이중 for문을 통해 전체 탐색을 하는 방법이 있다
	```cpp
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (a[i] + a[j] == m)
				{
					cnt++;
				}
			}
		}
	```
- 재귀를 이용한 방법
	```cpp
	void Combi(int idx, vector<int> & v)
	{
		if (v.size() == 2)
		{
			int b = a[ v[ 0 ] ];
			int c = a[ v[ 1 ] ];
			if (b + c == m)
			{
				cnt++;
			}

			return;
		}

		for (int i = idx + 1; i < n; i++)
		{
			v.push_back(i);
			Combi(i, v);
			v.pop_back();
		}
	}
	```
- 투포인터를 이용한 방법
	```cpp
	```

<br>

### 3986 좋은단어
- stack에 담아 짝짓기를 해주면 해결 가능하다
- 다음에 오는 단어가 `같은 단어면 pop`, 아니라면 push
- 즉, `stack이 비어있다`면 좋은단어고 아니라면 좋은단어가 아니다

<br>

## 2
### 2870 수학숙제
* 범위가 100글자라고 하였으니 자료형을 생각해보아야 한다  
int는 약 10자리 정도만 커버할 수 있고  
long long은 약 19자리까지 가능하다

* 때문에 string을 사용할 생각을 하자

* 소문자 알파벳은 버리고 주어진 숫자만 담으려면  
정수는 아스키코드 소문자 알파벳보다 작은 것을 활용하면 된다 `65~97은 문자`
`if (a < 'a')` or `if (a < 65)`

* 0000 같은 반례를 조심하자

* 문자열을 기반으로 비교를 하려면 custom operator가 필요하다
	```cpp
	sort(V.begin(), V.end(),
			[ & ] (const string Lhs, const string Rhs)
			{
				if (Lhs.size() == Rhs.size())
				{
					return Lhs < Rhs;
				}
				return Lhs.size() < Rhs.size();
			});
	```

<br>

* front같이 참조를 할 때는 size가 있는지 항상 체크하자
	```cpp
	if(Result.size() and Result.front() == '0')
	```

<br>

### 10709 기상캐스터
* 입력받은 string에 구름이 있으면 0 아니면 -1로 int 배열 초기화

* 전체 배열을 탐색해서 해당 인덱스 원소의 값이 0이면 카운트 1부터  
다음 인덱스 원소가 -1이 아닐 때까지 ++를 해주면 쉽게 해결할 수 있다
	```cpp
	for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (A[i][j] == 0)
				{
					int Cnt = 1;
					while (A[i][j+1] == - 1)
					{
						A[ i ][ j + 1 ] = Cnt++;
						j++;
					}
				}
			}
		}
	```

<br>

### 3474 교수가 된 현우
* 주어진 정수는 10억이하이므로 N!을 직접 구할 수 없다  
또한 10억을 왼쪽에서부터 오른쪽으로 차례대로 탐색하는 것도 무리가 있다

* 이 문제의 포인트는 0의 개수를 구하는 것이므로 10을 몇개를 만들 수 있느냐를 구하는 문제가 된다
즉 `2의 개수 와 5의 개수가 몇개인지`를 구하는 문제

<br>

* 예를 들어 10!의 0의 개수를 구한다고 하면 -> 1,2,3,4,5,6,7,8,9,10  
2는 8개(2 5개 + 4 2개 + 8 1개), 5는 2개  
결국 2의 승수, 5의 승수를 나눈 값들을 더해 min값을 구하면 원하는 결과를 얻을 수 있다
	```cpp
			for (int i = 2; i <= N; i *= 2)
			{
				A2 += N / i;
			}
			for (int j = 5; j <= N; j *= 5)
			{
				A5 += N / j;
			}

			cout << min(A2, A5) << '\n';
	```

<br>

### 2852 NBA 농구
* 시간이 나올 때 하나의 단위로 변환 후 통일해서 계산하는 것이 좋다
	```cpp
	int ChangeToInt(string S)
	{
		return atoi(S.substr(0, 2).c_str()) * 60 + atoi(S.substr(3, 2).c_str());
	}
	```

<br>

* 초를 다시 MM:SS 형식으로 변환
	```cpp
	string ChangeToString(int N)
	{
		string Minutes = "00" + to_string(N / 60);
		string Seconds = "00" + to_string(N % 60);
		return Minutes.substr(Minutes.size() - 2, 2) + ':' + Seconds.substr(Seconds.size() - 2, 2);
	}
	```

<br>

* prev를 이용하여 그 전 득점 타임과 차이를 계산해서 각 팀에 합산해 주면 해결할 수 있다  
단, 종료시간인 `48:00`을 꼭 마지막에 체크해야 함에 유의해야 한다
	```cpp
	string Prev;
	void Func(int & Sum, string S)
	{
		Sum += ChangeToInt(S) - ChangeToInt(Prev);
	}
	```

<br>

### 1436 영화감독 숌
* N이 10000이하 자연수이므로 666이 첫 종말의 수라고 했을 때  
어림잡아 최대 666 * 10000 = 6660000 안쪽으로 들어올 것을 예상할 수 있다

<br>

* 666부터 숫자를 더하며 666이 포함된 N번째숫자면 출력하게 단순하게 해결해보자
	```cpp
		int i = 666;
		for (;; i++)
		{
			if (to_string(i).find("666") != string::npos)
			{
				N--;
			}
			if (N == 0)
			{
				break;
			}
		}
	```

<br>

### 9012 괄호
* stack을 이용하면 쉽게 해결할 수 있다  
한쪽 괄호는 push 해주고 짝인 반대쪽 괄호가 들어오면 pop을 해줌으로써  
stack 컨테이너가 비어있느냐 아니냐에 따라 결정해줄 수 있다
	```cpp
			for (int i = 0; i < S.size(); i++)
			{
				if (VPS.size() and VPS.top() == '(' and S[i] == ')')
				{
					VPS.pop();
				}
				else
				{
					VPS.push(S[i]);
				}
			}
	```

<br>

### 4949 균형잡힌 세상
* [9012 괄호](#9012-괄호)와 같은 방식으로 해결할 수 있다  
stack 컨테이너에 괄호를 넣고 짝이면 pop해주는 방식을 사용하면 된다

<br>

### 14502 연구소
* 일단 벽을 3개 세우는 모든 경우의 수를 고려해본다  
    -> 시간초과가 나는지 안나는지 확인하려면  
    문제의 최대범위를 기반으로 시간복잡도를 유추해보자

1. 벽을 3개 세운다 -> N과 M의 최대는 8이므로 8*8 64 -> 벽 3개를 순서상관없이 세운다 = 64C3
1. 바이러스가 퍼진다 -> BFS or DFS 탐색을 한다 = 64
1. 안전영역을 카운팅해서 max값을 구한다 = 64

* -> 64C3 * (64 + 64) = 약 60 * 20 * 30 * 120 = 약 430만  
1000만 이하이므로 벽을 3개 세우는 모든 경우의 수는 괜찮다

* 벽의 모든 좌표들 중에 3개를 뽑는 경우의 수는 3중 for문을 사용하여 구현할 수 있다  
예를 들어 `{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}` 총 5개 좌표에 벽이 있다고 가정하면  
5개중 3개를 순서 상관 없이 뽑는 5C3에 해당하는 식은 아래와 같이 표현할 수 있다
	```cpp
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < i; j++)
			{
				for (int k = 0; k < j; k++)
				{
					cout << k << j << i << '\n';
				}
			}
		}
	```

<br>

### 2636 치즈
- 치즈가 없는 부분부터 시작해서 치즈가 있는부분은 녹이면 되는문제
- 원래는 치즈가 없는 부분을 찾는 로직부터 시작해야 하지만  
해당 문제에서는 가장자리에는 치즈가 없다고 되어있어 아무 자리에서나 시작해도 상관이 없다
- 모두 녹기 전 마지막 사이즈는 담을 자료구조의 size로 쉽게 해결 할 수 있다

<br>

즉 구현할 내용은 다음과 같다
1. DFS로 탐색
1. 0이면 계속 1이면 자료구조에 담고 `(다 녹기 전 치즈조각 = size)`
1. 담은 자료구조를 기반으로 다 0 으로 만들고 시간을 ++해준다 `(다 녹는데 걸리는 시간)`

<br>

### 1068 트리
- 반환 값이 int인 DFS 메서드를 사용하여 리프노드 수를 구하는 함수를 이용해보자  
리프노드? -> `자식노드가 없는 것`  
즉 `for : there -> Adj[here]` 탐색 시 `there`가 없는 것
	```cpp
		int Result = 0;
		int Child = 0;

		for (int there : Adj[here])
		{
			if (there == R)
			{
				continue;
			}
			Result += DFS(there);
			Child++;
		}
	```

<br>

### 효율적인 해킹
* 모든 정점에 대해 i부터 n까지 dfs를 돌린다고 가정하면  
1만 x 1만 = 1억이라 접근방법에 대해 생각해볼 필요가 있다

* 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 알려면 일단  
탐색하는 노드에서 연결되어 있는 노드가 몇개인지를 알아야 한다  
1에 2와 3이 연결된 트리가 있다고 가정해보자  
1에 연결되어있는 간선을 탐색하려면 아래와 같이 될 것이다
	```cpp
	int DFS(int here)
	{
		Visited[here] = 1;
		int Result = 1;
		for (int there : adj[here])
		{
			if (Vistied[there])
			{
				continue;
			}
			Result += DFS(there);
		}

		return Result;
	}
	```
* 위처럼 return값은 3을 얻을 수 있으며 이 방법을 이용하면 해결할 수 있다  
`자주 나오게 되는 방식이니 기억해두자`

<br>

* 모든 정점을 탐색하기 때문에 DFS 할 때마다 초기화를 빼먹으면 안된다
	```cpp
	memset(Visited, 0, sizeof(Visited));
	```

<br>

### 17298 오큰수
- 문제마다 다르지만 통상 1억이하, 1000만이하까지는 통과된다  
문제의 최대범위가 100만이기 때문에 이중 for문으로 돌릴경우 100억으로  
범위를 한참 벗어나기 때문에 다른 방식을 생각해야 한다
- 짝짓기는 stack을 활용하면 되는 경우가 많으므로 stack으로 접근해보자
- 오큰수는 오른쪽에 있다는 것은 자명하므로 왼쪽에서부터 오른쪽으로 탐색을하면 될 것이다
- 예를 들어 {3, 2, 1, 4}가 입력으로 주어졌을 때 3부터 오른쪽으로 탐색을 시작하면  
    1. 3의 오큰수는 아직 나타나지 않음
    1. 2의 오큰수는 아직 나타나지 않음
    1. 1의 오큰수는 아직 나타나지 않음
    1. 4가 나올 때 오큰수가 완성이 됌
- 즉, 오큰수가 결정이 안되었을 때는 일단 스택에 담아놓고  
더 큰수가 나올 때의 순간에 오큰수가 결정되는 것이라 할 수 있다

<br>

## 3
### 15686 치킨 배달
- 집은 최대 2N, 치킨집은 최대 13이라고 주어졌으니  
-> 최대 13C? x 100의 경우의 수가 나오게 된다  
-> 중간 값인 13C6이나 13C7정도가 제일 값이 크게 될 것이므로 약 13x12x11 = 1716
- 즉, 17만 정도이니 조합으로 충분히 통과할 것이다
    ```cpp
	// 자주 나오는 조합식
	void Combi(int start, vector<int> v)
	{
		if (v.size() == m)
		{
			vCLists.push_back(v);
			return;
		}

		for (int i = start + 1; i < vC.size(); i++)
		{
			v.push_back(i);
			Combi(i, v);
			v.pop_back();
		}

		return;
	}
	```
- 집 x 치킨집 조합 경우의 수
    ```cpp
	for (auto & CList : vCLists)
	{
		int ans = 0;
		for (auto & Home : vH)
		{
			int mn = 987654321;
			for (auto & Ch : CList)
			{
				int dist = abs(Home.first - vC[ Ch ].first) + abs(Home.second - vC[ Ch ].second);
				mn = min(mn, dist);
			}
			ans += mn;
		}
		answer = min(answer, ans);
	}
	```
<br>

### 1816 암호 키
- 문제에서 만일 S의 모든 소인수가 106보다 크다면 그 수는 적절한 암호 키이고,  
그렇지 않은 경우는 적절하지 못한 암호 키가 된다.
- 즉, 100만 이하이면서 2이상의 약수를 가지고 있다면 틀린번호라 생각하면 된다
	```cpp
	bool Check(ll n)
	{
		for (int i = 2; i <= 1000000; i++)
		{
			if (n % i == 0)		// 100만 이하의 약수가 존재한다
			{
				return false;
			}
			if (i == 1000000)	// 100만 이하의 약수가 존재하지 않는다
			{
				return true;
			}
		}
	}
	```

<br>

### 14568 2017 연세대학교 프로그래밍 경시대회
- 주어진 경우의 수를 반복문으로 먼저 작성해보고
- 조건대로 걸러줘도 `n의 범위가 100까지`이기 때문에 문제가 없음을 알 수 있다
<!--
조금더 최적화를 해보자면 남규는 영훈이보다 `2개이상` 가져야하고
반복문을 2부터 2씩 증가시키면서 전체 사탕개수에서(택희가 가진 개수 + 2)를 빼주고
나머지를 남규와 영훈이가 나눠가지면 된다는 규칙을 알 수 있다  
    사탕이 10개면 택희가 2개 가져가고 남규가 2개 더 가져가야 하므로 4, 10-4=6  
	6을 나누는 경우의 수는 (1,5), (2,4), (3,3)  
	즉 규칙은 (N - i -2) / 2가 된다
-->

<br>

### 19532 수학은 비대면강의입니다
- 주어진 경우의 수를 반복문으로 먼저 작성해보고
- 조건대로 걸러줘도 `n의 범위가 -999~999까지`이기 때문에 문제가 없음을 알 수 있다
- 반복문 대신 연립방정식을 풀어서 x, y에 대입하여 직접 구할 수도 있다
 	```cpp
		int x = (c * e - b * f) / (a * e - b * d);
    	int y = (c * d - a * f) / (b * d - a * e);
	```

<br>

### 2503 숫자 야구
- 영수가 생각할 수 있는 모든 수를 반복문으로 넣어본다
- 그리고 민혁이가 도전한 내용 즉, 주어진 조건에 맞는지 확인한다
- `vector<vector<int>> v` 형식으로 입력을 받으면  
    -> {number, strike, ball}형태로 값을 그대로 push_back할 수 있다

<br>

### 1090 체커
- 모든 좌표를 탐색 하게 될 경우에는 범위가 너무 크므로 불가능
- 각각 체커의 위치마다 이동해야하는 거리를 계산해서 최소값을 찾으면 된다
    ```cpp
    // 만날 장소 정하기
    for (int y : arrX)
    {
        for (int x : arrY)
        {
            vector<int> dist;

            // 만날 장소로 각각의 점들이 오는 비용 계산하기
            for (auto [ex, ey] : arr)
            {
                int d = abs(ex - x) + abs(ey - y);
                dist.push_back(d);
            }

            // 가까운 순서대로 정렬하기
            sort(dist.begin(), dist.end());

            int tmp = 0;
            for (int i = 0; i < dist.size(); i++)
            {
                tmp += dist[ i ];
                if (answer[ i ] == -1)
                {
                    answer[ i ] = tmp;
                }
                else
                {
                    answer[ i ] = min(tmp, answer[ i ]);
                }
            }
        }
    }
	```

---