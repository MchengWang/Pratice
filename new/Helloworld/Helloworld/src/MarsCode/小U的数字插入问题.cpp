#include <iostream>
#include <string>

int solution(int a, int b) {
    // 将 a 和 b 转换为字符串
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);

    // 初始化最大结果
    std::string maxResult = "";

    // 遍历插入位置
    for (int i = 0; i <= strA.size(); ++i) {
        // 尝试将 strB 插入到 strA 的第 i 个位置
        std::string temp = strA.substr(0, i) + strB + strA.substr(i);

        // 比较并更新最大结果
        if (temp > maxResult) {
            maxResult = temp;
        }
    }

    // 将最大结果转换回整数并返回
    return stoi(maxResult);

}

int main() {
    std::cout << (solution(76543, 4) == 765443) << std::endl;
    std::cout << (solution(1, 0) == 10) << std::endl;
    std::cout << (solution(44, 5) == 544) << std::endl;
    std::cout << (solution(666, 6) == 6666) << std::endl;
    return 0;
}