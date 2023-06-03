/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <vector>
#include <iostream>
#include <Set>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> ans;
  vector<vector<int>> combine(int n, int k) {
    vector<int> combine;

    backtrack(combine, n, 0, 0, k);

    return ans;
    }

    // 这一层用过的以后都不能用，但下一层用过的可以用
    void backtrack(vector<int> &combine, int n, int start, int current_depth, int depth){
        if(current_depth == depth){
            ans.push_back(combine);
            return;
        }

        for (size_t i = start; i <  n; i++)
        {
            combine.push_back(i + 1);
            backtrack(combine, n, i + 1, current_depth + 1, depth);
            combine.pop_back();

        }
    }
};
// @lc code=end

