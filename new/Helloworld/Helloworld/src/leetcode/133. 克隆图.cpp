#include <vector>
#include <unordered_map>

class Node
{
public:
    int val;
    std::vector<Node*> neighbors;

    Node()
    {
        val = 0;
        neighbors = std::vector<Node*>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = std::vector<Node*>();   
    }

    Node(int _val, std::vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // 如果当前节点为空节点，直接返回空即可
        if (!node) return nullptr;

        // 获取当前节点的邻居个数
        if (clone.count(node->val)) return clone[node->val];

        // 创建新节点，用于存储邻居
        Node* ans = new Node();
        ans->val = node->val;
        clone[ans->val] = ans;

        // 创建邻居集合
        std::vector<Node*> neighbors = node->neighbors;
        for (auto neighbor : neighbors)
        {
            Node* temp = cloneGraph(neighbor);
            ans->neighbors.emplace_back(temp);
        }

        return ans;
    }

private:
    std::unordered_map<int, Node*> clone;
};