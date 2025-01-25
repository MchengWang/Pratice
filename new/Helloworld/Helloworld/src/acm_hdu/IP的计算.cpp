#include<string>
#include<iostream>

int jud(char s)
{
	if (s >= '0' && s <= '9')
		return 1;
	if (s == '.')
		return 2;
	else
		return 0;
}
int main()
{
	char s[105];
	int i, t, a, n, c, k;
	while (std::cin.getline(s , 105))
	{
		a = c = k = n = 0;
		for (i = 0; i < strlen(s); i++)
		{
			t = jud(s[i]);
			if (!t)
				break;
			if (t == 1)
			{
				k = 0;
				a = a * 10 + s[i] - '0';
				n++;
				if (n > 3 || a > 255)
				{
					t = 0;
					break;
				}
			}
			else
			{
				a = n = 0;
				k++;
				c++;
				if (k > 1 || c > 3)
				{
					t = 0;
					break;
				}
			}
		}
		if (k || c != 3)
			t = 0;
		if (t)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}