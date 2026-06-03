class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int cnt=0;
        int maxi=INT_MAX;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int num=matrix[i][j];
                sum+=abs(num);
                if(num<0){
                    cnt++;
                }
                    maxi=min(maxi,abs(num));
            }
        }
        // cout<<cnt<<" "<<2*maxi<<" "<<sum<<" "<<sum-(2*maxi)<<" ";
        if(cnt%2==1){
            sum-=(2*maxi);
        }
        return sum;
    }
};