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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
       if(root == nullptr) return res;
       queue<TreeNode*>q;
       q.push(root);
       int flag =0;
       while(!q.empty())
       {
         int n = q.size();
         vector<int> temp;
         for(int i=0;i<n;i++)
         {
            TreeNode* first = q.front();
            q.pop();
            
            if(first->left != NULL) q.push(first->left);
            if(first->right != NULL) q.push(first->right);

            temp.push_back(first->val);
         }
         if(flag == 0)
            flag++;
         else{
            flag--;
            reverse(temp.begin(),temp.end());
         }
          res.push_back(temp);
       } 
       return res;
    }
};