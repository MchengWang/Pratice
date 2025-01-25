#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> solution(int n, int max, const std::vector<int>& array) {
    // 1. ͳ��ÿ������ֵ�ĳ��ִ���
    std::unordered_map<int, int> count;
    for (int card : array) {
        count[card]++;
    }

    // 2. �������п��ܵġ���«�����
    std::vector<std::pair<int, int>> possible_pairs;
    for (auto& [a, count_a] : count) {
        if (count_a >= 3) {
            for (auto& [b, count_b] : count) {
                if (a != b && count_b >= 2) {
                    possible_pairs.push_back({ a, b });
                }
            }
        }
    }

    // 3. ɸѡ���������ġ���«�����
    std::pair<int, int> best_pair = { 0, 0 };
    for (auto& [a, b] : possible_pairs) {
        if (3 * a + 2 * b <= max) {
            if (a > best_pair.first || (a == best_pair.first && b > best_pair.second)) {
                best_pair = { a, b };
            }
        }
    }

    // 4. ���ؽ��
    return { best_pair.first, best_pair.second };
}

int main() {
    // Add your test cases here

    std::vector<int> result1 = solution(9, 34, { 6, 6, 6, 8, 8, 8, 5, 5, 1 });
    std::cout << (result1 == std::vector<int>{8, 5}) << std::endl;

    std::vector<int> result2 = solution(9, 37, { 9, 9, 9, 9, 6, 6, 6, 6, 13 });
    std::cout << (result2 == std::vector<int>{6, 9}) << std::endl;

    std::vector<int> result3 = solution(9, 40, { 1, 11, 13, 12, 7, 8, 11, 5, 6 });
    std::cout << (result3 == std::vector<int>{0, 0}) << std::endl;

    return 0;
}
