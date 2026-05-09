class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n,vector<bool>((1<<n),false));
        for(int i=0;i<n;i++){
            int mask=(1<<i);
            q.push({i,mask});
            vis[i][mask]=true;
        }
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [node,mask]=q.front();
                q.pop();
                if(mask==(1<<n)-1) return cnt;

                for(int x:graph[node]){
                    int newmask=mask|(1<<x);

                    if(!vis[x][newmask]){
                        vis[x][newmask]=true;
                        q.push({x,newmask});
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
};