/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        // 找到第一个 相邻升序的元素
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }

        if(i >= 0){
            int j = nums.size() - 1;
            // 在后面降序序列中找到比nums[i] 大 的第一个元素 
            while(j >= 0 && nums[i] >= nums[j]){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // 将降序序列转为升序序列
        reverse(nums.begin() + i + 1, nums.end());

    }
/**
 * next_permutation(nums.begin(), nums.end());
 * return;
*/
};
// @lc code=end

