#include "basic.h"

class Sort
{
public:
	// 选择排序
	void selectionSort(std::vector<int>& nums)
	{
		int n = nums.size();
		// 外循环，未排序区间为 [i, n - 1]
		for (int i = 0; i < n - 1; i++)
		{
			// 内循环 找到未排序区间内的最小元素
			int k = i;
			for (int j = i + 1; i < n; j++)
			{
				if (nums[j] < nums[k])
					k = j; // 记录最小元素的索引
			}
			// 将最小元素与未排序区间的首个元素交换
			std::swap(nums[i], nums[k]);
		}
	}

	// 冒泡排序
	void bubbleSort(std::vector<int>& nums)
	{
		// 外循环 未排序区间为 [0, i]
		for (int i = nums.size() - 1; i > 0; i--)
		{
			// 内循环 将未排序区间[0, i]中的最大元素交换该区间的最右端
			for (int j = 0; j < i; j++)
			{
				if (nums[j] > nums[j + 1])
					// 交换 nums[j] 与 nums[j + 1]
					// 这里使用了 std::swap() 函数
					std::swap(nums[j], nums[j + 1]);
			}
		}
	}

	// 冒泡排序（标志优化）
	void bubbleSortWithFlag(std::vector<int>& nums)
	{
		// 外循环 未排序区间为 [0, i]
		for (int i = nums.size() - 1; i > 0; i--)
		{
			bool falg = false; // 初始化标志位
			// 内循环 将未排序区间[0, i]中的最大元素交换该区间的最右端
			for (int j = 0; j < i; j++)
			{
				if (nums[j] > nums[j + 1])
				{
					// 交换 nums[j] 与 nums[j + 1]
					// 这里使用了 std::swap() 函数
					std::swap(nums[j], nums[j + 1]);
					falg = true;
				}
			}
			if (!falg)
				break; // 此轮冒泡为交换任何元素，直接跳出
		}
	}

	// 插入排序
	void insertionSort(std::vector<int>& nums)
	{
		// 外循环 未排序区间为 [0, i - 1]
		for (int i = 1; i < nums.size(); i++)
		{
			int base = nums[i], j = i - 1;
			// 内循环 将未排序区间[0, i]中的最大元素交换该区间的最右端
			while (j >= 0 && nums[j] > base)
			{
				nums[j + 1] = nums[j]; // 将 nums[j] 向右移动一位
				j--;
			}
			nums[j + 1] = base; // 将 base 赋值到正确位置
		}
	}

	// 元素交换
	void swap(std::vector<int>& nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}

	// 哨兵划分
	int partition(std::vector<int>& nums, int left, int right)
	{
		// 以 nums[left] 为基准数
		int i = left, j = right;
		while (i < j)
		{
			while (i < j && nums[j] >= nums[left])
				j--; // 从右向左找首个小于基准数的元素
			while (i < j && nums[i] <= nums[left])
				i--; // 从左向右找首个小于基准数的元素
			swap(nums, i, j); // 交换这两个元素
		}
		swap(nums, i, left); // 将基准数交换至两个数组的分界线
		return i;
	}

	// 快速排序
	void quickSort(std::vector<int>& nums, int left, int right)
	{
		// 当子数组长度为 1 时终止递归
		if (left >= right)
			return;
		// 哨兵划分
		int pivot = partition(nums, left, right);
		// 递归左子数组、右子数组
		quickSort(nums, left, pivot - 1);
		quickSort(nums, pivot + 1, right);
	}

	// 选取三个候选元素的中位数
	int midianThree(std::vector<int>& nums, int left, int mid, int right)
	{
		int l = nums[left], m = nums[mid], r = nums[right];
		if ((l <= m && m <= r) || (r <= m && m <= l))
			return mid; // m 在 l 和 r 之间
		if ((m <= l && l <= r) || (r <= l && l <= m))
			return left; // l 在 m 和 r 之间
		return right;
	}

	// 哨兵划分(三数中位数)
	int partitionT(std::vector<int>& nums, int left, int right)
	{
	    // 选取三个候选元素的中位数
		int mid = midianThree(nums, left, (left + right) / 2, right);
		// 将中位数交换值数组最左端
		swap(nums, left, mid);
		// 以 nums[left] 为基准数
		int i = left, j = right;
		while (i < j)
		{
			while (i < j && nums[j] >= nums[left])
				j--; // 从右向左找首个小于基准数的元素
			while (i < j && nums[i] <= nums[left])
				i--; // 从左向右找首个小于基准数的元素
			swap(nums, i, j); // 交换这两个元素
		}
		swap(nums, i, left); // 将基准数交换至两个数组的分界线
		return i;
	}

