/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <string>
#include <bitset>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int posA = a.length() - 1;
        int posB = b.length() - 1;
        int carry = 0;
        string ans;

        if(posA > posB){
            string temp(posA - posB, '0');
            b = temp + b;
            posB = posA;
        }else if(posA < posB){
            string temp(posB - posA, '0');
            a = temp + a;
            posA = posB;
        }
        while(posA >= 0 && posB >= 0){
            int temp = a[posA] - '0' + b[posB] - '0' + carry;
            char c;

            if(temp % 2 == 0){
                c = '0';
            }else{
                c = '1';
            }
            carry = temp >= 2 ? 1 : 0;
            
            ans.insert(ans.begin(), c);
            posA--;
            posB--;
        }
        if(carry == 1){
            ans.insert(ans.begin(), '1');
        }

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

