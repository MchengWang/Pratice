class Solution {
public:
	int fib(int n) {
		int* nums = new int[31];
		nums[0] = 0;
		nums[1] = 1;
		for (int i = 2; i <= 30; i++)
			nums[i] = nums[i - 2] + nums[i - 1];

		return nums[n];
	}
};