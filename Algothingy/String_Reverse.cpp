#include <iostream>
#include <string>
#include <algorithm>

void reverseString(std::string & str)
{
	int left = 0;
	int right = str.length() - 1;
	while (left < right)
	{
		std::swap(str[ left ], str[ right ]);
		left++;
		right--;
	}
}

std::string reverseStringRecursive(const std::string & str)
{
	if (str.length() <= 1)
	{
		return str;
	}
	else
	{
		return reverseStringRecursive(str.substr(1)) + str[ 0 ];
	}
}

int main()
{
	std::string str = "Hello, World!";

	std::reverse(str.begin(), str.end());
	std::cout << str << std::endl;

	reverseString(str);
	std::cout << str << std::endl;

	std::cout << reverseStringRecursive(str) << std::endl;

	std::cout << str << std::endl;

	return 0;
}
