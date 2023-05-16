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
};
// @lc code=end

