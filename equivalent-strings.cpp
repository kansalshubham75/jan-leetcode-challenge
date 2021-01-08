class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        int n=w1.size(),m=w2.size();
        int x=w1[0].size(),y=w2[0].size();
        int i=0,j=0,k=0,l=0;
        while(i<n && j<m && k<x && l<y){
            // cout<<i<<" "<<k<<" "<<j<<" "<<l<<endl;
            if(w1[i][k]!=w2[j][l])return 0;
            i+=k==x-1;
            j+=l==y-1;
            if(i==n && j==m)return 1;
            k=k==x-1?0:k+1;
            l=l==y-1?0:l+1;
            x=w1[i].size();
            y=w2[j].size();
        }
        return 0;
    }
};