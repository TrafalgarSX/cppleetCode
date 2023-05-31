/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                ans = mid;
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                ans = mid;
                right = mid - 1;
            }
        }

        return ans;
    }
};
// @lc code=end

