/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>
#include <unordered_map>
#include <array>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        #if 0
        return isAnagram_stl(s, t);
        #else
        return isAnagram_array(s, t);
        #endif
    }

    bool isAnagram_array(string s, string t) {
        std::array<int, 26> alpha{0};

        for(const auto c: s) {
            ++alpha[c - 'a'];
        }

        for(const auto c: t) {
            --alpha[c - 'a'];
        }

        return std::all_of(alpha.begin(), alpha.end(), [](int i) { return i == 0; });
    }

    bool isAnagram_stl(string s, string t) {
        std::unordered_map<char, int> maps, mapt;
        for(const auto c: s) {
            maps[c]++;
        }
        for(const auto c: t) {
            mapt[c]++;
        }

        if(maps != mapt) {
            return false;
        }else{
            return true;
        }
    }
};
// @lc code=end

