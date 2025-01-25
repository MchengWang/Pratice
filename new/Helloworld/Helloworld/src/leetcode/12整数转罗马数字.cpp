#include <iostream>
#include <string>
#include <memory>

class Solution {
public:
    std::string intToRoman(int num) {
        int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        std::string templates[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

        for (int i = 0; i < 13; i++)
            while (num >= values[i])
            {
                num -= values[i];
                strs->append(templates[i]);
            }
        return strs->data();
    }
private:
    std::unique_ptr<std::string> strs = std::make_unique<std::string>();
};

int main()
{
    Solution sol;
    std::cout << sol.intToRoman(58) << std::endl;
    std::cin.get();
}