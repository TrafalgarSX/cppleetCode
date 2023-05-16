/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include<iostream>
#include<string>
#include<utility>
using namespace std;
// @lc code=start
pair<int, string> valueSymbols[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
class Solution {
public:
    //simulate
    string intToRoman(int num) {
        string roman;
        for (auto &[value, symbol] : valueSymbols)
        {
            while(num >= value){
                roman.append(symbol);
                num -= value;
            }
            if(num == 0){
                break;
            }
        }
        

        return roman;
    }
    string intToRoman_hardcode(int num) {
        // string romanAlp[] = {"I", "V", "X", "L", "C", "D", "M", 
        //                      "IV", "IX", "XL", "XC", "CD", "CM"};
        string thousands[] = {"", "M", "MM", "MMM"};
        
        string hunderds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string roman;

        roman = thousands[num / 1000]; 
        num %= 1000;
        roman.append(hunderds[num / 100]);
        num %= 100;
        roman.append(tens[num / 10]);
        num %= 10;
        roman.append(ones[num]);
        return roman;
    }
};
// @lc code=end

