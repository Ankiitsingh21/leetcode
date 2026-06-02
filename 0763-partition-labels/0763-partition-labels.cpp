class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<int,int> mpp;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            mpp[c-'a']=i;
        }

        vector<int> ans;
        int end=0;
        int start=0;
        for(int i=0;i<s.size();i++){
            end=max(end,mpp[s[i]-'a']);
            if(end==i){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};