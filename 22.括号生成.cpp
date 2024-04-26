/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
#if 0
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string quote;

        backtrack(ans, quote, n, n);
        return ans;
    }
#endif
    /*
    脑内模拟回溯的整个流程不现实，实际上应该从原理上想

    每个位置不是放左括号，就是放右括号。
    如果有剩余的左括号(remain_left > 0)，我们可以放一个左括号。
    如果剩余的左括号小于剩余的右括号，我们可以放一个右括号。

    这就可以保证括号是匹配的。
    
    */
    void backtrack(vector<string> &ans, const string& quote, int remain_left, int remain_right){
        if(remain_left == 0 && remain_right == 0){
            ans.push_back(quote);
            return;
        }

        if(remain_left > 0){
            backtrack(ans, quote + "(", remain_left - 1, remain_right);
        }

        if(remain_left < remain_right){
            backtrack(ans, quote + ")", remain_left, remain_right - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans;

        backtrack(ans, "", n, n);

        return ans;
    }
};
// @lc code=end

int main(void){
  Solution solution;

  return 0;
}
