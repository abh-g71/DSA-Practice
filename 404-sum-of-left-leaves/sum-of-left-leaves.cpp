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
int sum = 0;
    bool isLeaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if( root->left && isLeaf(root->left)){
            sum += root->left->val;
        }
        if(root->left)
        sumOfLeftLeaves(root->left);
        if(root->right )
        sumOfLeftLeaves(root->right);

return sum;
    }
};