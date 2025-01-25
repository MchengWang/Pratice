#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = std::max(a.size(), b.size()), carry = 0;
        for (int i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            result.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());

        return result;
    }
};


int main()
{
    char ch = '2';
    std::cout << ch << std::endl;
    std::cin.get();
}