/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <unordered_set>
// @lc code=start
class Solution {
public:
    int get_next(int n) {
        int total_sum = 0;

        while(n) {
            int d = n % 10;
            n /= 10;
            total_sum += d * d;
        }
        return total_sum;
    }


    bool isHappy(int n) {
        std::unordered_set<int> seen;

        while(1) {
            if(n == 1) {
                return true;
            }

            n = get_next(n);
            if(seen.find(n) != seen.end()) {
                return false;
            }else{
                seen.insert(n);
            }
        }
    }
};
// @lc code=end

