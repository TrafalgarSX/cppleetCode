/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    std::unordered_map<int, int> cnt;
    int totalFruit(vector<int>& fruits) {
        int ret;
        int l = 0;

        for(int r = 0; r < fruits.size(); ++r) {
            ++cnt[fruits[r]];

            while(cnt.size() > 2) {
                auto it = cnt.find(fruits[l]);
                --it->second;
                if(it->second == 0) {
                    cnt.erase(it);
                }

                ++l;
            }
            ret = std::max(ret, r - l + 1);

        }
        
        return ret;
    }

};
// @lc code=end

