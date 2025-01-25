#include<iostream>
#include<iomanip>

int n;
double s, p;
double sum_s, sum_sp;

int main() {
    while (std::cin >> n) {
        sum_s = sum_sp = 0.0;//学分总和 学分*点数总和
        while (n--)
        {
            std::cin >> s >> p;
            if ((int)p + 1 == 0)  //缺考
                continue;
            sum_s += s;
            if (p >= 90)
                sum_sp += 4 * s;
            else if (p >= 80)
                sum_sp += 3 * s;
            else if (p >= 70)
                sum_sp += 2 * s;
            else if (p >= 60)
                sum_sp += s;

        }
        if (sum_s != 0)
            std::cout << std::fixed << std::setprecision(2) << sum_sp / sum_s << std::endl;
        else
            std::cout << -1 << std::endl;
    }

    return 0;
}