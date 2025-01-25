#include <iostream>
#include <string>

std::string erase_zero(std::string str)
{
    int i, pos, len;
    pos = str.find(".");
    // 先判断是否为小数
    if (pos != std::string::npos) {
        len = str.length();
        // 找到“后导零”的开始位置
        for (i = len - 1; str[i] == '0'; i--) {}
        if (i == pos) {
            // 如果小数点后全部为零，还要删除小数点
            str.erase(i, len - i);
        }
        else {
            // 删除“后导零”
            str.erase(i + 1, len - i - 1);
        }
    }
    return str;
}

int main()
{
    std::string A, B;
    while (std::cin >> A >> B) {
        if (erase_zero(A) == erase_zero(B)) {
            std::cout << "YES";
        }
        else {
            std::cout << "NO";
        }
        std::cout << std::endl;
    }
    return 0;
}



