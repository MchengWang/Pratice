#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {   
        // 当头节点为空，直接返回头节点即可
        if (!head) return head;

        // 定义哨兵结点，将其指针域指向头节点
        ListNode* dummy = new ListNode();
        dummy->next = head;

        // 定义快慢结点指针
        ListNode* fast = dummy, * slow = nullptr;

        // 当快指针结点存在时，进入循环
        while (fast)
        {
            // 将慢指针移动到快指针上
            slow = fast;
            // 将快指针移动到它的下一个节点上
            fast = fast->next;

            // 当快指针节点的值与其下一个指针的节点的值相等时，进入循环
            while (fast && fast->next && fast->val == fast->next->val)
            {
                // 存储重复的结点值
                int x = fast->val;

                // 接下来只要是节点值等于 x 的都要删除
                while (fast && fast->val == x)
                    fast = fast->next;

                // 将慢指针的指针域指向相同节点值的下一个指针
                slow->next = fast;
            }
        }

        // 返回链表
        return dummy->next;
    }
};

int main()
{
    ListNode* p0 = new ListNode();
    ListNode* p1 = new ListNode(1, p0);
    ListNode* p2 = new ListNode(1, p1);
    ListNode* p3 = new ListNode(2, p2);
    ListNode* p4 = new ListNode(2, p3);
    ListNode* p5 = new ListNode(3, p4);
    ListNode* p6 = new ListNode(4, p5);
    ListNode* p7 = new ListNode(5, p6);
    ListNode* p8 = new ListNode(5, p7);

    Solution sol;
    ListNode* p = sol.deleteDuplicates(p8);

    while (p)
    {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cin.get();
}