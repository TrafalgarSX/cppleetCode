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

unordered_map<string, int> valueSymbols = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}
};
unordered_map<char, int> valueSymbolsLess= {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
};
class Solution {
public:

    //end to front
    int romanToInt(string s) {
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

    int romanToInt_mine(string s) {
        int size = s.length();       
        int roman = 0;

        for (size_t i = 0; i < size; i++)
        {
            if(i + 1 < size ){
                auto iter = valueSymbols.find(s.substr(i, 2));
                if(iter != valueSymbols.end()){
                    roman += iter->second;
                    i++;
                    continue;
                }
            }
            roman += valueSymbols.find(s.substr(i, 1))->second;
        }
        return roman; 
    }
};
// @lc code=end

