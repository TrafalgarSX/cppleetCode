#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <TreeNode.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#if 0
    /**
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if(!root){
            return ret;
        }

        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        TreeNode* temp;
        // true is left2right
        bool direct = true;

        while(!queue.empty()){
            std::vector<int> temp_vec;
            int size = queue.size();

            for(int i = 0; i < size; ++i){
                if(direct){
                    temp = queue.front(); 
                    queue.pop_front();
                }else{
                    temp = queue.back();
                    queue.pop_back();
                }
                
                temp_vec.emplace_back(temp->val);

                if(direct){
                    if(temp->left) queue.emplace_back(temp->left);
                    if(temp->right) queue.emplace_back(temp->right);
                }else{
                    if(temp->right) queue.emplace_front(temp->right);
                    if(temp->left) queue.emplace_front(temp->left);
                }
            }
            direct = !direct;
            ret.emplace_back(temp_vec);
        }

        return ret;
    }
#endif
    /**

    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if(!root){
            return ret;
        }

        std::queue<TreeNode*> queue;
        queue.emplace(root);
        TreeNode* temp;
        bool is_left = true;

        while(!queue.empty()){
            int size = queue.size();
            std::deque<int> temp_array;

            for(int i = 0; i < size; ++i){
                temp = queue.front(); queue.pop();
                if(is_left){
                    temp_array.emplace_back(temp->val);
                }else{
                    temp_array.emplace_front(temp->val);
                }
                if(temp->left) queue.emplace(temp->left);
                if(temp->right) queue.emplace(temp->right);
            }
            is_left = !is_left;
            ret.emplace_back(std::vector<int>{temp_array.begin(), temp_array.end()});
        }

        return ret;
    }
};
// @lc code=end

int main(void){
    Solution solution;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> ret = solution.zigzagLevelOrder(root);

    std::cout << "[";
    for(const auto& its : ret){
        std::cout << "[";
        for(const auto& it : its){
            std::cout << it << ",";
        }
        std:cout << "]" << ",";

    }
    std::cout << "]";
    return 0;

}