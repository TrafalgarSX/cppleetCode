/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
#if 0
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            // int mid = (left + right) / 2 // left + right 容易溢出
            int mid = left + ((right - left)/2); // 防止溢出
            if(nums[mid] < target) {
                left = mid + 1;
            }else if(nums[mid] > target) {
                right = mid - 1;
            }else {
                return mid;
            }
        }
#else
        int left = 0, right = nums.size();
        while(left < right) {
            // int mid = (left + right) / 2 // left + right 容易溢出
            int mid = left + ((right - left)/2); // 防止溢出
            if(nums[mid] < target) {
                left = mid + 1;
            }else if(nums[mid] > target) {
                right = mid;
            }else {
                return mid;
            }
        }
#endif
        return -1;

    }
};
// @lc code=end

