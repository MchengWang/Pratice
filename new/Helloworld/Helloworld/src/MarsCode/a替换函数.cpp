#include <iostream>
#include <string>

std::string solution(const std::string& s) {
    // ѭ�����������ַ�����ֻҪ�ǡ�a�� ���滻��%100
    std::string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            str.append("%100");
        else
            str.push_back(s[i]);
    }
    return str; // Placeholder
}

int main() {
    std::cout << (solution("abcdwa") == "%100bcdw%100") << std::endl;
    std::cout << (solution("banana") == "b%100n%100n%100") << std::endl;
    std::cout << (solution("apple") == "%100pple") << std::endl;
    return 0;
}