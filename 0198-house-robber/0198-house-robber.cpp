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
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nt=0+prev;
            int curri=max(take,nt);
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};