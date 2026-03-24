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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode *,int>> q;
        q.push({root,0});
        int width=1;
        while(!q.empty()){
           int size=q.size();
           unsigned long long first,last;
           int minn=q.front().second;
           for(int i=0;i<size;i++){
            unsigned long long currentid=q.front().second-minn;
            TreeNode * temp=q.front().first;
            q.pop();
            if(i==0){
                first=currentid;
            }
            if(i==size-1){
                last=currentid;
            }
            if(temp->left){
                q.push({temp->left,currentid*2+1});
            }
             if(temp->right){
                q.push({temp->right,currentid*2+2});
            }
           }
           width = max((unsigned long long)width, last - first + 1);
        }
        return width;
    }
};