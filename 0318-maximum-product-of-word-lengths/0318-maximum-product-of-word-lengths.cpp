class Solution {
    bool check(string s, string b) {
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (s[i] == b[j])
                    return false;
            }
        }
        return true;
    }

public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size(),0);
        for(int i=0;i<words.size();i++){
            for(char ch:words[i]){
                mask[i]|=(1<<(ch-'a'));
            }
        }
        int maxi = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            string s=words[i];
            for (int j = i + 1; j < words.size(); j++) {
                string b=words[j];
                if ((mask[i]&mask[j])==0) {
                    maxi = max(maxi, (int)(s.size() * b.size()));
                }
            }
        }
        return maxi;
    }
};