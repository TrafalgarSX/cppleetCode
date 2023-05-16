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
};
// #define DEBUG
#ifdef DEBUG
int main(void){
    Solution solution;

    string out = solution.convert("PAYPALISHIRING", 3);
    cout << out <<endl;
}
#endif // DEBUG

// @lc code=end

