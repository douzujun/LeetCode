/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	// 方法一：递归
        // vector<int> ans;
        // inorder(root, ans);
        // return ans;
        
        // 方法二：迭代
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode *rt = root;
        while (rt || S.size())
        {
            while (rt) {
                S.push(rt);
                rt = rt->left;
            }
            rt = S.top(); S.pop();
            v.push_back(rt->val);
            rt = rt->right;
        }
        return v;
    }

    void inorder(TreeNode *root, vector<int>& ans) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
};
// @lc code=end

