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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Just Hashing:

        map<int,int> inMap;

        for(int i=0; i<preorder.size(); i++){
            inMap[inorder[i]] =i;
        }

        return treeMaker( preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inMap );
        
    }

    TreeNode* treeMaker( vector<int> &preorder, vector<int> &inorder, int prestart, int preend, int instart, int inend, map<int, int> &inMap ){
                            
        if(prestart>preend || instart>inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inroot = inMap[preorder[prestart]];
        int leftnodes = inroot - instart;

        root->left = treeMaker( preorder, inorder, prestart+1, prestart+leftnodes, instart, inroot-1, inMap );

        root->right = treeMaker( preorder, inorder, prestart+leftnodes+1, preend, inroot+1, inend, inMap );

        return root;
        }
};