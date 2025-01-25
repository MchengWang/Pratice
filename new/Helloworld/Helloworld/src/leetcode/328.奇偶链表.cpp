#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() :val(0), next(nullptr) {}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // 当头节点为空的时候，直接返回头节点
        if (!head) return head;
        
        // 定义一个空结点
        ListNode* dummy = new ListNode(-1);
        // 将头节点，链接到 dummy 节点的后面
        dummy->next = head;

        // 定义一个工作结点，和一个慢结点
        ListNode* cur = head, *slow = nullptr;
        
        // 定义一个计数器，用于判断当前节点是 奇结点 还是 偶结点
        int count = 1; // 默认第一个为 奇结点
        while (cur)
        {
            // 如果是 奇结点，则将其连接到头结点后。
            if (count % 2 != 0) slow = cur->next;
        }
    }
};