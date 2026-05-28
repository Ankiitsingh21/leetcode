class Solution {
    void changee(map<int,int> &mpp, int l, int r, int change) {
        mpp[l] += change;
        mpp[r + 1] -= change;
    }

public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
     int n=INT_MIN;
     for(int i=0;i<flowers.size();i++){
        n=max(n,flowers[i][1]);
     }   
     map<int,int> mpp;
    //  vector<int> diff(n+1,0);
     for(int i=0;i<flowers.size();i++){
        int l=flowers[i][0],r=flowers[i][1];
        changee(mpp, l, r, 1);
     }
    //  for(int i=1;i<=n;i++){
    //     diff[i]+=diff[i-1];
    //  }
     int running = 0;
    for (auto &it : mpp) {
        running += it.second;
        it.second = running;
    }
     vector<int> ans(people.size());
     for(int i=0;i<people.size();i++){
        auto it = mpp.upper_bound(people[i]);
        if(it==mpp.begin()) ans[i]=0;
        else{
            --it;
            ans[i]=it->second;
        }
     }
        return ans;     
    }
};