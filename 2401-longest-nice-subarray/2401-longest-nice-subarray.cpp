class Solution {
    bool check(int l,int r, vector<int>&nums){
        for(int i=l;i<r;i++){
            for(int j=i+1;j<=r;j++){
                if((nums[i]&nums[j])!=0) return false;
            }
        }
        return true;
    }
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0;
        int ans=1;
        while(r<nums.size()){
            while(!check(l,r,nums)){
                l++;
            }
            ans=max(ans,r-l+1);
                r++;
        }
        return ans;
    }
};