class Solution {
    bool prime(int n){
        int cnt=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                cnt++;
                if(i!=(n/i)){
                    cnt++;
                }
            }
            if(cnt>2) return false;
        }
        return cnt==2;
    }
public:
    bool completePrime(int num) {
        string s=to_string(num);
        vector<int> prefix;
        vector<int> suffix;
        for(int i=1;i<=s.size();i++){
            prefix.push_back(stoi(s.substr(0,i)));
        }
        for(int i=0;i<s.size();i++){
            suffix.push_back(stoi(s.substr(i)));
        }
        for(int i=0;i<prefix.size();i++){
            if(!prime(prefix[i])) return false;
        }
        for(int i=0;i<suffix.size();i++){
            if(!prime(suffix[i])) return false;
        }
        return true;
    }
};