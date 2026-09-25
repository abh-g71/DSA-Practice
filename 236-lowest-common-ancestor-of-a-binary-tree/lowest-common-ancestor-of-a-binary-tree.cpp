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
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || !p  || !q){
            return NULL;
        }
        if(root == p || q == root){
            return root;
        }
        TreeNode* leftAns = dfs(root->left,p,q);
        TreeNode* rightAns = dfs(root->right,p,q);

        if(leftAns && rightAns){
            return root;
        }
        return leftAns ? leftAns : rightAns;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return dfs(root,p,q);
    }
};