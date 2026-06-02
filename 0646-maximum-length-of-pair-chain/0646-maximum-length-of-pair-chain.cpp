class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        int end=pairs[0][1];
        int cnt=1;
        for(int i=0;i<pairs.size();i++){
            // cout<<pairs[i][0]<<" "<<pairs[i][1]<<" ";
            if(pairs[i][0]>end){
                cnt++;
                end=max(end,pairs[i][1]);
            }
        }
        return cnt;
    }
};