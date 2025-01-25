#include <iostream>
#include <string>
#include <bitset>

int solution(int N) {
    // 1. ��ʮ������ N ת��Ϊ�������ַ���
    std::string binary = std::bitset<32>(N).to_string();  // 32 λ�����Ʊ�ʾ

    // 2. ȥ��ǰ����
    size_t pos = binary.find('1');
    if (pos != std::string::npos) {
        binary = binary.substr(pos);
    }
    else {
        binary = "0";  // ��� N Ϊ 0��������Ʊ�ʾΪ "0"
    }

    // 3. ���������ַ������з���ת��
    for (char& c : binary) {
        c = (c == '0') ? '1' : '0';
    }

    // 4. �������Ķ������ַ���ת����ʮ������
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