#include <iostream>
#include <string>

int main() {
    unsigned int m, n, case_n;
    unsigned int i, j, k, tmp, one = 1;

    std::cin >> case_n; // 案例数量

    while (case_n--) {
        std::cin >> m >> n; // m规定孩子出生的数量，n表示生了多少个孩子
        k = j = 0; 
        for (i = 1; i <= n; ++i) {
            std::cin >> tmp; // 输入的孩子性别
            if (tmp && !j) // 当输入的孩子性别为男性时
                j = i; // 当由男性出生，后所有孩子均需要为女性，且计数
        }
        if ((m == n) && (j == 0 || j == n)) { // 当出生孩子数量达到要求的数量 并且出生的男生数量为要求的孩子数量时
            std::cout << "0 RMB" << std::endl;
            continue;
        }
        if (j && j < n) // 
            tmp = (one << (n - j)) - 1;
        else
            tmp = 0;
        if (m < n)
            k = (one << (n - m)) - 1;
        else
            k = 0;
        tmp = (tmp > k) ? tmp : k;
        if (tmp)
            std::cout << tmp << "0000 RMB" << std::endl;
        else
            std::cout << "0 RMB" << std::endl;
    }

    return 0;
}