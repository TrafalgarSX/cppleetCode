/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
using namespace std;
// @lc code=start
#define MASK 
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
#   ifdef MASK
        vector<int> set;
        int size = nums.size();
        for (size_t mask = 0; mask < (1 << size); mask++)
        {
            set.clear();
            for (size_t i = 0; i < size; i++)
            {
                if(mask  & (1 << i)){
                    set.push_back(nums[i]);
                }
            }
            ans.push_back(set);
        }
#   else
        vector<int> set;
        dfs(nums, set, 0, nums.size());
#   endif // MASK
        return ans;
    }

    // 77题组合中的递归法实现子集枚举的方式
    void dfs(vector<int> &nums, vector<int> &set, int current_depth, int depth){
        if(current_depth == depth){
          ans.push_back(set);
          return;
        }

        // 选中当前
        set.push_back(nums[current_depth]);
        dfs(nums, set, current_depth + 1, depth);
        // 不选中档当前
        set.pop_back();
        dfs(nums, set, current_depth + 1, depth);
    }

    // 迭代法
    // 解释： 数组大小为n, 原序列中每个元素的状态有两种： 1-在子集中， 0-不在子集中
    // 这样每个子集可以用一个长度为 n 的二进制序列表示 mask

    

};
// @lc code=end

