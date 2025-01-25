#include <string>
#include <iostream>

std::string solution(const std::string& s) {
    // 去除全部的0
    int start = s.find_first_not_of("0");
    // 当 start 是字符串 s 的截止位置时，直接返回 0
    if (start == std::string::npos) start = 0;

    // 截取字符串，从第一个不为 0 的位置向后截取
    std::string temp = s.substr(start);

    // 获取小数点的位置
    int dot = temp.find('.');
    // 将数组拆分为整数部分和小数部分
    std::string zs, xs;
    // 如果小数点存在，则分别截取整数和小数部分
    if (dot != std::string::npos)
    {
        zs = temp.substr(0, dot);
        xs = temp.substr(dot);
    }
    else
    {
        zs = temp;
    }

    // 处理整数部分，添加 “，”号
    std::string formatString;
    // 定义一个计数器，用于判断是否添加 “,”号
    int count = 0;
    // 从后往前遍历整数部分字符串
    for (int i = zs.size() - 1; i >= 0; --i)
    {
        formatString += zs[i];
        count++;
        if (count % 3 == 0 && i != 0)
        {
            formatString += ',';
        }
    }

    std::reverse(formatString.begin(), formatString.end());

    // 合并整数和小数部分
    std::string result = formatString;
    // 如果小数部分不为空，则追加到结果字符串中
    if (!xs.empty())
    {
        result += xs;
    }

    return result;
}

int main() {
    std::cout << (solution("1294512.12412") == "1,294,512.12412") << std::endl;
    std::cout << (solution("0000123456789.99") == "123,456,789.99") << std::endl;
    std::cout << (solution("987654321") == "987,654,321") << std::endl;
}