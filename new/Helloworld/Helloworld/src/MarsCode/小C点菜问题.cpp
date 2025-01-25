#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

long solution(int m, const std::vector<int> w) {
    // ����һ����ϣ����ͳ��ÿ���۸�Ĳ�Ʒ����
    std::unordered_map<int, int> priceCount;

    // ������Ʒ�۸��б�
    for (int price : w) 
        if (price <= m) 
            // ���Ӹü۸�ļ���
            priceCount[price]++;

    // ��ʼ��������
    int maxCount = 0;

    // ������ϣ���ҳ�������
    for (const auto& pair : priceCount) 
        if (pair.second > maxCount) 
            maxCount = pair.second;

    return maxCount;
}

int main() {
    std::cout << (solution(6, { 2, 3, 3, 6, 6, 6, 9, 9, 23 }) == 3) << std::endl;
    std::cout << (solution(4, { 1, 2, 4, 4, 4 }) == 3) << std::endl;
    std::cout << (solution(5, { 5, 5, 5, 5, 6, 7, 8 }) == 4) << std::endl;
    return 0;
}