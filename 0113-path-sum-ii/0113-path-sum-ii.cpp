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

    void findPaths(TreeNode* root, int targetSum, vector<int>& currentPath, vector<vector<int>>& allPaths){
        if(root==nullptr) return;
        currentPath.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr && targetSum==root->val) allPaths.push_back(currentPath);
        else{
            findPaths(root->left,targetSum-root->val, currentPath,allPaths);
            findPaths(root->right, targetSum-root->val, currentPath, allPaths);
        }
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> allPaths;
        vector<int> currentPath;
        findPaths(root, targetSum, currentPath, allPaths);
        return allPaths;

    }
};