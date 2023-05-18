//104. 二叉树的最大深度/** * Definition for a binary tree node. * struct TreeNode { *     int val; *     TreeNode *left; *     TreeNode *right; *     TreeNode() : val(0), left(nullptr), right(nullptr) {} *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} * }; */class Solution {public://一个深度优先，一个广度优先（层次遍历）//要懂得回溯是什么用的    int getDepth(TreeNode* node){        if(node == nullptr) return 0;        int lefter = getDepth(node->left);        int righter = getDepth(node->right);        int depth = max(lefter, righter) + 1;        return depth;    }    int maxDepth(TreeNode* root) {        return getDepth(root);    }};