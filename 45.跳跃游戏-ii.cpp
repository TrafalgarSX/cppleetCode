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

    // better 
    int jump(vector<int>& nums) {
        int jump = 0;
        int end  = 0;
        int max_pos = 0;
        // 优化过的
        for (int i = 0; i < nums.size() - 1; i++)
        {

            max_pos = max(max_pos, nums[i] + i);
            // 跳跃完成时(到了end), 更新跳数和下次的跳跃完成点
            if(i == end){
                jump++;
                end = max_pos;
            }
        }
        return jump;
    }

    int jump_mime(vector<int>& nums) {
        int jump = 0;
        int size = nums.size();
        int pos = 0;

        while (pos < size - 1) {
            // 每次判断是否可以跳到终点了
            if(nums[pos] + pos >= size - 1){
                return jump + 1;
            }
            // 找下次可以跳的最远的 pos 
            int max = INT_MIN;
            int cur_pos = pos;
            for (int j = 1; j <= nums[cur_pos]; j++) {
                if((nums[cur_pos + j] + cur_pos + j) > max) {
                    pos = cur_pos + j;
                    max = nums[cur_pos + j] + cur_pos + j;
                }
            }
            // 找到之后就跳，增加跳数
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

