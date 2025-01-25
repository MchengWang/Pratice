#include <iostream>
#include <vector>
#include <string>

std::string solution(int n, std::string s, std::string t) {
    // 先计算原始答案中正确的个数
    int count = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == t[i]) count++;

    // 将原始答案进行反选
    int tcount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case 'A': s.replace(i, 1, "B"); break;
        case 'B': s.replace(i, 1, "A"); break;
        }

        if (s[i] == t[i]) tcount++;
    }

    if (count < tcount) return "yes";
    else if (count == tcount) return "draw";
    else return "no";
}

int main() {
    std::cout << (solution(2, "AB", "AA") == "draw") << std::endl;
    std::cout << (solution(3, "BAA", "ABB") == "yes") << std::endl;
    std::cout << (solution(4, "ABAB", "BABA") == "yes") << std::endl;
    return 0;
}