/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string quote;

        backtrack(ans, quote, n, n);
        return ans;
    }
    void backtrack(vector<string> &ans, string quote, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(quote);
            return;
        }

        if(left > 0){
            backtrack(ans, quote + "(", left - 1, right);
        }

        if(left < right){
            backtrack(ans, quote + ")", left, right - 1);
        }
    }
};
// @lc code=end

