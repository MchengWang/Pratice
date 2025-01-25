#include<iostream>
#include<string.h>

int main()
{
	int n, len;
	char s[50];
	int flag; //±êÖ¾Î» 
	while (scanf("%d\n", &n) != EOF)
	{
		while (n--)
		{
			flag = 0;
			std::cin.get(s, 50);
			len = strlen(s);
			for (int i = 0; i < len; i++)
			{
				if (i == 0)
				{
					if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '_'))
					{
						flag = 1;
						break;
					}
				}

				else
				{
					if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == '_' || (s[i] >= '0' && s[i] <= '9')))
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
				printf("no\n");
			else
				printf("yes\n");
		}
	}
	return 0;
}