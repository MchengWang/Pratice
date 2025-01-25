#include <iostream>
#include <string>

std::string solution(const std::string& s) {
    // 先将字符串中的全部大写字母转化为小写字母 并将其字母往前移一位 eg: A -> a -> b;
    std::string str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > 65 && s[i] <= 90)
            str.push_back((char)(s[i] + 31));
        else if (s[i] == 65)
            str.push_back('z');
        else
            str.push_back(s[i]);
    }

    // 编码
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case 'a':
        case 'b':
        case 'c': str.replace(i, 1, "2"); break;
        case 'd':
        case 'e':
        case 'f': str.replace(i, 1, "3"); break;
        case 'g': 
        case 'h': 
        case 'i': str.replace(i, 1, "4"); break;
        case 'j': 
        case 'k': 
        case 'l': str.replace(i, 1, "5"); break;
        case 'm': 
        case 'n': 
        case 'o': str.replace(i, 1, "6"); break;
        case 'p': 
        case 'q': 
        case 'r': 
        case 's': str.replace(i, 1, "7"); break;
        case 't': 
        case 'u': 
        case 'v': str.replace(i, 1, "8"); break;
        case 'w': 
        case 'x': 
        case 'y': 
        case 'z': str.replace(i, 1, "9"); break;
        }
    }

    return str; // Placeholder
}

int main() {
    std::cout << (solution("LIming0701") == "5464640701") << std::endl;
    std::cout << (solution("PassW0rd") == "62778073") << std::endl;
    std::cout << (solution("helloWORLD123") == "4355686752123") << std::endl;

    //std::cout << (int)'a' << std::endl; // 97
    //std::cout << (int)'A' << std::endl; // 65
    //std::cout << (int)'z' << std::endl; // 122
    //std::cout << (int)'Z' << std::endl; // 90

    //std::cout << 'a' - 'A' << std::endl; // 32
    return 0;
}