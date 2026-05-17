class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> mpp;
        mpp[0]=1;
        int cnt=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                cnt++;
            }
            int calc=cnt-k;
            if(mpp.find(calc)!=mpp.end()){
                ans+=mpp[calc];
            }
            mpp[cnt]++;
        }
        return ans;
    }
};