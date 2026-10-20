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

    void assignCords(TreeNode* root, int vertical, int level,
                    map<int, map<int, multiset<int>>> &cordMap){
        
        if(!root) return;
        
        assignCords(root->left, vertical-1, level+1, cordMap);
        cordMap[vertical][level].insert(root->val);
        assignCords(root->right, vertical+1, level+1, cordMap);

        return;    
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> cordMap;
        assignCords(root, 0, 0, cordMap);

        vector<vector<int>> ans;

        for(auto& p :  cordMap){
            vector<int> focusVertical;
            for(auto& q : p.second){
                for(int val : q.second){
                    focusVertical.push_back(val);
                }
            }
            ans.push_back(focusVertical);
        }

        return ans;
    }
};