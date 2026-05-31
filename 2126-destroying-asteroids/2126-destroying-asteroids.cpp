class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=mass;
        for(int &x:nums){
            if(sum<x) return false;
            sum+=x;
        }
        return true;
    }
};