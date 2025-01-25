#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

long solution(int m, const std::vector<int> w) {
    // 创建一个哈希表来统计每个价格的菜品数量
    std::unordered_map<int, int> priceCount;

    // 遍历菜品价格列表
    for (int price : w) 
        if (price <= m) 
            // 增加该价格的计数
            priceCount[price]++;

    // 初始化最大计数
    int maxCount = 0;

    // 遍历哈希表，找出最大计数
    for (const auto& pair : priceCount) 
        if (pair.second > maxCount) 
            maxCount = pair.second;

    return maxCount;
}

int main() {
    std::cout << (solution(6, { 2, 3, 3, 6, 6, 6, 9, 9, 23 }) == 3) << std::endl;
    std::cout << (solution(4, { 1, 2, 4, 4, 4 }) == 3) << std::endl;
    std::cout << (solution(5, { 5, 5, 5, 5, 6, 7, 8 }) == 4) << std::endl;
    return 0;
}