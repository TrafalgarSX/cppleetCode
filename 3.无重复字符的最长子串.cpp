/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <assert.h>
using namespace std;
// @lc code=start
class Solution {
public:
#if 0
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0;
        int maxLength = 0;

        if(s.length() == 0) return 0;

        for (int i = 0; i < s.size(); i++)
        {
            while(set.find(s[i]) != set.end()){
                set.erase(s[left]);
                left++;
            }
            maxLength = max(maxLength, i - left + 1);
            set.emplace(s[i]);
        }

        return maxLength;
    }
#endif
    int lengthOfLongestSubstringMap(string s) {
        unordered_map<char,int> map;
        int left = 0;
        int maxLength = 0;

        if(s.length() == 0) return 0;

        for (int i = 0; i < s.size(); i++)
        {
            //这里没有clear之前的元素， 是因为这样用可以把 map看作set
            //找到了 滑动窗口的left就往右移动
            if(map.find(s[i]) != map.end()){
                left = max(left, map.find(s[i])->second + 1);
            }
            maxLength = max(maxLength, i - left + 1);
            // all wrong
            map.emplace(s[i], i);
            map.insert({s[i], i});
        }

        return maxLength;
    }
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0;
        int maxLength = 0;

        if(s.length() == 0) return 0;

        for (int i = 0; i < s.size(); i++)
        {
            //这里没有clear之前的元素， 是因为这样用可以把 map看作set
            //找到了 滑动窗口的left就往右移动
            if(map.find(s[i]) != map.end()){
                left = max(left, map.find(s[i])->second + 1);
            }
            maxLength = max(maxLength, i - left + 1);
            /*
            wrong   emplace不会修改已经存在的键值对
            如果找到了重复的字符， 这里需要更新字符的下标，否则上面的判断中left会往左跳
            map.emplace(s[i], i);
            */

            // right 这里会更新之前重复的字符的下标
            map[s[i]] = i;
        }

        return maxLength;

    }
};
// @lc code=end
int main(void){
    Solution solution;

    int length = solution.lengthOfLongestSubstring("abcabcbb");
    cout<< length << endl;
    assert(length == 3);
}
