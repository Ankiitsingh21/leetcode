class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }

        const long long INF=LLONG_MAX;
        vector<vector<long long>> dist(n,vector<long long>(k+1,INF));
        dist[0][1]=0;

        priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<>> pq;
        pq.push({0,0,1});
        while(!pq.empty()){
            auto [d,node,run]=pq.top();
            pq.pop();

            if(d>dist[node][run]) continue;

            for(auto &[next,w]:adj[node]){
                int newRun;
                if(labels[next]==labels[node]){
                    newRun=run+1;
                }else{
                    newRun=1;
                }

                if(newRun>k) continue;

                long long newDist=d+w;
                if(newDist<dist[next][newRun]){
                    dist[next][newRun]=newDist;
                    pq.push({newDist,next,newRun});
                }
            }
        }
        long long best=INF;
        for(int run=1;run<=k;run++){
            best=min(best,dist[n-1][run]);
        }
        return best==INF?-1:best;
    }
};