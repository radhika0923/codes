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
    int height(TreeNode* root,bool &ans){
        if(root==NULL)
            return 0;
        int leftHeight=1+height(root->left,ans);
        int rightHeight=1+height(root->right,ans);
        if(abs(leftHeight-rightHeight)>1){
            ans=false;
            return 0;
        }
        return max(leftHeight,rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
          bool ans=true;
        height(root,ans);
        return ans;
    }
};