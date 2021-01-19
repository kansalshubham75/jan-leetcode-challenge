class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),max_=1,st=0,e=0;
        if(!n)return 0;
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int gap=0;gap<n;gap++){
            for(int l=0;l+gap<n;l++){
                int r=l+gap;
                if(gap==0){
                    dp[l][r]=1;
                }else if(gap==1){
                    dp[l][r]=s[l]==s[r];
                }else{
                    dp[l][r]=dp[l+1][r-1] && s[l]==s[r];
                }
                if(dp[l][r] && max_<r-l+1){
                    max_=r-l+1;
                    st=l,e=r;
                }
            }
        }
        return s.substr(st,e-st+1);
    }
};