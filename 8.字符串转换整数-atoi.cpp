/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;
class Solution {
public:
#if 0
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
#endif


    int myAtoi_std(string s) {
        std::istringstream iss(s);
        int num;
        iss >> num;
        return num;
    }


    int myAtoi(string s) {
        int ans = 0;
        int flag = 1;
        int digit;

        s.erase(0, s.find_first_not_of(' '));
        if(s[0] == '-'){
            flag = -1;
            s.erase(0, 1);
        }else if(s[0] == '+'){
            flag = 1;
            s.erase(0, 1);
        }
        for(const auto& ch : s){
            if(std::isdigit(ch)){
                digit = (ch - '0') * flag;
            }else{
                break;
            }
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit >= 7)){
                return INT_MAX;
            }

            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit <= -8)){
                return INT_MIN;
            }
            ans = ans * 10 + digit;
        }

        return ans;
    }
};
// @lc code=end
int main(void){
  Solution solution;

  std::cout << solution.myAtoi("-2147483649") << std::endl;
  std::cout << std::stoi(" -999") << std::endl;

  std::istringstream iss("want999");
  int num;
  iss >> num;
  std::cout << num << std::endl;
  return 0;
}
