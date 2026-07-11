class Solution {
    pair<int,int> check(int node,vector<vector<int>> &adj,vector<bool> &vis){
        vis[node]=true;
        queue<int> q;
        q.push(node);
        int vertices=0,edges=0;
        while(!q.empty()){
            int top=q.front();
            q.pop();
            vertices++;
            edges+=adj[top].size();
            for(int &v:adj[top]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        edges/=2;
        return {vertices,edges};
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                auto [ver,edge]=check(i,adj,vis);
                int calc=(ver*(ver-1))/2;
                if(edge==calc) cnt++;
                // cnt++;
            }
        }
        return cnt;
    }
};