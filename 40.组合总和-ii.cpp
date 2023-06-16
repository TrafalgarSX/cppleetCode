/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> combine;

        // 排序， 方便去重判断。
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, combine, target, 0, 0, 0, candidates.size());

        return ans;
    }

    void backtrack(vector<int>& candidates, vector<int>& combine, int target, int pos, 
                                            int sum, int current_depth, int depth){
        if(sum == target){
            ans.push_back(combine);
            return;
        }

        if(current_depth == depth){
            return;
        }

        // pos + 1可以保证，每个数字在每个组合中只能使用一次
        for (size_t i = pos; i < depth; i++)
        {
            // 去重， 这样解集中不会包含重复的组合
            if( i > pos && candidates[i] == candidates [i - 1]){
                continue;
            }
            int num = candidates.at(i);
            sum += num;
            // 剪枝，否则会超时
            if( sum <= target){
                combine.push_back(num);
                backtrack(candidates, combine, target, i + 1, sum,
                          current_depth + 1, depth);
                combine.pop_back();
            }else{
                break;
            }
            sum -= num;
        }

    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution solution;
    // solution.combinationSum2();
    return 0;
}


