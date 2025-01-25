#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 用于排序

std::vector<std::string> solution(int n, std::vector<std::string> s, std::vector<int> x) {
    // 创建一个结构体来存储每个人的名字和抢到的金额
    struct Person {
        std::string name;
        int amount;
        int index; // 记录抢红包的顺序
    };

    // 创建一个Person类型的向量来存储所有人的信息
    std::vector<Person> people(n);

    // 初始化people向量
    for (int i = 0; i < n; ++i) {
        people[i].name = s[i];
        people[i].amount = x[i];
        people[i].index = i; // 记录抢红包的顺序
    }

    // 使用自定义比较函数对people向量进行排序
    // 比较函数需要先比较金额，金额相同则比较抢红包的顺序
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        if (a.amount == b.amount) {
            return a.index < b.index; // 金额相同，按顺序排序
        }
        return a.amount > b.amount; // 金额不同，按金额从大到小排序
        });

    // 创建一个结果向量来存储排序后的名字
    std::vector<std::string> result(n);

    // 将排序后的名字放入结果向量中
    for (int i = 0; i < n; ++i) {
        result[i] = people[i].name;
    }

    return result;
}

int main() {
    std::cout << (solution(4, { "a", "b", "c", "d" }, { 1, 2, 2, 1 }) == std::vector<std::string>{"b", "c", "a", "d"}) << std::endl;
    std::cout << (solution(3, { "x", "y", "z" }, { 100, 200, 200 }) == std::vector<std::string>{"y", "z", "x"}) << std::endl;
    std::cout << (solution(5, { "m", "n", "o", "p", "q" }, { 50, 50, 30, 30, 20 }) == std::vector<std::string>{"m", "n", "o", "p", "q"}) << std::endl;
    return 0;
}