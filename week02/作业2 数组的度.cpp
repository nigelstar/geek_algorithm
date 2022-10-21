class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<uint16_t, pair<int, int>>> buffer{};
        for (int i = 0; i < nums.size(); ++i) {
            auto it = buffer.find(nums[i]);
            if (it == buffer.end()) {
                buffer[nums[i]] = {1, {i, i}};
            } else {
                ++(it->second.first);
                it->second.second.second = i;
            }
        }

        // 先统计最大的度
        uint16_t maxCnt = 0;
        for (const auto& it : buffer) {
            maxCnt = max(maxCnt, it.second.first);
        }

        // 获取最短连续子数组
        int ans = numeric_limits<int>::max();
        for (const auto& it : buffer) {
            if (it.second.first == maxCnt) {
                ans = min(ans, it.second.second.second - it.second.second.first + 1);
            }
        }

        return ans;
    }
};