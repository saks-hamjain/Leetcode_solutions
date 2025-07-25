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
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if((root != NULL) and (root ->left == NULL) and (root->right == NULL) 
        and ((targetSum - root->val) ==0)) return true;
        
        bool left =false,right = false;

        if(root != NULL){
        left = hasPathSum(root->left,targetSum - root->val);
         right = hasPathSum(root->right,targetSum - root->val);
        }
        if(left || right) return true;

        return false;
    }
};