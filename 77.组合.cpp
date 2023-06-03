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
  vector<bool> vis;
  vector<vector<int>> combine(int n, int k) {
    vector<int> combine;

    vis.resize(n);
    vector<int> nums;
    for (size_t i = 1; i <= n; i++)
    {
        nums.push_back(i);
    }
    
    backtrack(combine, nums, 0, 0, k);

    return ans;
    }

    // 这一层用过的以后都不能用，但下一层用过的可以用
    void backtrack(vector<int> &combine, vector<int> &nums, int start, int current_depth, int depth){
        if(current_depth == depth){
            ans.push_back(combine);
            return;
        }

        for (size_t i = start; i < nums.size(); i++)
        {
            if(vis[i])
                continue;
            
            combine.push_back(nums[i]);
            vis[i] = true;
            backtrack(combine, nums, i, current_depth + 1, depth);
            vis[i] = false;
            combine.pop_back();

        }
    }
};
// @lc code=end

