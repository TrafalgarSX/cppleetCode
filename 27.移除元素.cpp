/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int left = 0, right = size;

        // [1] 1 的情况
        // [01234567] 6   此时left = 6 right = 
        // 要注意right的大小, right不能是 size - 1
        while(left < right){
            if(nums[left] == val){
                nums[left] = nums[right - 1];
                right--;
            }else{
                left++;
            }
        }

        return left;
    }
};
// @lc code=end

