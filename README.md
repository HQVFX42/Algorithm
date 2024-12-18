# Lists
- [2870 수학숙제](#2870)

# [2870 수학숙제](https://www.acmicpc.net/problem/2870)
  
범위가 100글자라고 하였으니 자료형을 생각해보아야 한다  
int는 약 10자리 정도만 커버할 수 있고  
long long은 약 19자리까지 가능하다

때문에 string을 사용할 생각을 하자

소문자 알파벳은 버리고 주어진 숫자만 담으려면  
정수는 아스키코드 소문자 알파벳보다 작은 것을 활용하면 된다 `65~97은 문자`

`if (a < 'a')` or `if (a < 65)`

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