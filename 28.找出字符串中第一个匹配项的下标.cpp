/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    // 朴素解法， 下面的写法最简单直观。
    // TODO KMP解法
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int h = haystack.size();

        for(int i = 0; i + n <= h; i++){
            bool flag = true;
            for (int  j = 0; j < n; j++)
            {
                if(needle[j] != haystack[i + j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

