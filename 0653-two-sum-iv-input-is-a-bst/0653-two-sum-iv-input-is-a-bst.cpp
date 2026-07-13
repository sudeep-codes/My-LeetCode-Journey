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
    vector<int> inorder;
    void dfs(TreeNode* root) {
        if(root==nullptr) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int left=0;
        int right=inorder.size()-1;
        while(left<right){
            int sum=inorder[left]+inorder[right];
            if(sum==k) return true;
            if(sum<k) left++;
            else right--;
        }
        return false;
    }
};