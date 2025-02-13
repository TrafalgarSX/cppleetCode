/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ret = nullptr;

        auto curA = headA;
        auto curB = headB;
        int sizeA = 0;
        int sizeB = 0;

        while(curA) {
            sizeA++;
            curA = curA->next;
        }
        while(curB) {
            sizeB++;
            curB = curB->next;
        }

        ListNode* big = nullptr;
        ListNode* small = nullptr;
        big = sizeA > sizeB ? headA : headB;
        small = sizeA > sizeB ? headB : headA;

        int diff = abs(sizeA - sizeB);

        while(diff--) {
            big = big->next;
        }

        while(big && small) {
            if(big == small) {
                ret = big;
                break;
            }
            big = big->next;
            small = small->next;
        }
        return ret;
    }
};
// @lc code=end

