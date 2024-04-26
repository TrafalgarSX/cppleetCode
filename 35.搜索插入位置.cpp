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
#if 0
    // 在一个有序数组中找第一个大于等于 target 的下标
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int ans = nums.size();

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                // 记录当前大于 target的下标
                ans = mid;
                // 继续寻找下一个 大于target的下标
                right = mid - 1;
            }
        }

        return ans;
    }
#endif

    int searchInsert(vector<int>& nums, int target) {
        int ans;

        return ans;
    }
};
// @lc code=end

