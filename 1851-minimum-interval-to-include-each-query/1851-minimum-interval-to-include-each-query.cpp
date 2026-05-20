class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<int> arr=queries;
        sort(arr.begin(),arr.end());
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            int i=0;
            unordered_map<int,int> mpp;
        for(int j=0;j<arr.size();j++){
            while(i<intervals.size() && intervals[i][0]<=arr[j] ){
                int l=intervals[i][0];
                int r=intervals[i][1];
                pq.push({(r-l+1),r});
                i++;
            }

            while(!pq.empty() && pq.top().second<arr[j]){
                pq.pop();
            }
            if(!pq.empty()){
                mpp[arr[j]]=pq.top().first;
            }else{
                mpp[arr[j]]=-1;
            }
        }
        for(int &q:queries){
            ans.push_back(mpp[q]);
        }
        return ans;
    }
};