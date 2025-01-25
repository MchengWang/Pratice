#include <iostream>
#include <vector>

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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, * tail = &head, * aPtr = a, * bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(std::vector <ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        if (start > end) return nullptr;
        int mid = (start + end) >> 1;
        return mergeTwoLists(merge(lists, start, mid), merge(lists, mid + 1, end));
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};