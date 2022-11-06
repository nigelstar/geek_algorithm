class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 最低运载能力为单个包裹的最大重量，否则最大重量的包裹将无法运输
        int left = *max_element(weights.begin(), weights.end());  
        // 最大运载能力为所有包括的重量和，从而在一天内完成运输
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (finishTransfer(weights, days, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool finishTransfer(const vector<int>& weights, int days, int max_capacity) {
        int plan_days = 0;
        int capacity = 0;
        for (auto weight : weights) {
            if (capacity + weight <= max_capacity) {
                capacity += weight;
            } else {
                ++plan_days;
                if (plan_days > days) {
                    return false;  // 如果传送带的包裹运送时间已经超过时限，直接返回false
                }
                capacity = weight;
            }
        }

        // 若最后一艘船上的包裹重量不为0，仍需要将运送时间增加1天
        if (capacity != 0) {
            ++plan_days;
        }

        return (plan_days <= days);  
    }
};