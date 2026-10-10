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

    // void preOrder(vector<int> &ans, TreeNode* root){

    //     if(root == nullptr) return;

    //     ans.push_back(root->val);
    //     preOrder(ans, root->left);
    //     preOrder(ans, root->right);

    //     return;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right!=nullptr) st.push(temp->right);
            if(temp->left!=nullptr) st.push(temp->left);
        }

        return ans;
    }
};