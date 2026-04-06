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
    vector<vector<int>> ans;
    void traversal(TreeNode * temp,vector<int> &arr,int currSum,int target){
        if(!temp) return ;

        currSum+=temp->val;
        arr.push_back(temp->val);
        if(!temp->left && !temp->right ){
            if(currSum==target){
                ans.push_back(arr);
            }
        }

        // if(!temp->left && !temp->right && currSum!=target) ans.pop_back();
        traversal(temp->left,arr,currSum,target);
        traversal(temp->right,arr,currSum,target);
        arr.pop_back();
        return ;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> arr;
        traversal(root,arr,0,targetSum);
        return ans;
    }
};