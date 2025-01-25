
#include <iostream>
#include <vector>

int solution(std::vector<int> array) {
    // 既然会有一个元素，超过数组长度的一半，所以遍历数组，他的累计计数一定不为0
    int count = 0;

    // 定义一个存储元素个数最多的元素
    int temp = array[0];
    count = 1;
    for (int i = 1; i < array.size(); i++)
    {
        if (array[i] == temp)
            count++;
        else
            count--;
        if (count <= 0)
        {
            temp = array[i];
            count = 1;
        }
    }

    // 计算数组长度的一半
    int len = array.size() / 2;

    count = 0;
    for (int num : array)
    {
        if (num == temp)
            count++;
    }
    return temp;
}

int main() {
    // Add your test cases here

    std::cout << (solution({ 1, 3, 8, 2, 3, 1, 3, 3, 3 }) == 3) << std::endl;
    std::cout << (solution({ 5, 5, 5, 1, 2, 5, 5 }) == 5) << std::endl;
    std::cout << (solution({ 9, 9, 9, 9, 8, 9, 8, 8 }) == 9) << std::endl;

    return 0;
}
