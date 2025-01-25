#include <iostream>
#include <string>

int solution(int x, int y) {
    // 可以将其转成字符串后，遍历整个字符串
    int count = 0;
    while (x <= y)
    {
        std::string str = std::to_string(x);
        char ch = str[0];
        int flag = 1;
        for (int i = 1; i < str.size(); i++)
        {
            if (str[i] != ch)
            {
                flag = 0;
                break;
            }
        }

        if (flag) count++;
        x++;
    }
    return count;
}

int main() {
    // Add your test cases here

    std::cout << (solution(1, 10) == 9) << std::endl;
    std::cout << (solution(2, 22) == 10) << std::endl;

    return 0;
}
