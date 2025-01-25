#include <iostream>
#include <string>

std::string solution(std::string s, int k) {
    while (k--)
    {
        std::string ss;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case 'a': ss.append("bc"); break;
            case 'b': ss.append("ca"); break;
            case 'c': ss.append("ab"); break;
            }
        }
        s = ss;
    }
    return s;
}

int main() {
    std::cout << (solution("abc", 2) == "caababbcbcca") << std::endl;
    std::cout << (solution("abca", 3) == "abbcbccabccacaabcaababbcabbcbcca") << std::endl;
    std::cout << (solution("cba", 1) == "abcabc") << std::endl;
    return 0;
}