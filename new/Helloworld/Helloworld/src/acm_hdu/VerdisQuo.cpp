#include<iostream>
#define MAX 1010

char str[MAX];
int  intstr[MAX]; 
int sign[MAX];

int getvalue(char ch)
{
	if (ch == 'I') return 1;
	else if (ch == 'V')	return 5;
	else if (ch == 'X')	return 10;
	else if (ch == 'L')	return 50;
	else if (ch == 'C')	return 100;
	else if (ch == 'D')	return 500;
	else return 1000;

}

int getstring()
{
	int i;
	for (i = 0; i < strlen(str); i++)
		intstr[i] = getvalue(str[i]);
	intstr[i] = '\0';
	return 0;
}

int init()
{
	int i = 0;
	for (i = 0; i < MAX; i++)
		sign[i] = 1;
	return 0;
}


int main()
{
	int n;
	std::cin >> n;
	while (n--)
	{
		std::cin >> str;
		getstring();

		init();
		int i = 0;
		for (i = 0; i < strlen(str) - 1; i++)
		{
			if (intstr[i] < intstr[i + 1])
			{
				sign[i] = -1;
			}
		}

		int sum = 0;
		for (i = 0; i < strlen(str); i++)
		{
			sum += sign[i] * intstr[i];
		}
		std::cout << sum << std::endl;
	}
	return 0;
}