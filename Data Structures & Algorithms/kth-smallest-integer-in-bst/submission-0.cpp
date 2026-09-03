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
    int index=0;
    int result=-1;
    void infix(TreeNode*node,int k)
    {
        if(!node)return;
        infix(node->left,k);
        index++;
        if(index==k) {
            result=node->val;
            return;
        }
        infix(node->right,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        infix(root,k);
        return result;
    }
};
