class Solution {
     int count(vector<vector<int>> &arr,int n){
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });


        int cnt=0;
        int end=0;
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i][0]>end) return -1;
            if(arr[i][0]>maxi){
                cnt++;
                maxi=max(maxi,end);
            }

            end=max(end,arr[i][1]);
            if(end>=n) break;
        }

        if(end<n) return -1;
        return cnt+1;
     }
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> arr(ranges.size(),vector<int>(2,0));
        for(int i=0;i<ranges.size();i++){
            arr[i][0]=i-ranges[i];
            if(arr[i][0]<0){
                arr[i][0]=0;
            }
            arr[i][1]=i+ranges[i];
        }

        return count(arr,n);
    }
};