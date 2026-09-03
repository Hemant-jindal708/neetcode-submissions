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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        vector<TreeNode*>q={root};
        while(!q.empty())
        {
            vector<TreeNode*> currenth;
            vector<int>temp;
            for(TreeNode* t:q)
            {
                if(t->left){
                    currenth.push_back(t->left);
                }
                if(t->right){
                    currenth.push_back(t->right);
                }
                temp.push_back(t->val);
            }
            ans.push_back(temp);
            swap(q,currenth);
        }
        return ans;
    }
};
