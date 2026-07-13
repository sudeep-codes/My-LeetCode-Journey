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
    struct NodeValue{
        int minNode;
        int maxNode;
        int sum;
        bool isBST;
        NodeValue(int mn, int mx, int s, bool bst){
            minNode=mn;
            maxNode=mx;
            sum=s;
            isBST=bst;
        }
    };
    int ans=0;
    NodeValue dfs(TreeNode* root){
        if(root==nullptr) return NodeValue(INT_MAX, INT_MIN, 0, true);
        NodeValue left=dfs(root->left);
        NodeValue right=dfs(root->right);
        if(left.isBST && right.isBST &&left.maxNode<root->val&&root->val<right.minNode){
            int currSum=left.sum+right.sum+root->val;
            ans=max(ans, currSum);
            return NodeValue(
                min(left.minNode, root->val), max(right.maxNode, root->val), currSum, true
            );
        }
        return NodeValue(INT_MIN, INT_MAX, 0, false);
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};