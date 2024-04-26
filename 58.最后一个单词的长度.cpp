/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <vector>
#include <string>
#include <string.h>
#include <regex>
#include <sstream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;

        // length = lengthOfLastWord_sstream(s);
        // length = lengthOfLastWord_split(s);
        // length = lengthOfLastWord_regex(s);
        length = lengthofLastWord_scan(s);
        return length;
    }

    int lengthofLastWord_scan(const std::string& s){
        int length = 0;
        int i = s.length() - 1;
        while(i >= 0 && s[i] == ' '){
            --i;
        }

        while(i>= 0 && s[i] != ' '){
            ++length;
            --i;
        }

        return length;
    }

    // regex  too slow
    int lengthOfLastWord_regex(string &s){
        std::regex ws_re("\\s+"); // whitespace
        std::vector<std::string> v(
            std::sregex_token_iterator(s.begin(), s.end(), ws_re, -1),
            std::sregex_token_iterator());

        return v.back().length();

    }

    int lengthOfLastWord_split(string &s){
        char *token = strtok(s.data(), " ");
        int length;
        while(token != NULL){
            length = strlen(token);
            token = strtok(NULL, " ");
        }
        return length;
    }

    int lengthOfLastWord_sstream(string &s){

        stringstream ss(s);
        string word;
        int length;

        while(ss >> word){
            length = word.length();
        }

        return length;
    }
};
// @lc code=end

