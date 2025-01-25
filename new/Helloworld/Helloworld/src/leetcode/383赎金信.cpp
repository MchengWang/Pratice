#include <string>
#include <vector>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        std::vector<int> cnt(26);
        for (auto& c : magazine) {
            cnt[c - 'a']++;
        }
        for (auto& c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};