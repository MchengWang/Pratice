#include <iostream>

int solution(int a, int b) {
    // 只需要一个循环，用于累加每日返回的勾玉数量，只要大于原始购买的时候的勾玉数，既可以
    int sum = 0;
    int day = 0;
    while (sum < a)
    {
        sum += b;
        day++;
    }
    return day;
}

int main() {
    std::cout << (solution(10, 1) == 10) << std::endl;
    std::cout << (solution(10, 2) == 5) << std::endl;
    std::cout << (solution(10, 3) == 4) << std::endl;
    return 0;
}