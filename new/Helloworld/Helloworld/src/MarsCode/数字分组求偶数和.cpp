#include <iostream>
#include <vector>
#include <string>
#include <functional>

int solution(std::vector<int> numbers) {
    // �����������ת��Ϊ�ַ���
    std::vector<std::string> numStrs;
    for (int num : numbers) {
        numStrs.push_back(std::to_string(num));
    }

    int count = 0;

    // �ݹ麯�������ڳ��Դ�ÿ����������ѡ��һ������
    std::function<void(int, int)> dfs = [&](int index, int sum) {
        // ����Ѿ�ѡ���������������е�һ������
        if (index == numStrs.size()) {
            // �жϸ�λ֮���Ƿ�Ϊż��
            if (sum % 2 == 0) {
                count++;
            }
            return;
        }

        // ������ǰ�������е�ÿ������
        for (char digit : numStrs[index]) {
            // �ݹ���ã�ѡ����һ���������е�����
            dfs(index + 1, sum + (digit - '0'));
        }
        };

    // �ӵ�һ�������鿪ʼ�ݹ�
    dfs(0, 0);

    return count;
}

int main() {
    // ��������
    std::cout << (solution({ 123, 456, 789 }) == 14) << std::endl;
    std::cout << (solution({ 123456789 }) == 4) << std::endl;
    std::cout << (solution({ 14329, 7568 }) == 10) << std::endl;
    return 0;
}