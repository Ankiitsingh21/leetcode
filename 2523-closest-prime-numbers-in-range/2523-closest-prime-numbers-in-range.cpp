class Solution {
    vector<int> solve(int n,int l,int r){
        if(n<=1) return {};
        vector<int> prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=2;i*i<=n;i++){
            if(prime[i]==1){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=0;
                }
            }
        }
        vector<int> ans;
        for(int i=l;i<=r;i++){
            if(prime[i]==1){
                // cout<<i<<" ";
                ans.push_back(i);
            }
        }
        return ans;
    }
public:
    vector<int> closestPrimes(int left, int right) {
      vector<int> arr=solve(right,left,right);
      vector<int> ans={-1,-1};
      int mini=INT_MAX;
      for(int i=1;i<arr.size();i++){
        int diff=arr[i]-arr[i-1];
        if(diff<mini){
            mini=diff;
            ans={arr[i-1],arr[i]};
        }
      } 
      return ans;
    }
};