#include <iostream>
#include <string>

std::string solution(int A, int B) {
    // �����������ʱ����ƴ��
    // ����������ַ�����ʱ��ͽ���ƴ��
    int tt = B - A;

    std::string str = std::to_string(tt);
    str.push_back('/');
    str.append(std::to_string(B));
    return str;
}

int main() {
    std::cout << (solution(2, 7) == "5/7") << std::endl;
    std::cout << (solution(1, 3) == "2/3") << std::endl;
    std::cout << (solution(3, 5) == "2/5") << std::endl;
}