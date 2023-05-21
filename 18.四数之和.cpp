/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // 剪枝可以减少执行时间
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size = nums.size();
        int first, second, left, right;
        long long int inner_target;

        if(size < 4){
            return ans;
        }
        sort(nums.begin(), nums.end());

        for (first = 0; first < size - 3; first++)
        {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            // 此处有两个可以剪枝的操作
            if ((long long) nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target)
            {
                break;
            }
            if ((long long) nums[first] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target)
            {
                continue;
            }

            for(second = first + 1; second < size - 2; ++second){
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                // 此处有两个可以剪枝的操作
                if ((long long) nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target)
                {
                    break;
                }
                if ((long long) nums[first] + nums[second] + nums[size - 1] + nums[size - 2] < target)
                {
                    continue;
                }

                left = second + 1;
                right = size - 1;
                while(left < right){
                    inner_target = (long long)nums[first] + nums[second] + nums[left] + nums[right];
                    if(inner_target == target){
                        ans.push_back({nums[first], nums[second], nums[left], nums[right]});
                        // 去除相同的
                        while(left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        left++;
                        // 去除相同的
                        while(left < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        right--;
                    }else if(inner_target < target){
                        left++;
                    }else if(inner_target > target){
                        right--;
                    }

                }
               
            }

        }
        
        

        return ans;
    }
};
// @lc code=end

