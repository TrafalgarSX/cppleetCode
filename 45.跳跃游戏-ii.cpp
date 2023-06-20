/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0;
        int size = nums.size();
        int pos = 0;

        if(1 == size) {
            return 0;
        }
        if(nums[0] >= size - 1){
            return 1;
        }

        while (pos < size - 1) {
            int max = INT_MIN;
            int cur_pos = pos;
            for (int j = 1; j <= nums[cur_pos]; j++) {
                if(cur_pos + j == size - 1){
                    return jump + 1;
                }
                if((nums[cur_pos + j] + cur_pos + j) > max) {
                    pos = cur_pos + j;
                    max = nums[cur_pos + j] + cur_pos + j;
                }
            }

            jump++;
        }
        return jump;
    }
};
// @lc code=end
int main(void){
  Solution solution;
//   vector<int> nums = {1, 2, 3};
  vector<int> nums = {3,4,3,2,5,4,3};
  std::cout << solution.jump(nums) << std::endl;
  return 0;
}

