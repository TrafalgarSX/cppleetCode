/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Solution {
public:

    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && (x % 10 == 0))){
            return false;
        }
        int num = 0;
        //如何判断逆转了一半数字？  判断条件 x >= num;
        while(x > num){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return x == num || x == num / 10;
    }
    bool isPalindrome_str(int x) {

        if(x < 0) {
            return false;
        }
        //可以加速
        if(x > 0 && (x % 10 == 0)){
            return false;
        }
        char numbers[11]; // int类型长度最长为10， 字符串多 1
        int len = 0;
        int size = 0;
        // itoa(x, numbers, 10);
        sprintf(numbers, "%d", x);
        len = strlen(numbers) >> 1;
        size = strlen(numbers);
        for (size_t i = 0; i < len; i++)
        {
            if(numbers[i] != numbers[size - i - 1]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

