#include <iostream>
#include <string>

int main()
{
    int n, r;
    std::string base = "0123456789ABCDEF";
    while (std::cin >> n >> r)
    {
        getchar();
        std::string* str = new std::string();
        int i = 0;
        if (n < 0) std::cout << "-";
        n = n > 0 ? n : -n;
        while (n)
        {
            str[i++] = base[n % r];
            n /= r;
        }
        while (i--)
            std::cout << str[i];
        std::cout << std::endl;
    }
    return 0;
}



#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.1415927
using namespace std;

//进制转换，10进制数N转换成R进制
void baseConvert(int N, int R) {
	int a[32] = { 0 };
	char b[17] = "0123456789ABCDEF";
	if (N < 0) cout << '-';
	int num = abs(N);
	int i = 0;
	while (num > 0) {//辗转相除法
		a[i] = num % R;
		num = num / R;
		i++;
	}
	for (int j = i - 1; j >= 0; j--) {
		cout << b[a[j]];
	}
	cout << endl;
}

int main()
{
	int N, R;
	while (cin >> N >> R) {
		baseConvert(N, R);
	}
	return 0;
}