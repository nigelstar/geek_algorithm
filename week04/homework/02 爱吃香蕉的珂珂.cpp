class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1e9;  
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (finishEat(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool finishEat(vector<int>& piles, int h, int speed) const {
        int time = 0;
        for (auto pile : piles) {
            time += (pile / speed);
            if (pile % speed != 0) {
                ++time;
            } 
        }
        return time <= h;
    }
};