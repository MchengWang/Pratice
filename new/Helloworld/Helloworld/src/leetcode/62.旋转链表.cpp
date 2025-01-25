#include <iostream>

struct ListNode
{
    int data;
    ListNode* next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : data(x), next(next) {}

};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 初始条件，当旋转次数为 0 or 头节点为空 or 头节点的下一个指针为空 直接返回头节点就行
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        // 定义一个工作指针，指向头节点
        ListNode* cur = head;
        // 查找链表的尾节点，并计算链表的长度
        int count = 1;
        while (cur->next != nullptr)
        {
            cur = cur->next;
            count++;
        }
        // 计算在第几个结点断开指针
        int index = count - k % count;
        // 如果 index 为 n， 则说明没有进行改变
        if (index == count) return head;
        // 将尾节点与头节点进行链接，构成一个环
        cur->next = head;
        // 开始找要断开连接的结点
        while (index--)
            cur = cur->next;
        // 定义一个结点，存储结果指针
        ListNode* temp = cur->next;
        // 断开当前指针的下一个结点的链接
        cur->next = nullptr;
        // 返回结果
        return temp;
    }
};

int main()
{
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    Solution sol;
    p1 = sol.rotateRight(p1, 2);

    while (p1)
    {
        std::cout << p1->data << std::endl;
        p1 = p1->next;
    }
    return 0;
}