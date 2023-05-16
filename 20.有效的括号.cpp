/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;
// @lc code=start
unordered_map<char, char> quote = {
        {')', '('},
        {'}', '{'},
        {']', '['},
};
class Solution {
public:
    bool isValid(string s) {
        if(1 == s.length() % 2){
            return false;
        }
        stack<char> quote_stack;
        for (auto ch : s)
        {
            // count 是否存在key
            if(quote.count(ch)){
                if(quote_stack.empty() || quote[ch] != quote_stack.top()){
                    return false;
                }
                quote_stack.pop();
            }else{
                quote_stack.push(ch);
            }
        }
        return quote_stack.empty();
    }
};
// @lc code=end

