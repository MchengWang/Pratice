#include <iostream>
#include <cmath>
#include <string>

int isSuShu(int n); // 判断素数函数

int main()
{
    int x, y, i;
    while (std::cin >> x >> y && (x || y))
    {
        for (i = x; i < y; i++)
            if (isSuShu(i * i + i + 41) == 1) // if 条件成立循环提前结束
                break;
        if (i < y) // 代表循环提前结束
            std::cout << "Sorry" << std::endl;
        else
            std::cout << "OK" << std::endl;
    }

    return 0;
}

int isSuShu(int n)
{
    int i;
    for (i = 2; i < sqrt(n); i++)
		// 如果a^2能整除b的话a也可以整除b
		// 例如4可以整除8那么2也可以整除8，
		// 相反如果c不能整d的话那么c^2也一定不能整除d，
		// 例如3不能整除25那么9也一定不能整除25.
		// 所以循环只需要执行到n的根号就可以了，
		// 能减小时间复杂度
        if (n % i == 0)
            // n被除了1和自身以外的某个数整除函数提前结束并返回1
            return 1;
    return 0;
}
