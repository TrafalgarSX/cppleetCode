/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

#include <vector>
#include <climits>
using namespace std;
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {


    }
    int divide_solution(int dividend, int divisor){
        int ans = 0;



        return ans;
    }

    int divide_cheat(int dividend, int divisor){
        long long int ans = (long long int)dividend / divisor;

        if (ans > INT_MAX)
            ans = INT_MAX ;
        if (ans < INT_MIN)
            ans = INT_MIN;
        return ans;
    }
};
// @lc code=end

