class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& arr, vector<vector<int>>& arr1) {
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        vector<int> temp(2);
        while(i<arr.size() && j<arr1.size()){
            int s1=arr[i][0];
            int e1=arr[i][1];
            int s2=arr1[j][0];
            int e2=arr1[j][1];

            if(s2<=e1 && s1<=e2 ){
                temp[0]=max(s1,s2);
                temp[1]=min(e1,e2);
                ans.push_back(temp);
            }

            if(e1>e2){
                j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};