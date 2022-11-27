> Problem: [45. 跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/description/)

# 思路

为了获取达到最后位置的最小跳跃次数，可以通过动态规划获取达到每个位置的最小跳跃次数，通过前面位置的最优解逐步获取后面位置的最优解，直到获取最后位置的最小跳跃次数。

# 解题方法

1、定义类型为`vector<int>`的数组dp保存每个数组位置的最小跳跃次数，初始值设置为int类型的最大值；

2、将数组dp的首个元素值设置为0，并且定义类型为int的变量`max_pos`用于保存当前所能达到的最大位置；

3、遍历数组，获取当前元素所能达到的最大位置，如果当前最大位置超过max_pos，那么需要更新数组dp在区间(max_pos, cur_max_pos]的值，注意数组不要越界。更新完dp数组在区间(max_pos, cur_max_pos]的值后，更新max_pos的值；

4、将数组dp的最后一个元素值作为结果返回。

# 复杂度
- 时间复杂度: $O(n)$，n为数组个数，需要遍历数组，且数组dp只有一次机会进行设置

- 空间复杂度: $O(n)$，n为数组个数，需要个数为n为的数组dp保存达到每个位置的最小跳跃次数。

# Code
```C++ []

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), numeric_limits<int>::max());  // 保存每个数组位置的最小跳跃次数，初始值设置为最大值
        dp.front() = 0;  // 首位置将跳跃次数设置为0
        int max_pos = 0;  // 当前及其之前位置所能跳跃的最大位置, 初始值设置为0
        for (int i = 0; i < nums.size(); ++i) {
            int cur_max_pos = i + nums[i];  // 获取当前位置所能达到的最大位置
            // 如果当前最大位置超过之前位置能够达到的最大值，需要更新(pre_max, cur_max]区间的最下跳跃次数
            if (cur_max_pos > max_pos) {  
                int j = max_pos + 1;
                while (j < nums.size() && j <= cur_max_pos) {
                    dp[j] = min(dp[j], dp[i] + 1);
                    ++j;
                }
                max_pos = cur_max_pos;
            }
        }
        return dp.back();
    }
};
```