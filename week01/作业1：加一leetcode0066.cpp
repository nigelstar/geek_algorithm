/* 

给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。 

*/

// 由于最后一位加1和进位加1的效果一致，那么可以直接在数组中从后往前进行遍历。解题思路如下：
// 1. 从后往前遍历数组，将每个整数与1相加，将相加后的结果与10进行求余，如果求余后的值不为0，则直接返回结果，否则继续遍历；
// 2. 当遍历结束后，如果数组首位的结果为0，那么需要在数组头部加入一个整数1，否则直接返回结果。

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i) {
            ++digits[i];  // 个数位加1或者进位加1
            digits[i] %= 10;
            if (digits[i] != 0) {
                return digits;
            }
        }
        if (digits.front() == 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};