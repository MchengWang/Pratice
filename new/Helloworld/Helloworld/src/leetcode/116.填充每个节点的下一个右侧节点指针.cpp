#include <iostream>
#include <queue>

struct Node
{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() :val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int x, Node* left, Node* right, Node* next)
        :val(x), left(left), right(right), next(next) {}
};

/*
    判断一层节点是否结束，可以判断是否满足数学公式
    (count % 2) - 1 == 0;
    完美二叉树，全部节点一共为 2 ^ n - 1 个节点
*/

//class Solution {
//public:
//    Node* connect(Node* root) {
//        if (!root) 
//            return root;
//
//        // 初始化队列同时将第一层节点加入队列中，即根节点
//        std::queue<Node*> que;
//        que.push(root);
//
//        // 外层的 while 循环迭代的是层数
//        while (!que.empty()) {
//
//            // 记录当前队列大小
//            int size = que.size();
//
//            // 遍历这一层的所有节点
//            for (int i = 0; i < size; i++) {
//
//                // 从队首取出元素
//                Node* node = que.front();
//                que.pop();
//
//                // 连接
//                if (i < size - 1) 
//                    node->next = que.front();
//
//                // 拓展下一层节点
//                if (node->left)
//                    que.push(node->left);
//                if (node->right) 
//                    que.push(node->right);
//            }
//        }
//
//        // 返回根节点
//        return root;
//    }
//};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        // 从根节点开始
        Node* leftmost = root;

        while (leftmost->left != nullptr) {

            // 遍历这一层节点组织成的链表，为下一层的节点更新 next 指针
            Node* head = leftmost;

            while (head != nullptr) {

                // CONNECTION 1
                head->left->next = head->right;

                // CONNECTION 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                // 指针向后移动
                head = head->next;
            }

            // 去下一层的最左的节点
            leftmost = leftmost->left;
        }

        return root;
    }
};