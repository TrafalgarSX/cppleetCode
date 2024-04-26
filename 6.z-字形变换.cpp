/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
#if 0
    string convert(string s, int numRows) {
        int size = s.length();
        if(1 == numRows || size <= numRows){
            return s;
        }
        int flag = 1;
        int line = 0;
        string res;
        vector<string> vec_res(numRows);
        
        for(auto c: s)
        {
            vec_res[line].push_back(c) ;
            line += flag;
            if(line == numRows - 1 || line == 0){
                flag = -flag;
            }
        }

        for (auto s : vec_res)
        {
            res.append(s);
        }
        return res; 
    }
#endif
    enum class direction {up, down};

    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        vector<string> vec_res(numRows);
        int line_pos = 0;
        direction direct = direction::down;
        for(const auto& ch : s){
            vec_res[line_pos] += ch;
            if(direct == direction::down){
                ++line_pos;
            }else if (direct == direction::up) {
                --line_pos;
            }
            if(line_pos == 0){
                direct = direction::down;
            }else if(line_pos == numRows - 1){
                direct = direction::up;
            }
        }

        string ret;

        for(const auto& line : vec_res){
            ret += line;
        }
        return ret;
    }
};
#if 0
int main(void){
    Solution solution;

    string out = solution.convert("PAYPALISHIRING", 3);
    std::cout << out << ":compare result is :" << out.compare("PAHNAPLSIIGYIR") << std::endl;

    out = solution.convert("PAYPALISHIRING", 4);
    std::cout << out << ": compare result is :" << out.compare("PINALSIGYAHRPI") << std::endl;

}
#endif

// @lc code=end

