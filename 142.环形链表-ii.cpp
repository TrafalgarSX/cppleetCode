/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include "include/ListNode.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto ret = static_cast<ListNode*>(nullptr);
        auto fast = head;
        auto slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                auto encounter = fast;
                auto meet = head;
                while(encounter != meet) {
                    encounter = encounter->next;
                    meet = meet->next;
                }
                ret = meet;
                break;
            }
        }
        
        return ret;
    }
};
// @lc code=end

