#include <vector>

class Solution {
public:
    std::vector<int> stableMountains(std::vector<int>& height, int threshold) {
        std::vector<int> vecs;
        for (int i = 1; i < height.size(); i++)
            if (height[i - 1] > threshold) vecs.push_back(i);
        return vecs;
    }
};