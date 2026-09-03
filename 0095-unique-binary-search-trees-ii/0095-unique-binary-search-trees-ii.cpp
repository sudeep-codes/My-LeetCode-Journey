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

    map<pair<int,int>, vector<TreeNode*>> memo;
    vector<TreeNode*> buildTrees(int start, int end){
        vector<TreeNode*> all_trees;
        if(start>end){
            all_trees.push_back(nullptr);
            return all_trees;
        }
        if(memo.find({start, end})!=memo.end()){
            return memo[{start,end}];
        }
        for(int i=start; i<=end; ++i){
            vector<TreeNode*> left_trees=buildTrees(start, i-1);
            vector<TreeNode*> right_trees=buildTrees(i+1, end);
            for(TreeNode* left:left_trees){
                for(TreeNode* right:right_trees){
                    TreeNode* current_root=new TreeNode(i);
                    current_root->left=left;
                    current_root->right=right;
                    all_trees.push_back(current_root);
                }       
            }
        }
        memo[{start,end}]=all_trees;
        return all_trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return{};
        return buildTrees(1,n);
    }
};