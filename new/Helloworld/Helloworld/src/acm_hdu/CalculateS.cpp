#include <iostream>
#include <iomanip>

#define MOD 10000
long long n, temp;

int main()
{
	while (std::cin >> n) {
		temp = (n * (n + 1) / 2 % MOD) * (n * (n + 1) / 2 % MOD) % MOD;
		printf("%04lld\n", temp);
	}
	return 0;
}