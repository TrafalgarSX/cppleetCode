/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
/*
 * 1. string
 * 2. 回溯
 */

unordered_map<char, string> phoneMap = {
    {'2', "abc"}, 
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.empty()) {
      return ans;
    }
   
   string combination;
   backtrack(ans, digits, combination, 0);
   return ans;
  }

public:
  void backtrack(vector<string> &ans, const string &digits, string combination, int current_depth){
    if(digits.length() == current_depth){
        ans.push_back(combination);
    }else{
        // const string &current_map = phoneMap[digits[current_depth]];
        const string &current_map = phoneMap.at(digits[current_depth]);

        for(const auto &ch: current_map)
        {
            combination.push_back(ch);
            backtrack(ans, digits, combination, current_depth + 1);
            combination.pop_back();
        }
    }
  }
  
};
// @lc code=end