	// 快速排序（尾递归优化）
	void quickSortR(std::vector<int>& nums, int left, int right)
	{
		// 当子数组长度为 1 时终止递归
		while (left < right)
		{
			// 哨兵划分
			int pivot = partition(nums, left, right);
			// 对两个子数组中较短的那个执行快速排序
			if (pivot - left < right - pivot)
			{
				quickSort(nums, left, pivot - 1); // 递归排序左子数组
				left = pivot + 1; // 剩余未排序区间为 [pivot + 1, right]
			}
			else
			{
				quickSort(nums, pivot + 1, right); // 递归排序右子数组
				right = pivot - 1; // 剩余未排序区间为 [left, pivot - 1]
			}
		}
	}

	// 合并左子数组和右子数组
	void merge(std::vector<int>& nums, int left, int mid, int right)
	{
		// 左子数组区间为 [left, mid],右子数组区间为 [mid + 1, right]
		// 创建一个临时数组 tmp， 用于存放合并后的结果
		std::vector<int> tmp(right - left + 1); 
		// 初始化左子数组和右子数组的起始索引
		int i = left, j = mid + 1, k = 0;
		// 当左右子数组都还有元素时，进行比较并将较小的元素复制到临时数组中
		while (i <= mid && j <= right)
		{
			if (nums[i] <= nums[j])
				tmp[k++] = nums[i++];
			else
				tmp[k++] = nums[j++];
		}
		// 将左子数组和右子数组的剩余元素复制到临时数组中
		while (i <= mid)
			tmp[k++] = nums[i++];
		while (i <= right)
			tmp[k++] = nums[i++];
		// 将临时数组 tmp 中的元素复制回到原数组 nums 的对应区间
		for (k = 0; k < tmp.size(); k++)
			nums[left + k] = tmp[k];
	}

	// 归并排序
	void mergeSort(std::vector<int>& nums, int left, int right)
	{
		// 终止条件
		if (left >= right) return; // 当子数组长度为 1 时终止递归
		// 划分阶段
		int mid = (left + right) / 2; // 计算中点
		mergeSort(nums, left, mid); // 递归左子数组
		mergeSort(nums, mid + 1, right); // 递归右子数组
		// 合并阶段
		merge(nums, left, mid, right);
	}

	// 堆的长度为 n，从节点 i 开始，从顶至底堆化
	void siftDown(std::vector<int>& nums, int n, int i)
	{
		while (true)
		{
			// 判断节点 i，l, r 中值最大的节点，记为 ma
			int l = 2 * i + 1;
			int r = 2 * i + 2;
			int ma = i;
			if (l < n && nums[l] > nums[ma])
				ma = l;
			if (r < n && nums[r] > nums[ma])
				ma = r;
			// 若节点 i 最大或索引 l, r 越界，则无需继续堆化，跳出
			if (ma == i) break;
			// 交换两节点
			std::swap(nums[i], nums[ma]);
			// 循环向下堆化
			i = ma;
		}
	}

	// 堆排序
	void heapSort(std::vector<int>& nums)
	{
		// 建堆操作：堆化除节点以外的其他所有节点
		for (int i = nums.size() / 2 - 1; i >= 0; --i)
			siftDown(nums, nums.size(), i);
		// 从堆中提取最大元素，循环 n - 1 轮
		for (int i = nums.size() - 1; i > 0; --i)
		{
			// 交换根节点与最右叶节点（交换首元素与尾元素）
			std::swap(nums[0], nums[i]);
			// 以根节点为起点，从顶至底进行堆化
			siftDown(nums, i, 0);
		}
	}

