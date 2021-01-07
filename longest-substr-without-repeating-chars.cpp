class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        int i=0,j=0,n=st.length(),ans=0;
        unordered_set<char> s;
        while(j<n){
            while(s.count(st[j])){
                s.erase(st[i]);
                i++;
            }
            s.insert(st[j]);
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};