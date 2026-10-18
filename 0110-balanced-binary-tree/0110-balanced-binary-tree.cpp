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


    //Non-Optimal Solution:
    // int height(TreeNode* root){
    //     if(root==nullptr) return 0;
    //     return 1 + max(height(root->left), height(root->right));
    // }
    // bool isBalanced(TreeNode* root) {
    //     if(root==nullptr) return true;

    //     int dif = height(root->left) - height(root->right);
    //     return ( isBalanced(root->left) && isBalanced(root->right) && (dif>=-1 && dif<=1) );
    // }

    //Optimal Solution:
    int check(TreeNode* root){
        if(root==nullptr) return 0;
        int lh = check(root->left);
        int rh = check(root->right);
        if(lh==-1 || rh==-1) return -1;
        if(lh-rh<-1 || lh-rh>1) return -1;
        return max(lh,rh) +1;
    }

    bool isBalanced(TreeNode* root) {
        if(check(root)>-1) return true;
        else return false;
    }

};