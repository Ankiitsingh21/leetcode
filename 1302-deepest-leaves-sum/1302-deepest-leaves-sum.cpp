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
    int maxDepth = 0;
    int sum = 0;
    
    void dfs(TreeNode* root, int level) {
        if(!root) return;
        
        if(level > maxDepth) {
            maxDepth = level;
            sum = root->val;       // ← new deepest level found, reset sum
        } else if(level == maxDepth) {
            sum += root->val;      // ← same deepest level, add to sum
        }
        
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};