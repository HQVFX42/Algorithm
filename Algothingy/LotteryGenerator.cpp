#include <iostream>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubbleSort(int* numbers, int count)
{
	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < count - 1 - i; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				Swap(numbers[j], numbers[j + 1]);
			}
		}
	}
}

void ChooseLotto(int* numbers)
{
	int count = 0;

	while (count != 6)
	{
		int randValue = 1 + rand() % 45;

		bool bFound = false;
		for (size_t i = 0; i < count; i++)
		{
			if (numbers[i] == randValue)
			{
				bFound = true;
				break;
			}
		}

		if (!bFound)
		{
			numbers[count] = randValue;
			count++;
		}
	}

	BubbleSort(numbers, count);
}

int main()
{
	srand((unsigned)time(0));

	int lotteryNumbers[6];

	for (size_t i = 0; i < 10; i++)
	{
		ChooseLotto(lotteryNumbers);

		for (size_t i = 0; i < 6; i++)
		{
			std::cout << lotteryNumbers[i] << ' ';
		}

		std::cout << std::endl;
	}
}