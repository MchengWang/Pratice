#include <iostream>

int solution(int n) {
    // 如果队伍数为1，直接返回0
    if (n == 1) 
        return 0;

    // 初始化比赛次数
    int matches = 0;

    // 循环直到队伍数为1
    while (n > 1) {
        if (n % 2 == 0) {
            // 偶数队伍数
            matches += n / 2;
            n = n / 2;
        }
        else {
            // 奇数队伍数
            matches += (n - 1) / 2;
            n = (n - 1) / 2 + 1;
        }
    }

    return matches;
}

int main() {
    std::cout << (solution(7) == 6) << std::endl;
    std::cout << (solution(14) == 13) << std::endl;
    std::cout << (solution(1) == 0) << std::endl;

    return 0;
}