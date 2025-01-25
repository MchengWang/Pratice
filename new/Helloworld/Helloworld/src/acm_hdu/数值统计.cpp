#include <iostream>

int main()
{
    int n;
    while (std::cin >> n && n)
    {
        int a = 0, b = 0, c = 0;
        while (n--)
        {
            double d;
            std::cin >> d;
            if (d < 0)
                a++;
            else if (d == 0)
                b++;
            else
                c++;
        }
        std::cout << a << " " << b << " " << c << std::endl;
    }
    return 0;
}