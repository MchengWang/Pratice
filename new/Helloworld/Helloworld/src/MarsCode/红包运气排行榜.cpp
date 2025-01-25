#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // ��������

std::vector<std::string> solution(int n, std::vector<std::string> s, std::vector<int> x) {
    // ����һ���ṹ�����洢ÿ���˵����ֺ������Ľ��
    struct Person {
        std::string name;
        int amount;
        int index; // ��¼�������˳��
    };

    // ����һ��Person���͵��������洢�����˵���Ϣ
    std::vector<Person> people(n);

    // ��ʼ��people����
    for (int i = 0; i < n; ++i) {
        people[i].name = s[i];
        people[i].amount = x[i];
        people[i].index = i; // ��¼�������˳��
    }

    // ʹ���Զ���ȽϺ�����people������������
    // �ȽϺ�����Ҫ�ȱȽϽ������ͬ��Ƚ��������˳��
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        if (a.amount == b.amount) {
            return a.index < b.index; // �����ͬ����˳������
        }
        return a.amount > b.amount; // ��ͬ�������Ӵ�С����
        });

    // ����һ������������洢����������
    std::vector<std::string> result(n);

    // �����������ַ�����������
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