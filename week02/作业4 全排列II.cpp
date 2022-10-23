class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {  
        numUseFlag_ = vector<bool>(nums.size(), false);
        backtrace(nums);
        return ans_;
    }

private:
    void backtrace(vector<int>& nums) {
        if (nums.size() == trace_.size()) {
            ans_.push_back(trace_);  // 若排列的个数满足条件，则保存结果
            return;
        }
        
        // 每层递归通过一个临时的哈希表保存访问过的元素，若已访问过，那么本层则不访问该元素，从而避免重复的全排列
        unordered_set<int> levelUseFlag{};  
        for (int i = 0; i < nums.size(); ++i) {
            if ((!numUseFlag_[i]) && (levelUseFlag.find(nums[i]) == levelUseFlag.end())) {
                levelUseFlag.insert(nums[i]);
                trace_.push_back(nums[i]);
                numUseFlag_[i] = true;
                backtrace(nums);
                numUseFlag_[i] = false;
                trace_.pop_back();
            }
        }
    }

    vector<vector<int>> ans_;
    vector<int> trace_;
    vector<bool> numUseFlag_;
};