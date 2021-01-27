class Solution {
public:
    #define ll long long
    #define M 1000000007
    ll mul(ll a,ll b){
        return ((a%M)*(b%M))%M;
    }
    ll sum(ll a,ll b){
        return ((a%M)+(b%M))%M;
    }
    int concatenatedBinary(int n) {
        int bit=0;
        ll ans=0,cp=1;
        for(int i=n;i>=1;i--){
            int curr=1;
            while(curr<=i){
                if(curr&i)ans=sum(ans,cp);
                cp=mul(cp,2);
                curr=curr<<1;
                bit++;
            }
        }
        return ans;
    }
};