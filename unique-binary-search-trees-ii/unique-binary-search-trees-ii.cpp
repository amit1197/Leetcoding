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
    vector<TreeNode*> generateTrees(int n) {
        return makeTrees(1,n);
        
    }
    vector<TreeNode*> makeTrees(int l,int r){
//         base case
        if(l>r){
            return {NULL};
        }
        vector<TreeNode*> ans;
        for(int root=l;root<=r;root++){
            
            vector<TreeNode*> rootLeft=makeTrees(l,root-1);
            vector<TreeNode*> rootRight=makeTrees(root+1,r);
            for(auto i:rootLeft){
                for(auto j:rootRight){
                    TreeNode* node=new TreeNode(root);
                    node->left=i;
                    node->right=j;
                    ans.push_back(node);
                }
            }
            
            
        }
        
        
        
        
        return ans;
        
    }
};