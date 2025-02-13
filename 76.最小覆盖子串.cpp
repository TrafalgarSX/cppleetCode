/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    std::unordered_map<char, int> ori, cnt;
    string minWindow(string s, string t) {
        for(const auto c : t) {
            ++ori[c];
        }

        int l = 0;
        int lret = 0;
        int len = INT_MAX;

        for(int r = 0; r < s.size(); ++r) {
            if(ori.find(s[r]) != ori.end()) {
                ++cnt[s[r]];
            }

            // l <= r 保证窗口不为空, 也就是保证可以正确处理 s = "a"  t = "a" 这种情况
            while(isWindowCovered() && l <= r) {
                // 因为 isWindowCovered() 最后会 false, 所以这里要保存最小的长度
                if(r - l + 1 < len) {
                    len = r - l + 1;
                    lret = l;
                }
                if(ori.find(s[l]) != ori.end()) {
                    --cnt[s[l]];
                }
                ++l;
            }
        }
    
        return len == INT_MAX ? "" : s.substr(lret, len);
    }
    // 这是正确的处理方式， 不可以用遍历 t 的方式，因为 t 中可能有重复的字符
    // 遍历的方式 t = "bbac"  window = "bac" 也是满足条件的
    bool isWindowCovered() {
        for(const auto c : ori) {
            if(cnt[c.first] < c.second)
            return false;
        }

        return true;
    }
};
// @lc code=end

