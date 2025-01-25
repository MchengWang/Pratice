#include <iostream>

#define MAX 20000

int primes[20000];

void init_primes() {
	primes[1] = 2;
	for (int i = 2; i < MAX; i++)
		if (primes[i] == 0) {
			primes[i] = 1;
			for (int j = i * 2; j < MAX; j += i) {
				primes[j] = 2;
			}
		}
	primes[2] = 2;
}

int main() {
	init_primes();
	int count = 1;
	int a;
	while (std::cin >> a && a != 0) {
		if (primes[a] == 1) {
			std::cout << count++ << ": " << "yes" << std::endl;
		}
		else if (primes[a] == 2) {
			std::cout << count++ << ": " << "no" << std::endl;
		}
	}
	return 0;
}