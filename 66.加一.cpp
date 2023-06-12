/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    // return plusOne_mine(digits);
    return plusOne_other(digits);
  }

  vector<int> plusOne_mine(vector<int> &digits) {
    auto iter = digits.rbegin();
    int carry = 1;

    // 模拟进位加法， 一步步模拟
    while (iter != digits.rend()) {
      *iter += carry;
      carry = *iter / 10;
      *iter %= 10;
      iter++;
    }

    if (carry == 1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }

  vector<int> plusOne_other(vector<int> &digits) {
    int len = digits.size();
    // 相比我的少了一些循环， 提前退出了
    for (int i = len - 1; i >= 0; i--) {
      digits[i] = (digits[i] + 1) % 10;
      // 判断 + 1后是不是0， 不是，就可以返回了
      if (digits[i] != 0) {
        return digits;
      }
    }
    vector<int> ans(len + 1);
    ans[0] = 1;
    return ans;
  }
};
// @lc code=end
