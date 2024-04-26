#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <TreeNode.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ret;
        if(!root){
            return ret;
        }

        std::queue<TreeNode*> queue;
        queue.emplace(root);
        TreeNode* temp;

        while(!queue.empty()){
            std::vector<int> temp_vec;
            int size = queue.size();

            for(int i = 0; i < size; ++i){
                temp = queue.front(); queue.pop();
                temp_vec.emplace_back(temp->val);
                if(temp->left) queue.emplace(temp->left);
                if(temp->right) queue.emplace(temp->right);
            }

            ret.emplace_back(temp_vec);
        }

        return ret;
    }
};
// @lc code=end
int main()
{
    Solution solution;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    std::vector<std::vector<int>> ret = solution.levelOrder(root);

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
