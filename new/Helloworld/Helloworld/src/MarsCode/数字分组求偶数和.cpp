#include <iostream>
#include <vector>
#include <string>
#include <functional>

int solution(std::vector<int> numbers) {
    // 将输入的数字转换为字符串
    std::vector<std::string> numStrs;
    for (int num : numbers) {
        numStrs.push_back(std::to_string(num));
    }

    int count = 0;

    // 递归函数，用于尝试从每个数字组中选择一个数字
    std::function<void(int, int)> dfs = [&](int index, int sum) {
        // 如果已经选择了所有数字组中的一个数字
        if (index == numStrs.size()) {
            // 判断各位之和是否为偶数
            if (sum % 2 == 0) {
                count++;
            }
            return;
        }

        // 遍历当前数字组中的每个数字
        for (char digit : numStrs[index]) {
            // 递归调用，选择下一个数字组中的数字
            dfs(index + 1, sum + (digit - '0'));
        }
        };

    // 从第一个数字组开始递归
    dfs(0, 0);

    return count;
}

int main() {
    // 测试样例
    std::cout << (solution({ 123, 456, 789 }) == 14) << std::endl;
    std::cout << (solution({ 123456789 }) == 4) << std::endl;
    std::cout << (solution({ 14329, 7568 }) == 10) << std::endl;
    return 0;
}