#include <iostream>
#include <vector>

/*
    算法步骤
    1.异或运算：异或运算有一个非常有用的性质：
       任何数和 0 做异或运算，结果仍然是原来的数，即 a ^ 0 = a。
       任何数和其自身做异或运算，结果是 0，即 a ^ a = 0。
       异或运算满足交换律和结合律，即 a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b。
    2.遍历数组：我们可以遍历整个数组，对所有元素进行异或运算。
       由于其他数字都出现两次，它们会相互抵消，最终剩下的就是唯一出现一次的数字。
*/

int solution(std::vector<int> cards) {
    // Edit your code here
    int temp = cards[0];
    for (int i = 1; i < cards.size(); i++) {
        temp ^= cards[i];
    }
    return temp;
}

int main() {
    // Add your test cases here

    std::cout << (solution({ 1, 1, 2, 2, 3, 3, 4, 5, 5 }) == 4) << std::endl;
    std::cout << (solution({ 0, 1, 0, 1, 2 }) == 2) << std::endl;

    return 0;
}
