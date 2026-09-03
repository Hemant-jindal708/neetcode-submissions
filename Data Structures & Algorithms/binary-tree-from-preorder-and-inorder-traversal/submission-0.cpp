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
    unordered_map<int,int> indexMap;
    TreeNode* construct(vector<int> pre,int left,int right)
    {
        if(left>right) return nullptr;
        int rootVal=pre[index++];
        TreeNode*temp = new TreeNode(rootVal);
        int mid=indexMap[rootVal];

        temp->left=construct(pre,left,mid-1);
        temp->right=construct(pre,mid+1,right);
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++)
        {
            indexMap[inorder[i]]=i;
        }
        return construct(preorder,0,preorder.size()-1);
    }
};
