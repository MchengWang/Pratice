#include <iostream>
#include <string>

int solution(int a, int b) {
    // �� a �� b ת��Ϊ�ַ���
    std::string strA = std::to_string(a);
    std::string strB = std::to_string(b);

    // ��ʼ�������
    std::string maxResult = "";

    // ��������λ��
    for (int i = 0; i <= strA.size(); ++i) {
        // ���Խ� strB ���뵽 strA �ĵ� i ��λ��
        std::string temp = strA.substr(0, i) + strB + strA.substr(i);

        // �Ƚϲ����������
        if (temp > maxResult) {
            maxResult = temp;
        }
    }

    // �������ת��������������
    return stoi(maxResult);

}

int main() {
    std::cout << (solution(76543, 4) == 765443) << std::endl;
    std::cout << (solution(1, 0) == 10) << std::endl;
    std::cout << (solution(44, 5) == 544) << std::endl;
    std::cout << (solution(666, 6) == 6666) << std::endl;
    return 0;
}