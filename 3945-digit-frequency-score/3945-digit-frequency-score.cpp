class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int> mpp;
        while(n>0){
            int d=n%10;
            mpp[d]++;
            n/=10;
        }
        int ans=0;
        for(auto it:mpp){
            ans+=it.first*it.second;
        }
        return ans;
    }
};