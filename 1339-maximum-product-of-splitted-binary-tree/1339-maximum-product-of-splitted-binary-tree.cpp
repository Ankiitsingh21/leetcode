class Solution {
    long long total = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long tot(TreeNode* root){
        if(!root) return 0;
        return root->val + tot(root->left) + tot(root->right);
    }

    long long solve(TreeNode * root){
        if(!root) return 0;

        long long left = solve(root->left);
        long long right = solve(root->right);

        long long ll = (total - left) * left;
        long long rr = (total - right) * right;

        ans = max(ans, max(ll, rr));  

        return root->val + left + right;
    }

public:
    int maxProduct(TreeNode* root) {
        total = tot(root);
        solve(root);
        return ans % MOD;  
    }
};