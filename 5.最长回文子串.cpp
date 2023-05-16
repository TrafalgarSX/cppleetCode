/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.length();
        if( size < 2) return s;

        int maxLen = 1;
        int begin = 0;
        vector<vector<bool>> dp(size, vector<bool>(size));
        for (size_t i = 0; i < size; i++)
        {
            dp[i][i] = true;
        }
        //动态规划 状态转移方程的条件是 子串的长度 短向长转移
        for(int len = 2; len <= size; len++){
            for (int i = 0; i < size; i++)
            {
                // j - i + 1 = len
                int j = len + i - 1;
                //右边界越界
                if(j >= size){
                    break;
                }
                if(s[i] != s[j]){
                    dp[i][j] = false;
                }else{
                    //len <= 3的情况  bab  bb
                    if(len < 3){
                        dp[i][j] = true;
                    }else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if(dp[i][j] && j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
            
        }

        return s.substr(begin, maxLen);
    }
};
// @lc code=end

