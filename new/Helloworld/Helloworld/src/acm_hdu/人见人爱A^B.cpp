# include <iostream>

int main()
{
    int A, B;
    // 当输入的数值同时为 0 时结束
    while (std::cin >> A >> B && (A != 0 && B != 0)) 
    {
        //如果A大于999，则只取A的后三位数进行后面的计算即可
        if (A > 999)
            A %= 1000;

        int num = A;
        int ge, shi, bai;

        ge = num % 10; // 个位  
        shi = num % 100 / 10; // 十位
        bai = num / 100; // 百位

        // num = (原百位数的个位*num*1 + 十位*num*10 + 百位*num*100) % 1000
        for (int i = 1; i < B; i++)     //需要注意循环相乘的次数
            num = (ge * num + shi * num * 10 + bai * num * 100) % 1000;

        //输出结果
        std::cout << num << std::endl;
    }

    return 0;
}

