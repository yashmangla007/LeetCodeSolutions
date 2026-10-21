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

    /*
    //Reccursive:
    void inorder(TreeNode* &root, vector<int> &ans){
        if(root == nullptr) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
        return;
    }*/

    //Iterative: 
    // vector<int> inorderTraversal(TreeNode* root) {
        
    //     if(root==nullptr) return {};

    //     vector<int> ans;
    //     // inorder(root, ans);
    //     stack<TreeNode*> st;
    //     st.push(root);

    //     while(!st.empty()){
    //         TreeNode* temp = st.top();
    //         st.pop();
    //         if(temp->right!=nullptr) st.push(temp->right);
    //         if(temp->left!=nullptr) st.push(temp->left);
    //         if(temp->lefans.push_back(temp->val);
    //     }

    //     return ans;
    // }

    //Constant Space (Morris Traversal):
    vector<int> inorderTraversal(TreeNode* &root){
        if(root==nullptr) return {};
        vector<int> ans;
        TreeNode* curr = root;
        
        while(curr){
            
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }

            else{
                TreeNode* rightmost=curr->left;
                //moving to rightmost guy in subtree
                while(rightmost->right && rightmost->right!=curr){
                    rightmost = rightmost->right;
                }

                if(rightmost->right == nullptr){
                    rightmost->right = curr;
                    curr = curr->left;
                }
                else{
                    rightmost->right = nullptr;
                    ans.push_back(curr->val);
                    curr= curr->right;
                }
            }

        }

        return ans;
    }
};