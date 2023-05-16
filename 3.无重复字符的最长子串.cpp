/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
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
            map.emplace(s[i], i);
        }

        return maxLength;
    }
};

int main(void){
    Solution solution;

    int length = solution.lengthOfLongestSubstringMap("abcdabc");
    cout<< length << endl;
}
// @lc code=end

