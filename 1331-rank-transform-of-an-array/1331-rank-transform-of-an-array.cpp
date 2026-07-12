class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,vector<int>> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]].push_back(i);
        }
        vector<int> ans(arr.size(),0);
        int j=1;
        for(auto &it:mpp){
           for(int i=0;i<it.second.size();i++){
               ans[it.second[i]]=j;
           }
           j++;
        }
        return ans;
    }
};