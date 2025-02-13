/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> nums_set(nums1.begin(), nums1.end());
        std::unordered_set<int> ret_set;

        for(const auto num: nums2) {
            if(nums_set.find(num) != nums_set.end()) {
                ret_set.insert(num);
            }
        }

        return vector<int>(ret_set.begin(), ret_set.end());
    }
};
// @lc code=end

