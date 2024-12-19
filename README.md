# :spiral_notepad:Note
- ? -> 완탐? -> DP? -> 그리디?
- ? -> Sorted Array? -> 이분탐색?
- 평균 1000만이하는 OK
- Counting = Map or Array

<br>

---
# :clipboard:Lists
| Problem | Description | Code | Status |
| :--: | :--: | :--: | :--: |
| [BOJ 2870](https://www.acmicpc.net/problem/2870) | [수학숙제](#2870-수학숙제) | [Code](./Algothingy/2870.cpp) | :ballot_box_with_check: |
| [BOJ 10709](https://www.acmicpc.net/problem/10709) | [기상캐스터](#10709-기상캐스터) | [Code](./Algothingy/10709.cpp) | :ballot_box_with_check: |
| [BOJ 3474](https://www.acmicpc.net/problem/3474) | [교수가 된 현우](#3474-교수가-된-현우) | [Code](./Algothingy/3474.cpp) | :ballot_box_with_check: |
| [BOJ 2852](https://www.acmicpc.net/problem/2852) | [NBA 농구](#2852-NBA-농구) | [Code](./Algothingy/2852.cpp) | :ballot_box_with_check: |
| [BOJ 1436](https://www.acmicpc.net/problem/1436) | [영화감독 숌](#1436-영화감독-숌) | [Code](./Algothingy/1436.cpp) | :ballot_box_with_check: |
| [BOJ 9012](https://www.acmicpc.net/problem/9012) | [괄호](#9012-괄호) | [Code](./Algothingy/9012.cpp) |  |

<br>

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

<br>

front같이 참조를 할 때는 size가 있는지 항상 체크하자
```cpp
if(Result.size() and Result.front() == '0')
```

<br>
<br>

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

<br>
<br>

# 3474 교수가 된 현우
주어진 정수는 10억이하이므로 N!을 직접 구할 수 없다  
또한 10억을 왼쪽에서부터 오른쪽으로 차례대로 탐색하는 것도 무리가 있다

포인트는 0의 개수를 구하는 것이므로 10을 몇개를 만들 수 있느냐를 구하는 문제가 된다
즉 `2의 개수 와 5의 개수가 몇개인지`를 구하는 문제

<br>

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

<br>
<br>

# 2852 NBA 농구
시간이 나올 때 하나의 단위로 변환 후 통일해서 계산하는 것이 좋다
```cpp
int ChangeToInt(string S)
{
	return atoi(S.substr(0, 2).c_str()) * 60 + atoi(S.substr(3, 2).c_str());
}
```

<br>

초를 다시 MM:SS 형식으로 변환
```cpp
string ChangeToString(int N)
{
	string Minutes = "00" + to_string(N / 60);
	string Seconds = "00" + to_string(N % 60);
	return Minutes.substr(Minutes.size() - 2, 2) + ':' + Seconds.substr(Seconds.size() - 2, 2);
}
```

<br>

prev를 이용하여 그 전 득점 타임과 차이를 계산해서 각 팀에 합산해 주면 해결할 수 있다  
단, 종료시간인 `48:00`을 꼭 마지막에 체크해야 함에 유의해야 한다
```cpp
string Prev;
void Func(int & Sum, string S)
{
	Sum += ChangeToInt(S) - ChangeToInt(Prev);
}
```

<br>
<br>

# 1436 영화감독 숌
N이 10000이하 자연수이므로 666이 첫 종말의 수라고 했을 때  
어림잡아 최대 666 * 10000 = 6660000 안쪽으로 들어올 것을 예상할 수 있다

666부터 숫자를 더하며 666이 포함된 N번째숫자면 출력하게 단순하게 해결해보자
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
<br>

# 9012 괄호

---