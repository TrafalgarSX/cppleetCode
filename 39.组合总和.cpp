/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combine;
        backtrack(candidates, combine, target, 0, candidates.size(), 0);

        return ans;
    }

    void backtrack(vector<int>& candidates, vector<int>& combine, int target, int sum, 
                                              int depth, int pos){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(combine);
            return;
        }

        for (size_t i = pos; i < depth; i++)
        {
            int num = candidates.at(i);
            sum += num;
            combine.push_back(num);
            backtrack(candidates, combine, target, sum, depth, i);
            combine.pop_back();
            sum -= num;
        }
    }
};
// @lc code=end
int main(void){
    Solution solution;
    vector<int> candidates = {4, 2, 8};

    solution.combinationSum(candidates, 8);

    return 0;
}

