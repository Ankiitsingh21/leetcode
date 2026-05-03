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
    int ans=0;
    pair<int,int> solve(TreeNode * root){
        if(!root) return {0,0};

        auto [leftS,leftC] =solve(root->left);
        auto [rightS,rightC] =solve(root->right);

        int size=1+leftS+rightS;
        int coins=root->val+leftC+rightC;
        ans+=abs(size-coins);

        return {size,coins};
    }
public:
    int distributeCoins(TreeNode* root) {
        solve(root);
        return ans;
    }
};