/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  /* 暴力法，但是有重复解的问题
   * 排序和判断解和上一个解是否相同,就可以解决重复解的问题
   * */
  vector<vector<int>> threeSum_brutal_froce(vector<int> &nums) {
    vector<vector<int>> res;
    if (nums.size() < 3)
      return res;

    int size = nums.size();
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        for (int k = j + 1; k < size; k++) {
          /* code */
          if (nums[i] + nums[j] + nums[k] == 0) {
            vector<int> tmp;
            tmp.push_back(nums[i]);
            tmp.push_back(nums[j]);
            tmp.push_back(nums[k]);
            res.push_back(tmp);
          }
        }
      }
    }

    return res;
  }
  /* 排序+双指针 */
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    int first, second, third, size, target;
    if (nums.size() < 3)
      return res;

    sort(nums.begin(), nums.end());
    size = nums.size();

    // 利用排序和总和==0的特点，优化代码
    for (first = 0; first < size; ++first) {
      if (first > 0 && nums[first] == nums[first - 1])
        continue;

      third = size - 1;
      target = -nums[first];
      // second 的增加和 third的减少是同时进行的
      // 不会sedond增加后， third回到 size-1的状态
      for (second = first + 1; second < size; second++) {
        if (second > first + 1 && nums[second] == nums[second - 1])
          continue;

        while (second < third && nums[second] + nums[third] > target)
          third--;

        // second的循环结束，没有解了
        if (second == third)
          break;

        if (nums[second] + nums[third] == target)
          res.push_back({nums[first], nums[second], nums[third]});
      }
    }

    return res;
  }
};
// @lc code=end
