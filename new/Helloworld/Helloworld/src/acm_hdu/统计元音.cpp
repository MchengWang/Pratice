#include<iostream>
#include<string>
#include<cstring>

void count(char chs[])
{
    int a = 0, e = 0, i = 0, o = 0, u = 0;
    std::cin.getline(chs, 100);
    for (int k = 0; k < strlen(chs); k++)
    {
        switch (chs[k])
        {
        case 'a': a++; break;
        case 'e': e++; break;
        case 'i': i++; break;
        case 'o': o++; break;
        case 'u': u++; break;
        }
    }
    std::cout << "a:" << a << std::endl;
    std::cout << "e:" << e << std::endl;
    std::cout << "i:" << i << std::endl;
    std::cout << "o:" << o << std::endl;
    std::cout << "u:" << u << std::endl;
}
int main()
{
    int n, i;
    char chs[100];
    while (std::cin >> n)
    {
        getchar();
        for (i = 0; i < n; i++)
        {
            count(chs);
            if (i < n - 1)
                std::cout << std::endl;
        }
    }
    return 0;
}
