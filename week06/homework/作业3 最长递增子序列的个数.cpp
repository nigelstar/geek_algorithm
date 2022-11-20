
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), 1);
        vector<int> cnt = vector<int>(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
        }

        int max_num = *max_element(dp.begin(), dp.end());

        int ans = 0;
        for (int i = 0; i < dp.size(); ++i) {
            if (dp[i] == max_num) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};