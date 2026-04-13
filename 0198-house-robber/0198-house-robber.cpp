class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // cout<<n<<endl;
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        // if(n==2){
        //     return max(nums[0],nums[1]);
        // }
        vector<int> dp(n,0);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=dp[i-2];
            }
            int nt=0+dp[i-1];
            cout<<take<<" "<<nt<<endl;
            dp[i]=max(take,nt);
        }
        return dp[n-1];
    }
};