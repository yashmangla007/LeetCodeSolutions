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

    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;

        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i++]);
        }

        while (j <= high) {
            temp.push_back(arr[j++]);
        }

        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //Just Hashing:

        map<int,int> inMap;

        for(int i=0; i<preorder.size(); i++){
            inMap[inorder[i]] =i;
        }

        return treeMaker( preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, inMap );
        
    }

    TreeNode* treeMaker( vector<int> &preorder, vector<int> &inorder, int prestart, 
                        int preend, int instart, int inend, map<int, int> &inMap ){
                            
        if(prestart>preend || instart>inend) return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inroot = inMap[preorder[prestart]];
        int leftnodes = inroot - instart;

        root->left = treeMaker( preorder, inorder, prestart+1, 
                                prestart+leftnodes, instart, inroot-1, inMap );

        root->right = treeMaker( preorder, inorder, prestart+leftnodes+1, 
                                    preend, inroot+1, inend, inMap );

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        mergeSort(inorder, 0, inorder.size()-1);

        return buildTree(preorder, inorder);
    }
};