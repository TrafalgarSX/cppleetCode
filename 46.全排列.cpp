/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> ans;
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> permutation;

    // backtrack(permutation, nums, 0, nums.size());

    backtrack_std(nums, 0, nums.size());

    return ans;
  }

  void backtrack_std(vector<int> &nums, int current_depth, int depth) {
    if (current_depth == depth) {
      ans.push_back(nums);
      return;
    }

    // 把用过的放前面， 后面递归的时候都是没用过的
    for (int i = current_depth; i < depth; ++i) {
      swap(nums[i], nums[current_depth]);
      backtrack_std(nums, current_depth + 1, depth);
      swap(nums[i], nums[current_depth]);
    }
  }

  // 深度优先搜索
  void backtrack(vector<int> &permutation, vector<int> &nums, int current_depth,
                 int depth) {
    if (current_depth == depth) {
      ans.push_back(permutation);
      return;
    }

    for (int i = 0; i < depth; ++i) {
      if (nums[i] != 1000) {
        int temp = nums[i];
        permutation.push_back(nums[i]);
        nums[i] = 1000;
        backtrack(permutation, nums, current_depth + 1, depth);
        nums[i] = temp;
        permutation.pop_back();
      }
    }
  }

  // too complicated, 没必要对nums erase
  // insert操作，我们的目的只是用过的就不再用了
  void backtrack_first(vector<int> &permutation, vector<int> &nums,
                       int current_depth, int depth) {
    if (current_depth == depth) {
      ans.push_back(permutation);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      int temp = nums[i];
      permutation.push_back(temp);
      nums.erase(nums.begin() + i);
      backtrack_first(permutation, nums, current_depth + 1, depth);
      nums.insert(nums.begin() + i, temp);
      permutation.pop_back();
    }
  }

  vector<vector<int>> permute_alg(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    ans.push_back(nums);
    while (next_permutation(nums.begin(), nums.end())) {
      ans.push_back(nums);
    }
    return ans;
  }
};
// @lc code=end
