#include <iostream>
#include <vector>

std::vector<int> solution(int n)
{
    // 
    /*
        查看示例后，其实不难发现，这就是直角三角形倒过来
        ##########
        #########
        ########
        #######
        ######
        #####
        ####
        ###
        ##
        #
    */
    std::vector<int> temp;

    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > n - i; j--)
        {
            temp.push_back(j);
        }
    }

    return temp;
}

int main() {
    std::vector<int> result1 = solution(3);
    std::cout << (result1 == std::vector<int>{3, 2, 1, 3, 2, 3}) << std::endl;

    std::vector<int> result2 = solution(4);
    std::cout << (result2 == std::vector<int>{4, 3, 2, 1, 4, 3, 2, 4, 3, 4}) << std::endl;

    std::vector<int> result3 = solution(5);
    std::cout << (result3 == std::vector<int>{5, 4, 3, 2, 1, 5, 4, 3, 2, 5, 4, 3, 5, 4, 5}) << std::endl;

    return 0;
}