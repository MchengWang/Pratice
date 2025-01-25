#include <iostream>
#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string str;
        while (columnNumber > 0) {
            --columnNumber;
            str += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        std::reverse(str.begin(), str.end());
        return str;
    }
};

int main1()
{
    std::cout << (int)'A' << std::endl;
    std::cout << (int)'Z' << std::endl;
    std::cin.get();
    return 0;
}