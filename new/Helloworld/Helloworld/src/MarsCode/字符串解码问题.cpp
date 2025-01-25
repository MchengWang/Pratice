#include <iostream>
#include <string>

std::string solution(int N, const std::string& S) {
    // 循环遍历字符串，然后对字符串一 一解码
    std::string str = "";

    for (int i = 0; i < N; i++)
    {
        switch (S[i])
        {
        case 'x': str.push_back('y'); break;
        case 'y': str.push_back('x'); break;
        case 'a': str.push_back('b'); break;
        case 'b': str.push_back('a'); break;
        default: str.push_back(S[i]); break;
        }
    }

    return str;
}

int main() {
    std::cout << (solution(5, "xaytq") == "ybxtq") << std::endl;
    std::cout << (solution(6, "abcxyz") == "bacyxz") << std::endl;
    std::cout << (solution(3, "zzz") == "zzz") << std::endl;
}