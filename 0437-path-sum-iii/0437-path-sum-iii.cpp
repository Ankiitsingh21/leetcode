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
    int cnt=0;
    void traversal(TreeNode * temp,long long currSum,int target,map<long long,int> &mpp){
        if(!temp) return ;
        currSum+=temp->val;

        cnt += mpp[currSum-target];  

        mpp[currSum]++;

        traversal(temp->left,currSum,target,mpp);
        traversal(temp->right,currSum,target,mpp);
        mpp[currSum]--;
        if(mpp[currSum]==0) mpp.erase(currSum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        map<long long,int> mpp;
        mpp[0]++;
        traversal(root,0,targetSum,mpp);
        return cnt;
    }
};