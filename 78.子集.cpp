/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> set;
        ans.push_back(set);
        dfs(nums, set, 0, nums.size());

        return ans;
    }

    // 77题组合中的递归法实现子集枚举的方式
    void dfs(vector<int> &nums, vector<int> &set, int current_depth, int depth){
        if(current_depth == depth){
            return;
        }

        set.push_back(nums[current_depth]);
        ans.push_back(set);
        dfs(nums, set, current_depth + 1, depth);

        set.pop_back();
        dfs(nums, set, current_depth + 1, depth);

    }
};
// @lc code=end

