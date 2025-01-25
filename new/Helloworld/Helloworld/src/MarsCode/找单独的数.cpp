#include <iostream>
#include <vector>

/*
    �㷨����
    1.������㣺���������һ���ǳ����õ����ʣ�
       �κ����� 0 ��������㣬�����Ȼ��ԭ���������� a ^ 0 = a��
       �κ�������������������㣬����� 0���� a ^ a = 0��
       ����������㽻���ɺͽ���ɣ��� a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b��
    2.�������飺���ǿ��Ա����������飬������Ԫ�ؽ���������㡣
       �����������ֶ��������Σ����ǻ��໥����������ʣ�µľ���Ψһ����һ�ε����֡�
*/

int solution(std::vector<int> cards) {
    // Edit your code here
    int temp = cards[0];
    for (int i = 1; i < cards.size(); i++) {
        temp ^= cards[i];
    }
    return temp;
}

int main() {
    // Add your test cases here

    std::cout << (solution({ 1, 1, 2, 2, 3, 3, 4, 5, 5 }) == 4) << std::endl;
    std::cout << (solution({ 0, 1, 0, 1, 2 }) == 2) << std::endl;

    return 0;
}
