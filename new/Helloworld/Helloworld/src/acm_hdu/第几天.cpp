#include <iostream>

int getMonth(int month , int flag)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: return 31;
	case 4:
	case 6:
	case 9:
	case 11: return 30;
	case 2: return flag == 1 ? 29 : 28;
	}
}

int main()
{
	int year, month, day;
	char a, b;
	while (std::cin >> year >> a >> month >> b >> day)
	{
		int flag = 0;
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) flag = 1;
		int result = 0;
		for (int i = month - 1; i > 0; i--)
		{
			result += getMonth(i, flag);
		}
		result += day;

		std::cout << result << std::endl;
		
	}
	return 0;
}