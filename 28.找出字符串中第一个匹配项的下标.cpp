/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    // 朴素解法， 下面的写法最简单直观。
    // TODO KMP解法
    int strStr(string haystack, string needle) {
        // return strStr_easy(haystack, needle);
        return strStr_second(haystack, needle);
    }

private:
    int strStr_KMP(const string& haystack, const string& needle){

        return -1;
    }

    int strStr_easy(const string& haystack, const string& needle){
        int n = needle.size();
        int h = haystack.size();

        for(int i = 0; i + n <= h; i++){
            bool flag = true;
            for (int  j = 0; j < n; j++)
            {
                if(needle[j] != haystack[i + j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        return -1;

    }

    int strStr_std(const string& haystack, const string& needle){
        return haystack.find(needle);
    }


    int strStr_second(const string& haystack, const string& needle){
        int h_size = haystack.length();
        int n_size = needle.length();
        int i = 0;

        while(i < h_size){
            if(haystack[i] == needle[0]){
                int temp = i, it = i;
                for(const auto& ch : needle){
                    if(it >= h_size || ch != haystack[it]){
                        break;
                    }
                    ++it;
                }

                if(it - temp == n_size){
                    return temp;
                }
            }
            ++i;
        }
        return -1;
    }
};
// @lc code=end


int main(void){
  Solution solution;

  std::cout << solution.strStr("mississippi", "issip") << std::endl;
  return 0;
}