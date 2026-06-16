class Solution {
    const int MOD=1e9+7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int num:nums){
            pq.push(num);
        }
        while(k--){
            int x=pq.top();
            pq.pop();
            pq.push(x+1);
        }
        long long ans=1;
        while(!pq.empty()){
            if(pq.top()==0) return 0;
            ans=(ans*pq.top())%MOD;
            pq.pop();
        }
        return ans;
    }
};