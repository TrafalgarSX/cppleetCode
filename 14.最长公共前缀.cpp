/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    //横向   二分法横向 两种方法  二分法比较有意思（递归）
    string longestCommonPrefix(vector<string>& strs) {

    }
    //纵向比较
    string longestCommonPrefixVertical(vector<string>& strs) {
        int size = strs.size();
        if(size == 1){
            return strs[0];
        }

        string first = strs[0];
        int length = first.length();
        for (int i = 0; i < length; i++)
        {
            for (int j = 1; j < size; j++)
            {
                if(i == strs[j].length() || strs[j][i] != first[i]){
                    return first.substr(0, i);
                }
            }
        }
        return first;
    }
};
// @lc code=end

