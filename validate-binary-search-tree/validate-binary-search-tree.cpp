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
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
    bool check(TreeNode* root,TreeNode* low,TreeNode* high){
        if(!root) return true;
        if((low && root->val <=low->val) || (high && root->val >= high->val)) return false;
        return check(root->left,low,root) && check(root->right,root,high);    
    }
};