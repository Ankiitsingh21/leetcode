class Solution {
    long long Gcd(int a,int b){
        while(b!=0){
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long> prefixGcd;
        int maxi=INT_MIN;
        for(int num:nums){
            maxi=max(maxi,num);
            prefixGcd.push_back(Gcd(num,maxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i=0,j=prefixGcd.size()-1;
        long long sum=0;
        while(i<j){
            sum+=Gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};