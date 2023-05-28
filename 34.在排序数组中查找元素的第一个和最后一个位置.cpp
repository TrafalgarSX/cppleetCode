/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;

        ans.push_back(left_bound(nums, target));
        ans.push_back(right_bound(nums, target));

        return ans;
    }

    int left_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        // 应该利用短路特性， left >= nums.size()在前，否则会出现nums为空的时候
        // 使用nums[left] 报错
        if(left >= nums.size() || nums[left] != target ){
            return -1;
        }

        return left;
    }

    int right_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid + 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }
        }
        // 应该利用短路特性， right < 0在前，否则会出现nums为空的时候
        // 使用nums[right] 报错
        if(right < 0 || nums[right] != target){
            return -1;
        }

        return right;
    }
};
// @lc code=end

