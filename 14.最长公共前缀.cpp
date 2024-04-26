/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include<iostream>
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    std::string longestCommonPrefix(const std::string& str1, const std::string& str2){

        int size = std::min(str1.length(), str2.length());
        for (int i = 0; i < size; ++i) {
            if(str1[i] != str2[i]){
                return str1.substr(0, i);
            }
        }
        return str1.length() > str2.length() ? str2 : str1;
    }

    //横向   二分法横向 两种方法  二分法比较有意思（递归）
    std::string longestCommonPrefix(vector<string>& strs) {
        int i = 0; 
        int j = i + 1;
        std::string prefix = strs[0];
        
        for(; j < strs.size(); ++j){
            prefix = longestCommonPrefix(prefix, strs[j]);
            if(prefix.empty()){
                return prefix;
            }
        }

        return prefix;
    }
    //纵向比较
    string longestCommonPrefixVertical(vector<string>& strs) {
        for(int i = 0; i < strs[0].length(); ++i){
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); ++j){
                if(i == strs[j].length() || strs[j][i] != ch){
                    return strs[0].substr(0,i);
                }
            }
        }

        return strs[0];

    }
};
// @lc code=end

int main(void){
  Solution solution;
  std::vector<std::string> strs{"aaa","aa","aaa"};

  std::string ans = solution.longestCommonPrefix(strs);
  std::cout << "result is: " << ans << std::endl;
  return 0;
}
