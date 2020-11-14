#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverse(int number)
{
	char str[50] = {0};
	char reverse_str[50] = {0};

	itoa(number, str, 50);

	if (str[0] == '-')
	{
		int count = 1;
		reverse_str[0] = '-';

		for (int i = strlen(str) - 1; i >= 0; i++)
		{
			if (str[i] == '0') continue;
			else
			{
				str[i] = reverse_str[count];
				count++;
			}
		}

		int result = (int)strtol(reverse_str, NULL, 10);

		return result;
	}else
	{
		int count = 0;

		for (int i = strlen(str) - 1; i >= 0; i++)
		{
			if (str[i] == '0') continue;
			else
			{
				str[i] = reverse_str[count];
				count++;
			}
		}

		int result = (int)strtol(reverse_str, NULL, 10);

		return result;
	}
}


int main()
{
	int n = 0;
	scanf("%d", &n);

	printf("%d", reverse(n));

	return 0;
}