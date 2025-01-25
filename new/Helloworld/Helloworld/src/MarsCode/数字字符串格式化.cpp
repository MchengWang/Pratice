#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // ȥ��ȫ����0
    int start = s.find_first_not_of("0");
    // �� start ���ַ��� s �Ľ�ֹλ��ʱ��ֱ�ӷ��� 0
    if (start == std::string::npos) start = 0;

    // ��ȡ�ַ������ӵ�һ����Ϊ 0 ��λ������ȡ
    std::string temp = s.substr(start);

    // ��ȡС�����λ��
    int dot = temp.find('.');
    // ��������Ϊ�������ֺ�С������
    std::string zs, xs;
    // ���С������ڣ���ֱ��ȡ������С������
    if (dot != std::string::npos)
    {
        zs = temp.substr(0, dot);
        xs = temp.substr(dot);
    }
    else
    {
        zs = temp;
    }

    // �����������֣���� ��������
    std::string formatString;
    // ����һ���������������ж��Ƿ���� ��,����
    int count = 0;
    // �Ӻ���ǰ�������������ַ���
    for (int i = zs.size() - 1; i >= 0; --i)
    {
        formatString += zs[i];
        count++;
        if (count % 3 == 0 && i != 0)
        {
            formatString += ',';
        }
    }

    std::reverse(formatString.begin(), formatString.end());

    // �ϲ�������С������
    std::string result = formatString;
    // ���С�����ֲ�Ϊ�գ���׷�ӵ�����ַ�����
    if (!xs.empty())
    {
        result += xs;
    }

    return result;
}

int main() {
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}