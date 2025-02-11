/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

#include <cmath>
// @lc code=start
class Solution {
public:
    // NewTon
    int mySqrt(int x){
        if(x == 0) return 0;
        int left = 1, right = x;
        while(left <= right) {
            int mid = left + ((right - left) / 2);
            if(mid < x / mid) {
                left = mid + 1;
            }else if(mid > x / mid) {
                right = mid - 1;
            }else {
                return mid;
            }
        }
        return right;
    }

    //  二分
    int mySqrtBinarySearch(int x){
        if( x == 0){
            return 0;
        }
        int left = 1, right = x;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid == x / mid){
                return mid;
            }
            else if (mid > x / mid){
                right = mid - 1;
            }
            else if (mid < x / mid){
                ans = mid;
                left = mid + 1;

            }
        }
        return ans;

    }

    // newTon
    int mySqrtNewTon(int x){
        if(x == 0){
            return 0;
        }

        double C = x, x0 = x;
        while(true){
            double xi = (x0 + C / x0) * 0.5;
            if(fabs(x0 - xi) < 1e-7){
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }


    int mySqrtEasy(int x) {
        int ans;
        int min  = INT_MAX;
        for (size_t i = 1; i <= (x >> 1); i++)
        {
            if((x - i * i) < min){
                ans = i;
                min = x - i * i;
            }
        }
        return ans;
    }
};
// @lc code=end

