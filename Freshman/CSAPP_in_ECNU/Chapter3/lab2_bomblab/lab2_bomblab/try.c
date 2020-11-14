#include <stdio.h>
#include <math.h>

int ten_multi(int n)
{
	int result = 1;
	for(int i=0; i<n; i++)
	{
		result *= 10;
	}

	return result;
}

int reverse(int number)
{
	int temp = number;

	int bit[50] = {0};

	int count = 0;
	while (number != 0)
	{
		if (number % 10 != 0)
		{
			bit[count] = abs(number % 10);
			count++;
			number /= 10;
		}else if (count != 0)
		{
			bit[count] = abs(number % 10);
			count++;
			number /= 10;
		}else
		{
			number /= 10;
		}
	}
	int sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += bit[i] * ten_multi(count - 1 - i);
	}

	if (temp < 0)
	{
		sum = -sum;
	}

	return sum;

}

int main()
{
	int number = 0;

	scanf("%d", &number);

	printf("%d", reverse(number));

	return 0;
}