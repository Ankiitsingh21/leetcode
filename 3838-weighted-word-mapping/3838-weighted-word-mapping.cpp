class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(int i=0;i<words.size();i++){
            int sum=0;
            for(char c:words[i]){
                int cha=c-'a';
                // cout<<cha<<" ";
                sum+=weights[cha];
            }
            int ch=26-(sum%26)-1;
            // cout<<endl;
            // cout<<(sum%26+'a')<<" ";
            s.push_back(ch+'a');
        }
        return s;
    }
};