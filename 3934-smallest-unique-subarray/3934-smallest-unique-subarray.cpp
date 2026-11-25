class Solution {
    bool solve(vector<int>&nums,int len){
        int n=nums.size();
        long long md1=1e9+7,bs1=131;
        long long md2=1e9+9,bs2=137;
        long long h1=0,h2=0,pw1=1,pw2=1;
        for(int i=0;i<len;i++){
            pw1=pw1*bs1 % md1;
            pw2=pw2 * bs2 %md2;
        }
        map<pair<long long,long long>,int> mpp;
        for(int i=0;i<n;i++){
            h1=(h1*bs1+nums[i])%md1;
            h2=(h2*bs2+nums[i])%md2;
            if(i>=len){
                h1=(h1-nums[i-len] *pw1 %md1 +md1)%md1;
                h2=(h2-nums[i-len] *pw2 % md2 + md2)%md2;
            }
            if(i>=len-1) mpp[{h1,h2}]++;
        }
        for(pair<pair<long long,long long>,int> p:mpp){
            if(p.second==1) return true;
        }
        return false;
    }
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int low=1,high=nums.size(),ans=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};