#include <iostream>
#include <string>

int solution(const std::string& s) {
    // 数字中有圆圈的数字分别是 6 8 9 0
    // 分别有 1 2 1 1 个源泉
    // 定义一个计数器计算圆圈个数
    int count = 0;

    // 循环字符串
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '6': count += 1; break;
        case '8': count += 2; break;
        case '9': count += 1; break;
        case '0': count += 1; break;
        }
    }

    return count;
}

int main() {
    std::cout << (solution("1234567890") == 5) << std::endl;
    std::cout << (solution("8690") == 5) << std::endl;
    std::cout << (solution("1111") == 0) << std::endl;
}   