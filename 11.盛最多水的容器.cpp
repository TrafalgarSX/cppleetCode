/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
#if 0
    int maxArea(vector<int>& height) {
        int size = height.size();
        int maxWater = 0;
        int temp;

        int i = 0, j = size - 1;
        while(i <= j){
            int water = (j - i) * min(height[i], height[j]);
            if(maxWater < water){
                maxWater = water;
            }
            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }

        return maxWater;
    }
#endif

    //time exceeded
    int maxArea_brutal_force(vector<int>& height) {
        int size = height.size();
        int  maxWater = 0;
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i + 1; j < size; j++)
            {
                int water = (j - i) * min(height[i], height[j]);
                if(maxWater < water){
                    maxWater = water;
                }
            }
            
        }
        return maxWater;       
    }

    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;

        while(left < right){
            int temp_height = std::min(height[left], height[right]);
            ans = std::max(ans, temp_height * (right - left));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return ans;
    }
};
// @lc code=end
int main(void){
  Solution solution;
  std::vector<int> height = {1,8,6,2,5,4,8,3,7};

  int ans = solution.maxArea(height);
  std::cout << ans << std::endl;
  return 0;
}
