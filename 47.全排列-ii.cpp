/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // vector<int> perm;
        // vis.resize(nums.size());
        // sort(nums.begin(), nums.end());
        // backtrack(perm, nums, 0, nums.size());
        backtrack_std(nums, 0, nums.size());

        return ans;
    }

    void backtrack(vector<int> &perm, vector<int>& nums, int current_depth, int depth){
        if(current_depth == depth){
            ans.push_back(perm);
            return;
        }

        for (int i = 0; i < depth; i++)
        {
            // 用vis标记的做法
            // 数据都是从左向右处理， 前面一个的vis[i - 1] = false说明它是被用过的
            // vis[i - 1] = false 说明它在同一层被用过了
            // vis[i - 1] = true 说明它在上一层被用了， 这一层还可以用
            if(vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])){
                continue;
            }
            perm.emplace_back(nums[i]);
            vis[i] = 1;
            backtrack(perm, nums, current_depth + 1, depth);
            perm.pop_back();
            vis[i] = 0;
        }
    }

    void backtrack_std(vector<int> &nums, int current_depth, int depth){
        if(current_depth == depth){
            ans.push_back(nums);
            return;
        }

        std::unordered_set<int> set;
        for(int i = current_depth; i < depth; ++i){
            if(set.find(nums[i]) != set.end()){
                continue;
            }
            set.emplace(nums[i]);
            std::swap(nums[current_depth], nums[i]);
            backtrack_std(nums, current_depth + 1, depth);
            std::swap(nums[i], nums[current_depth]);
        }
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> numbers = {2,2,1,1};
    vector<vector<int>> ans = solution.permuteUnique(numbers);
    for(auto &v: ans)
    {
        for(auto &num : v)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

