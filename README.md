# Lists
| Problem | Description | Code |
| :--: | :--: | :--: |
| [BOJ 2870](https://www.acmicpc.net/problem/2870) | [수학숙제](#2870-수학숙제) | [Code](./Algothingy/2870.cpp) |
| [BOJ 10709](https://www.acmicpc.net/problem/10709) | [기상캐스터](#10709-기상캐스터) | [Code](./Algothingy/2870.cpp) |
| [BOJ 3474](https://www.acmicpc.net/problem/3474) | [교수가 된 현우](#3474-교수가-된-현우) | [Code](./Algothingy/2870.cpp) |

---

# 2870 수학숙제
범위가 100글자라고 하였으니 자료형을 생각해보아야 한다  
int는 약 10자리 정도만 커버할 수 있고  
long long은 약 19자리까지 가능하다

때문에 string을 사용할 생각을 하자

소문자 알파벳은 버리고 주어진 숫자만 담으려면  
정수는 아스키코드 소문자 알파벳보다 작은 것을 활용하면 된다 `65~97은 문자`

`if (a < 'a')` or `if (a < 65)`

0000 같은 반례를 조심하자

##
문자열을 기반으로 비교를 하려면 custom operator가 필요하다
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
##
front같이 참조를 할 때는 size가 있는지 항상 체크하자
```cpp
if(Result.size() and Result.front() == '0')
```

---

# 10709 기상캐스터
입력받은 string에 구름이 있으면 0 아니면 -1로 int 배열 초기화

전체 배열을 탐색해서 해당 인덱스 원소의 값이 0이면 카운트 1부터  
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

---

# 3474 교수가 된 현우
주어진 정수는 10억이하이므로 N!을 직접 구할 수 없다  
또한 10억을 왼쪽에서부터 오른쪽으로 차례대로 탐색하는 것도 무리가 있다

포인트는 0의 개수를 구하는 것이므로 10을 몇개를 만들 수 있느냐를 구하는 문제가 된다
즉 `2의 개수 와 5의 개수가 몇개인지`를 구하는 문제

##
예를 들어 10!의 0의 개수를 구한다고 하면 -> 1,2,3,4,5,6,7,8,9,10  
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

---

#