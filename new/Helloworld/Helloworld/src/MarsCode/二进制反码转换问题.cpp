#include <iostream>
#include <string>
#include <bitset>

int solution(int N) {
    // 1. 将十进制数 N 转换为二进制字符串
    std::string binary = std::bitset<32>(N).to_string();  // 32 位二进制表示

    // 2. 去除前导零
    size_t pos = binary.find('1');
    if (pos != std::string::npos) {
        binary = binary.substr(pos);
    }
    else {
        binary = "0";  // 如果 N 为 0，则二进制表示为 "0"
    }

    // 3. 将二进制字符串进行反码转换
    for (char& c : binary) {
        c = (c == '0') ? '1' : '0';
    }

    // 4. 将反码后的二进制字符串转换回十进制数
    int result = 0;
    int base = 1;
    for (int i = binary.size() - 1; i >= 0; --i) {
        if (binary[i] == '1') {
            result += base;
        }
        base *= 2;
    }

    return result;
}

int main() {
    std::cout << (solution(5) == 2) << std::endl;
    std::cout << (solution(10) == 5) << std::endl;
    std::cout << (solution(0) == 1) << std::endl;
    return 0;
}