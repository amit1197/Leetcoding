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
    int depth=0;
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int level=0;
        helper(root,level);
        return depth+1;
    }
    void helper(TreeNode* root,int level){
        depth=max(level,depth);
        if(root->left) helper(root->left,level+1);
        if(root->right) helper(root->right,level+1);
    }
};