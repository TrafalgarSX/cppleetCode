/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include<iostream>
#include<string>
#include<limits>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int size = s.size();
        int ret = 0;
        int flag;
        int i = 0;

        s.erase(0, s.find_first_not_of(" "));
        if(s[0] == '-'){
            flag = -1;
            i = 1;
        }else {
            flag = 1;
            if(s[0] == '+')  
              i = 1;
        }
        for (; i < size; i++)
        {
            char ch = s[i];
            if(isdigit(ch) == false){
                break;
            }
            if(flag == 1){
                if((ret > 214748364 || (ret == 214748364 && (ch - '0') >= 7))){
                    return INT_MAX;
                }               
                ret = ret * 10 + (ch -'0');
            }else{
                if((ret > 214748364 || (ret == 214748364 && (ch - '0') >= 8))){
                    return INT_MIN;
                }
                ret = ret * 10 + (ch -'0');
            }

        }
         
        return ret * flag; 
    }
};
// @lc code=end

