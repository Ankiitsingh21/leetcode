class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> mpp(26);
        for(int i=0;i<s.size();i++){
            mpp[s[i]-'a']=i;
        }

        int start=0 ,end=0;
        // cout<<maxi<<" ";
        for(int i=0;i<s.size();i++){
            end=max(end,mpp[s[i]-'a']);
            if(i==end){
                // cout<<i<<" ";
                ans.push_back(end-start+1);
                start=i+1;
                // maxi=mpp[s[i]-'a'];
                // cout<<maxi<<" ";
            }

        }

        return ans;
    }
};