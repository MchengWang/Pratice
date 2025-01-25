#include<iostream>

const int MAX = 2345;
// 计算2345正好大于2^31-1，输入输出用scanf和printf不能cin和cout不然超时
__int64 db[MAX];

using namespace std;
int main()
{
    int n, m, i;
    db[1] = 1;
    //打表法 
    for (i = 3; i <= MAX; i += 2)
    {
        db[i] = db[i - 2] + i * i;
    }
    while (scanf("%d", &n) != EOF)
    {
        printf("%I64d\n", db[n]);
    }
    return 0;
}