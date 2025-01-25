#include <iostream>
#include <string>

int solution(const std::string& s) {
    // ��������ԲȦ�����ֱַ��� 6 8 9 0
    // �ֱ��� 1 2 1 1 ��ԴȪ
    // ����һ������������ԲȦ����
    int count = 0;

    // ѭ���ַ���
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