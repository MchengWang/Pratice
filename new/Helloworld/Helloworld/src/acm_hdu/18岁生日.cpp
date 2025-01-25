#include <iostream>

int inRun(int year)  //判断闰年 
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	return 0;
}
int main()
{
	int T;
	std::cin >> T;
	while (T--)
	{
		int year, month, day, days;
		char temp;
		std::cin >> year >> temp >> month >> temp >> day;
		if (month == 2 && day == 29)  //2.29 一定没有18岁生日 
		{
			std::cout << "-1" << std::endl;
			continue;
		}
		days = 0;

		for (int i = year; i < year + 18; ++i)  //从出生的一年到18岁前一年的总天数 
		{
			if (inRun(i))
				days += 366;
			else
				days += 365;
		}

		if (inRun(year) && month >= 3)   //出生这一年 大于二月且为闰年（多算了一天）要 减一 
			days--;

		year += 18;
		if (inRun(year) && month >= 3)  //十八岁这一年  小于等于2月且为闰年（少算了一天） ，要加一 
			days++;
		std::cout << days << std::endl;
	}
	return 0;
}