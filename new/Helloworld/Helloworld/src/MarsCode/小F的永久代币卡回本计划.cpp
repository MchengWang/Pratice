#include <iostream>

int solution(int a, int b) {
    // ֻ��Ҫһ��ѭ���������ۼ�ÿ�շ��صĹ���������ֻҪ����ԭʼ�����ʱ��Ĺ��������ȿ���
    int sum = 0;
    int day = 0;
    while (sum < a)
    {
        sum += b;
        day++;
    }
    return day;
}

int main() {
    std::cout << (solution(10, 1) == 10) << std::endl;
    std::cout << (solution(10, 2) == 5) << std::endl;
    std::cout << (solution(10, 3) == 4) << std::endl;
    return 0;
}