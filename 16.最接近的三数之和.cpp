/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int ret;
    int first, second, third, tmp_target;
    int size = nums.size();
    int min;

    for (first = 0; first < size; ++first) {
      if (first > 0 && nums[first] == nums[first - 1])
        continue;

      third = size - 1;
      for (second = first + 1; second < size; ++second) {
        if (second > first + 1 && nums[second] == nums[second - 1])
          continue;

        while(second < third && abs(nums[first] + nums[second] + nums[third] - target) < min)
            third--;

      }
    }

    return ret;
  }
};
// @lc code=end
