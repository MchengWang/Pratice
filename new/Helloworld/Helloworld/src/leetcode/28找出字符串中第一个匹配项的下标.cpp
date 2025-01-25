#include <iostream>
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (haystack.length() == 0 || needle.length() == 0) return -1;

        int neeIndex = 0;
        for (int hayIndex = 0; hayIndex < haystack.length(); hayIndex++)
        {
            if (haystack.at(hayIndex) == needle.at(neeIndex))
            {
                neeIndex++;
                if (neeIndex == needle.length()) return hayIndex - neeIndex + 1;
            }
            else
            {
                hayIndex = hayIndex - neeIndex;
                neeIndex = 0;
            }
        }

        return -1;

    }

    /*int strStr(std::string haystack, std::string needle)
    {
        int hayLen = haystack.size(), neeLen = needle.size();
        for (int i = 0; i + neeLen <= hayLen; i++)
        {
            bool flag = true;
            for (int j = 0; j < neeLen; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                return i;
            }
        }
        return -1;
    }*/
};

int main()
{
    Solution sol;
    std::cout << sol.strStr("a", "a") << std::endl;
    std::cin.get();
}