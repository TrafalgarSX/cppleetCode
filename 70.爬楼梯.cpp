/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (size_t i = 0; i < n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};
// @lc code=end

int main(int argc, const char** argv) {
    Solution solution;

    std::cout << solution.climbStairs(10) << std::endl;

    return 0;
}

