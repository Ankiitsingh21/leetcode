class Solution {
    vector<vector<int>> ans;
    void dfs(vector<int> & nums,vector<int> arr,int index){
        if(index==nums.size()){
            ans.push_back(arr);
            return ;
        }

        dfs(nums,arr,index+1);
        arr.push_back(nums[index]);
        // arr.pop_back();
        dfs(nums,arr,index+1);
        arr.pop_back();
        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        dfs(nums,arr,0);
        return ans;
    }
};