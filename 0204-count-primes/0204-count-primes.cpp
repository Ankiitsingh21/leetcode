class Solution {
    bool prime(int n){
        if(n<=1) return false;
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
        return true;
    }
    bool primee(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        // int cnt=0;
        // for(int i=2;i<n;i++){
        //     if(primee(i)){
        //         cnt++;
        //         // cout<<i<<" "<<cnt<<" ";
        //     } 
        // }
        // return cnt;
        vector<int> pr(n+1,1);
        pr[0]=0;
        pr[1]=0;
        for(int i=2;i<n;i++){
            if(pr[i]==1){
                // pr[i]=0;
                for(int j=2*i;j<=n;j+=i){
                    pr[j]=0;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            if(pr[i]==1){
                cnt++;
            }
        }
        return cnt;

    }
};