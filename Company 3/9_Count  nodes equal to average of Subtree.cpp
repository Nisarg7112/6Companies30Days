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
    int f(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }

        int left=f(root->left,ans);
        int right=f(root->right,ans);

        int sum=root->val;
        if(root->left){
            sum+=root->left->val;
        }
        if(root->right){
            sum+=root->right->val;
        }

        int n=1+left+right;
        if(root->val == sum/n){
            ans=ans+1;
        }

        root->val=sum;
        return 1+left+right;
    }

    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        f(root,ans);

        return ans;
    }   
};
