#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// #define BRUTAL_FORCE
#define DOUBLE_POINTER
// #define DYNAMIC_PROGRAMMING
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    enum class direction {
        left,
        right 
    };
    int find_border(vector<int>& height, int index, direction direct)
    {
        int max = height[index];
        int border = index;

        if(direct == direction::left){
            for(int i = index - 1; i >=0; --i){
                if(height[i] > max){
                    border = i;
                    max = height[i];
                }
            }
        }else if(direct == direction::right){
            for(int i = index + 1; i < height.size(); ++i){
                if(height[i] > max){
                    border = i;
                    max = height[i];
                }
            }
        }
        return border;
    }
    // brutal force
#ifdef BRUTAL_FORCE
    int trap(vector<int>& height) {
        int size = height.size();
        int ret = 0;

        for(int i = 1; i < size - 1; ++i)
        {
            int left_border = find_border(height, i, direction::left);
            int right_border = find_border(height, i, direction::right);
            int min = std::min(height[left_border], height[right_border]);

            if(height[i] < min){
                ret += min - height[i];
            }
        }
        return ret;
    }
#endif
#ifdef DYNAMIC_PROGRAMMING
    int trap(vector<int>& height) {
        int ret = 0;
        int size = height.size();

        return ret;
    }
#endif

// #ifdef DOUBLE_POINTER
#if 1
    int trap(vector<int>& height) {
        int ret = 0;

        int left =0, right = height.size() - 1;
        int left_max = 0, right_max = 0;

        while(left < right){
            left_max = std::max(height[left], left_max);
            right_max = std::max(height[right], right_max);
            if(height[left] < height[right]){
                ret += left_max - height[left];
                left++;
            }else{
                ret += right_max - height[right];
                right--;
            }
        }

        return ret;
    }
#endif
};
// @lc code=end

#if 1
int main()
{
    Solution solution;
    vector<int> height0{0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height1{4,2,0,3,2,5};
    vector<int> height2{0,2,0};
    vector<int> height3{4,2,3};

    int water_sum = solution.trap(height0);
    std::cout << "trap water is :" << water_sum << std::endl;

    water_sum = solution.trap(height1);
    std::cout << "trap water is :" << water_sum << std::endl;

    water_sum = solution.trap(height2);
    std::cout << "trap water is :" << water_sum << std::endl;

    water_sum = solution.trap(height3);
    std::cout << "trap water is :" << water_sum << std::endl;

    vector<int> height4(40000, 1);
    water_sum = solution.trap(height4);
    std::cout << "trap water is :" << water_sum << std::endl;

    return 0;
}

#endif

