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
bool check(TreeNode * rootleft,TreeNode * rootright){
   if (rootleft == nullptr && rootright == nullptr) return true;
    if (rootleft == nullptr || rootright == nullptr) return false;

    // Check current node values and recurse on children
    if (rootleft->val == rootright->val) {
        return check(rootleft->left, rootright->right) && check(rootleft->right, rootright->left);
    } else {
        return false;
    }
}
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true; 
        return check(root->left, root->right);  
    }
};