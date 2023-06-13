/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <string>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int carry = 0;
        int size = max(a.length(), b.length());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        for(int i = 0; i < size; i++){
            carry += i < a.size() ? a[i] - '0' : 0;
            carry += i < b.size() ? b[i] - '0' : 0;
            ans.push_back(carry % 2 == 1 ? '1' : '0');
            carry /= 2;
        }

        if(carry == 1){
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

int main(int argc, const char** argv) {
    Solution solution ;
    string a("11");
    string b("01");
    string ans = solution.addBinary("1111", "1111");
    std::cout << ans << std::endl;
    int num_a, num_b;

    num_a = stoi(a, nullptr, 2);
    num_b = stoi(b, nullptr, 2);
    bitset<64> bits = (num_a + num_b);
    std::cout << bits.to_string() << std::endl;
    return 0;
}

