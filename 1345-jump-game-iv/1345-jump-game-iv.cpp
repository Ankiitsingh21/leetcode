class Solution {
    int solve(map<int,vector<int>> &mpp,int n,vector<int>& arr,vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0]=true;
        while(!q.empty()){
            auto [index,cnt]=q.front();
            q.pop();
            if(index==n-1)return cnt;
            int node=arr[index];
            // for(int i=0;i<mpp[node].size();i++){
            //     if(!vis[mpp[node][i]]){
            //         vis[mpp[node][i]]=true;
            //         q.push({mpp[node][i],cnt+1});
            //     }
            // }
            for(int &x:mpp[node]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push({x,cnt+1});
                }
            }
            mpp[node].clear();
            if(index+1<n && !vis[index+1] ){
                vis[index+1]=true;
                q.push({index+1,cnt+1});
            }
            if(index-1>0 && !vis[index-1]){
                vis[index-1]=true;
                q.push({index-1,cnt+1});
            }
        }
        return 0;
    }
public:
    int minJumps(vector<int>& arr) {
        map<int,vector<int>> mpp;
        vector<bool> vis(arr.size(),false);
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
        }
        return solve(mpp,arr.size(),arr,vis);
    }
};