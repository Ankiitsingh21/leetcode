class Solution {
public:
    int ans = INT_MAX;
    void bfs(vector<vector<pair<int, int>>>& adj, vector<int>& vis){
        
        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &[next,wt]:adj[node]){
                ans=min(ans,wt);
                if(!vis[next]){
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
        return ;
    }

    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis) {
        vis[node] = 1;

        for (auto &[next, wt] : adj[node]) {
            ans = min(ans, wt);

            if (!vis[next]) {
                dfs(next, adj, vis);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> vis(n + 1, 0);

        bfs(adj, vis);

        return ans;
    }
};