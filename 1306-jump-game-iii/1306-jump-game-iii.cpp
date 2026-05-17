class Solution {
    bool solve(int index,vector<int>&arr,vector<bool> &vis){
        if(arr[index]==0) return true;


        bool back=false;
        //go backward
        if((index-arr[index]) >= 0 && !vis[index-arr[index]]){
            vis[index-arr[index]]=true;
           back=solve(index-arr[index],arr,vis);
           vis[index-arr[index]]=false;
        } 

        bool forward=false;
        //go forward
        if((index+arr[index])<=arr.size()-1 &&!vis[index+arr[index]]){
            vis[index+arr[index]]=true;
            forward=solve(index+arr[index],arr,vis);
            vis[index+arr[index]]=false;
        } 


        if(back || forward) return true;


        return false;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0) return true;
        vector<bool> vis(arr.size(),false);
        return solve(start,arr,vis);
    }
};