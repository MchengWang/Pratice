#include <iostream>
#include <vector>

#define MAX(A, B) A > B ? A : B

class Solution
{
public:
	long long maxEnergyBoost(std::vector<int>& energyDrinkA, std::vector<int>& energyDrinkB)
	{
		// 先计算 n 的大小
		int n = energyDrinkA.size();
		// 创建一个二维数组，用于计算最大能量饮料
		
		// energy[i][0] 代表在第 i 个小时里饮用 A 饮料的最大值
		// energy[i][1] 代表在第 i 个小时里饮用 B 饮料的最大值
		std::vector<std::vector<long long>> energy(n + 1, std::vector<long long>(2, 0));


		for (int i = 0; i < n; i++)
		{
			/*
				其实可以想成打游戏，装备的叠加，如果选择这件装备了，跟之前另一套方案的攻击力相差多少
				是原方案的攻击力高点，还是现在买了一件新装备后的攻击力高。

				可以想成让二维数组每 i 位加上增加的 buff 在跟邻居 i - 1 位上的数值作比较最后取最大值
				
				其实最初我的想法是直接分成几个小区间进行对比，但是这样空间以及时间都会相对应的进行增加，
				但是被我 pass 了，因为我忽略了中间如果说去喝另一款能量饮料的时候，是有一个时间的间隔的。
				但是 “宏定义 MAX” 给了一个很好的处理，如果说另一款的能量饮料比当前的再喝下的能量值都大，
				那我是不是可以认为，我去喝另一家的就可以得到当前能量中最大的那一套方案。
			*/
			energy[i + 1][0] = MAX(energy[i][0] + energyDrinkA[i], energy[i][1]);
			energy[i + 1][1] = MAX(energy[i][1] + energyDrinkB[i], energy[i][0]);
			
		}

		// 返回最大攻击力的方案
		return MAX(energy[n][0], energy[n][1]);
	}
};