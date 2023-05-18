/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int ret = 1e7;
    int first, second, third, tmp_target;
    int size = nums.size();
    sort(nums.begin(), nums.end());

    for (first = 0; first < size; ++first) {
      if (first > 0 && nums[first] == nums[first - 1])
        continue;

      second = first + 1, third = size - 1;
      while(second < third){
        int sum = nums[first] + nums[second] + nums[third];
        if(sum == target){
            return target;
        }

        if(abs(sum - target) < abs(ret - target)){
            ret = sum;
        }

        if(sum > target){
            int temp = third - 1;
            while(second < temp && nums[temp] == nums[third]){
                temp--;
            }
            third = temp;
        }else {
            int temp = second + 1;
            while(temp < third && nums[temp] == nums[second]){
                temp++;
            }
            second = temp;
        }
      }
    }

    return ret;
  }
};
// @lc code=end


// 应该是 lamada表达式
        // // 根据差值的绝对值来更新答案
        // auto update = [&](int cur) {
        //     if (abs(cur - target) < abs(best - target)) {
        //         best = cur;
        //     }
        // };

