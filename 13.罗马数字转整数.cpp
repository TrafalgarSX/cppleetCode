/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include<iostream>
#include<string>
#include<utility>
#include<unordered_map>
using namespace std;
// @lc code=start

#if FRONT_TO_END
unordered_map<char, int> valueSymbolsLess= {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
};
#endif
class Solution {
public:

    int romanToInt(string s) {
        // return romanToInt_front_to_end(s);
        return romanToInt_end_to_fron(s);
    }

    int romanToInt_end_to_fron(const string& s){
        int size = s.length();
        int ans = 0;

        for (int i = size - 1; i >= 0; --i)
        {
            switch(s[i]){
                case 'I':{
                    ans += (ans >= 5 ? -1 : 1);
                    break;
                }
                case 'V':{
                    ans += 5;
                    break;
                }
                case 'X':{
                    ans += (ans >= 50 ? -10 : 10);
                    break;
                }
                case 'L':{
                    ans += 50;
                    break;
                }
                case 'C':{
                    ans += (ans >= 500 ? -100 : 100);
                    break;
                }
                case 'D':{
                    ans += 500;
                    break;
                }
                case 'M':{
                    ans += 1000;
                    break;
                }
            }
        }

        return ans;

    }
#if FRONT_TO_END
    int romanToInt_front_to_end(string s) {
        int size = s.length();
        int ans = 0;

        for (size_t i = 0; i < size; i++)
        {
            int value = valueSymbolsLess[s[i]];
            if(i + 1 < size && value < valueSymbolsLess[s[i + 1]]){
                ans -= value;
            }else{
                ans += value;
            }
        }
        return ans;
    }
    // front to end
    int romanToInt_mine(string s) {
        int ans;

        for(int i = 0; i< s.size(); ++i){
            int value = valueSymbolsLess[s[i]];
            if(i + 1 < s.size() && value < valueSymbolsLess[s[i + 1]]){
                ans -= value;
            }else{
                ans += value;
            }
        }

        return ans;
    }
#endif
};
// @lc code=end

