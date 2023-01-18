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
    void f1(TreeNode* root, map<pair<TreeNode*,int> , int>& m){
        if(root==NULL){
            return;
        }

        m[{root,0}]=-1;
        m[{root,1}]=-1;

        f1(root->left,m);
        f1(root->right,m);

        return;
    }

    int f(TreeNode* root,int k,map<pair<TreeNode*,int> , int>& m){
        if(root==NULL){
            return 0;
        }

        if(m[{root,k}]!=-1){
            return m[{root,k}];
        }

        int w1=0 + f(root->left,0,m) + f(root->right,0,m);
        int w2=0;
        if(k==0){
            w2=root->val + f(root->left,1,m) + f(root->right,1,m);
        }

        return m[{root,k}]=max(w1,w2);
    }

    int rob(TreeNode* root) {
        map<pair<TreeNode*,int> , int>m;
        f1(root,m);
        return f(root,0,m);
    }
};
