#include <iostream>

#define ABS(x) x > 0 ? x : -x

#define XLS(a, b, c) ((a <= b) && (a <= c))

int findMinofTrip(int A[], int n, int B[], int m, int C[], int p)
{
	// D_min 用于记录三元组的最小距离，初值赋值为 INT_MAX;
	int D_min = INT_MAX;

	int i = 0, j = 0, k = 0;
	while (i < n && j < m && k < p && D_min > 0)
	{
		int d = ABS(A[i] - B[j]) + ABS(B[j] - C[k]) + ABS(C[k] - A[i]); // 计算 d
		if (d < D_min) D_min = d; // 更新 d 
		if (XLS(A[i], B[j], C[k])) i++; // 更新 a
		else if (XLS(B[j], C[k], A[i])) j++;
		else k++;
	}
	return D_min;
}

int main()
{
	int numA[3] = { -1, 0, 9 };
	int numB[4] = { -25, -10, 10, 11 };
	int numC[5] = { 2, 9, 17, 30, 41 };

	std::cout << findMinofTrip(numA, 3, numB, 4, numC, 5);
	return 0;
}