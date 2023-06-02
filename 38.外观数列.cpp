/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";

        for(int i = 1; i < n; i++){
            string cur;
            int start = 0;
            int pos = 0;
            int size = prev.size();
            while(pos < size){
                while(pos < size && prev[pos] == prev[start]){
                    pos++;
                }
                cur += to_string(pos - start) + prev[start];
                start = pos;
            }
            prev = cur;

        }

        return prev;
    }
};
// @lc code=end

