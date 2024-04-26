#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ListNode.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first = nullptr;
        ListNode* second = head;
        ListNode* temp;

        while(second){
            temp = second->next;
            
            second->next = first;
            first = second;
            second = temp;
        }

        return first;
    }
};
// @lc code=end

int main(void){
  Solution solution;
  ListNode* head = ListNode::make_list({1,2,3,4,5});

  ListNode* reverse_head = solution.reverseList(head);
  ListNode::print_list(reverse_head);
  return 0;
}

