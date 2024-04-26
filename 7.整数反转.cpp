/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include<iostream>
#include<limits>
using namespace std;
// @lc code=start
class Solution {
public:
#if 0
    int reverse(int x) {
        if(0 == x) return 0;

        int reverseNum = 0; 
        int digit = 0;
        while(0 != x){
            digit = x % 10;
            // if(reverseNum > 214748364 || (reverseNum == 214748364 && digit > 7)){
            //     return 0;
            // }
            // if(reverseNum < -214748364 || (reverseNum == -214748364 && digit < -8)){
            //     return 0;
            // }
            //Better
            //当x位数与 int_max int_min相同时， digit是最高位 不可能大于2  digit <= 2
            if(reverseNum > INT_MAX / 10 || reverseNum < INT_MIN / 10){
                return 0;
            }
            reverseNum = reverseNum * 10 + digit;
            x /= 10;
        }
        return reverseNum;
    }
#endif

    int reverse(int x) {
        int reverse_num = 0;
        int digit;

        while(x != 0){
            digit = x % 10;

            if(reverse_num > INT_MAX / 10 || reverse_num < INT_MIN / 10){
                return 0;
            }
            // 注意这里计算 reverse_num 和判断  reverse_num 的相对位置
            reverse_num = reverse_num * 10 + digit;
            x /= 10;
        }

        return reverse_num;
    }
};
// @lc code=end

int main()
{
    Solution solution;

    std::cout << solution.reverse(-2147483412) << std::endl;

    std::cout << -123 % 10  << std::endl;
    
    return 0;
}
 