#include <iostream>

int solution(int n) {
    // ���������Ϊ1��ֱ�ӷ���0
    if (n == 1) 
        return 0;

    // ��ʼ����������
    int matches = 0;

    // ѭ��ֱ��������Ϊ1
    while (n > 1) {
        if (n % 2 == 0) {
            // ż��������
            matches += n / 2;
            n = n / 2;
        }
        else {
            // ����������
            matches += (n - 1) / 2;
            n = (n - 1) / 2 + 1;
        }
    }

    return matches;
}

int main() {
    std::cout << (solution(7) == 6) << std::endl;
    std::cout << (solution(14) == 13) << std::endl;
    std::cout << (solution(1) == 0) << std::endl;

    return 0;
}