#include <iostream>
#include <vector>

int solution(int n, int l, int r, std::vector<int>& a) {
    // 首先范围是 l < x < r (不包括端点值)
    // 其次是偶数
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] % 2 == 0 && a[i] >= l && a[i] <= r)
            count++;
    }
    return count;
}

int main() {
    std::vector<int> a1 = { 1, 2, 6, 8, 7 };
    std::cout << (solution(5, 3, 8, a1) == 2) << std::endl;

    std::vector<int> a2 = { 12, 15, 18, 9 };
    std::cout << (solution(4, 10, 20, a2) == 2) << std::endl;

    std::vector<int> a3 = { 2, 4, 6 };
    std::cout << (solution(3, 1, 10, a3) == 3) << std::endl;
}