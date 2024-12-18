# Lists
- [2870 수학숙제](#2870-수학숙제)
- [10709 기상캐스터](#10709-기상캐스터)

---

# [2870 수학숙제](https://www.acmicpc.net/problem/2870)
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

# [10709 기상캐스터](https://www.acmicpc.net/problem/10709)
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