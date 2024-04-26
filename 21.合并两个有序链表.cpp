/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>
#include "ListNode.h"
#include "include/ListNode.h"
using namespace std;
// @lc code=start
// * Definition for singly-linked list.
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
class Solution {
public:
#if 0
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head;
        ListNode* temp = &head;

        while(list1 && list2){
            if(list1->val < list2->val){
                temp->next = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        temp->next = list1 == nullptr ? list2 : list1;
        return head.next;
    }
#endif

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* temp = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val >= list2->val){
                temp->next = list2;
                list2 = list2->next;
            }else{
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }

        temp->next = list1 == nullptr ? list2 : list1;
        return dummy.next;
    }
};
// @lc code=end

int main(void){
  Solution solution;

  ListNode* first = ListNode::make_list({1,2,4});
  ListNode* second = ListNode::make_list({1,3,4});

  ListNode* ret = solution.mergeTwoLists(first, second);

  ListNode::print_list(ret);
  return 0;
}

