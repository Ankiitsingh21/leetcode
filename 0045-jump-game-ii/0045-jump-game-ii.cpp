class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,r=0;
        int cnt=0;
        while(r<nums.size()-1){
            int far=0;
            for(int j=i;j<=r;j++){
                far=max(far,j+nums[j]);
            }
            i=r+1;
            r=far;
            cnt++;
        }
        return cnt;
    }
};