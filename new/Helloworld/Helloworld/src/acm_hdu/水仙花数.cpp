#include <iostream>
#include <string>

bool isShuiXianHua(int num)
{
	bool flag = false;
	int hundred = num / 100;
	int ten = num / 10 % 10;
	int ge = num % 10;

	return num == ((hundred * hundred * hundred) + (ten * ten * ten) + (ge * ge * ge));
}

int main()
{
	int start , end , sign = 1;
	bool flag = false;
	while (std::cin >> start >> end)
	{
		if (start >= 100 && start <= 999 && end >= 100 && end <= 999)
		{
			if (start > end)
			{
				int* temp = new int();
				*temp = start;
				start = end;
				end = *temp;
				delete temp;
			}

			for (; start <= end; start++)
			{
				if (isShuiXianHua(start))
				{
					if (sign == 1)
					{
						std::cout << start;
						sign = 0;
					}
					else
						std::cout << " " << start;
					flag = true;
				}
			}

			if (!flag) std::cout << "no" << std::endl;
			else std::cout << std::endl;

		}
	}
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int m, n, i, j, time = 1;
    while (cin >> m >> n)
    {
        if (m > n)
        {
            int temp;
            temp = m;
            m = n;
            n = temp;
        }
        j = 0;
        for (i = m; i <= n; i++)
        {
            int a, b, c, d;
            a = i / 100;
            b = i % 100;
            c = b / 10;
            d = b % 10;
            if (i == a * a * a + c * c * c + d * d * d)
            {
                if (time == 1)   //time的作用是判断是否为第一次输出（注意第一次与后面的输出形式不同）
                {
                    cout << i;
                    time++;
                    j++;
                }        //j的作用是对水仙花数的计数
                else
                {
                    cout << " " << i;
                    j++;
                }
            }
            if (i == n && j > 0)   //结尾的换行
            {
                cout << endl;
            }
        }
        if (j == 0)
        {
            cout << "no" << endl;
        }
        time = 1;
    }
    return 0;
}