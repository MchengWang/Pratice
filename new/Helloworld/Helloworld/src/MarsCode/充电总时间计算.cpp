#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>  // ���ڸ�ʽ�����

std::string solution(int n, int x, std::vector<int> a) {
    double total_time = 0.0;

    // ����ÿ�����Եĵ������
    for (int i = 0; i < n; ++i) {
        // ����ÿ�����Գ����������ʱ��
        double time_for_this_computer = static_cast<double>(a[i]) / (4 * x);

        // �ۼӵ���ʱ����
        total_time += time_for_this_computer;
    }

    // ��ʽ��������������С�������λ
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << total_time;
    return oss.str();
}

int main() {
    std::cout << (solution(4, 1, { 2, 3, 4, 5 }) == "3.50") << std::endl;
    std::cout << (solution(3, 2, { 4, 6, 8 }) == "2.25") << std::endl;
    std::cout << (solution(2, 1, { 10, 5 }) == "3.75") << std::endl;
    return 0;
}