	// 桶排序
	void bucketSort(std::vector<float>& nums)
	{
		// 初始化 k = n / 2 个桶，预期向每个桶分配 2 个元素
		int k = nums.size() / 2;
		std::vector<std::vector<float>> buckets(k);
		// 1、将数组元素分配到各个桶中
		for (float num : nums)
		{
			// 输入数据范围为 [0, 1), 使用 num * k 映射到范围 [0, k -1]
			int i = num * k;
			// 将 num 添加进桶 bucket_idx
			buckets[i].push_back(num);
		}
		// 2、对各个桶进行排序
		for (std::vector<float>& bucket : buckets)
			// 使用内置排序函数，也可以替换成其他排序算法
			std::sort(bucket.begin(), bucket.end());
		// 3、遍历桶合并结果
		int i = 0;
		for (std::vector<float>& bucket : buckets)
			for (float num : bucket)
				nums[i++] = num;
	}

	// 计数排序
	// 简单实现，无法用于排序对象
	void countingSortNaive(std::vector<int>& nums)
	{
		// 1、统计数组最大元素 m
		int m = 0;
		for (int num : nums)
			m = std::max(m, num);
		// 2、统计各数字的出现次数
		// counter[num] 代表 num 的出现次数
		std::vector<int> counter(m + 1, 0);
		for (int num : nums)
			counter[num]++;
		// 3、遍历 counter ，将各元素填入原数组 nums
		int i = 0;
		for (int num = 0; num < m + 1; num++)
		{
			for (int j = 0; j < counter[num]; j++, i++)
			{
				nums[i] = num;
			}
		}
	}

	// 计数排序
	// 完整实现，可排序对象，并且是稳定排序
	void countingSort(std::vector<int>& nums)
	{
		// 1、统计数组最大元素 m
		int m = 0;
		for (int num : nums)
			m = std::max(m, num);
		// 2、统计各数字的出现次数
		// counter[num] 代表 num 的出现次数
		std::vector<int> counter(m + 1, 0);
		for (int num : nums)
			counter[num]++;
		// 3、求 counter 的前缀和，将出现次数转换为尾索引
		// 即 counter[num] - 1 是 num 在 res 中最后一次出现的索引
		for (int i = 0; i < m; i++)
			counter[i + 1] = counter[i];
		// 4、倒序遍历 nums, 将各元素填入结果数组 res
		// 初始化数组 res 用于记录结果
		int n = nums.size();
		std::vector<int> res(n);
		for (int i = n - 1; i >= 0; i--)
		{
			int num = nums[i];
			res[counter[num] - 1] = num; // 将 num 放置到对应索引处
			counter[num]--; // 令前缀和自减 1，得到下次放置 num 的索引
		}
		// 使用结果数组 res 覆盖原数组 nums
		nums = res;
	}

	// 获取元素 num 的第 k 位，其中 exp = 10^(k - 1)
	int digit(int num, int exp)
	{
		// 传入 exp 而非 k 可以避免在此重复执行昂贵的次方计算
		return (num / exp) % 10;
	}

	// 计数排序（根据 num 第 k 位排序）
	void countingSortDigit(std::vector<int>& nums, int exp)
	{
		// 十进制的位范围位 0~9 ，因此需要长度为 10 的桶数组
		std::vector<int> counter(10, 0);
		int n = nums.size();
		// 统计 0~9 各数字的出现次数
		for (int i = 0; i < n; i++)
		{
			int d = digit(nums[i], exp); // 获取 nums[i] 的第 k 位，记为 d
			counter[d]++; // 统计数组 d 的出现次数
		}
		// 求前缀和，将出现个数转换为数组索引
		for (int i = 1; i < 10; i++)
			counter[i] += counter[i - 1];
		// 倒序遍历，根据桶内统计结果，将个元素填入 res
		std::vector<int> res(n, 0);
		for (int i = n - 1; i >= 0; i--)
		{
			int d = digit(nums[i], exp);
			int j = counter[d] - 1; // 获取 d 在数组中的索引 j
			res[j] = nums[i]; // 将当前元素填入索引 j
			counter[d]--; // 将 d 的数量减 1
		}
		// 使用结果数组 res 覆盖原数组 nums
		for (int i = 0; i < n; i++)
			nums[i] = res[i];
	}

	// 基数排序
	void radixSort(std::vector<int>& nums)
	{
		// 获取数组的最大元素，用于判断最大位数
		int m = *max_element(nums.begin(), nums.end());
		// 按照从低位到高位的顺序遍历
		for (int exp = 1; exp <= m; exp *= 10)
			// 对数组元素的第 k 位执行计数排序
			// k = 1 -> exp = 1
			// k = 2 -> exp = 10
			// 即 exp = 10^(k - 1)
			countingSortDigit(nums, exp);
	}
};