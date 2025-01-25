#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 如果list1为空链表，则list2就是需要返回的链表
        if (list1 == nullptr) return list2;
        // 如果list2为空链表，则list1就是需要返回的链表
        else if (list2 == nullptr) return list1;
        // 如果list1的数值小于list2的数值
        else if (list1->val < list2->val) {
            // 将list1的下一个设
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};