class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int f[26]={0},f1[26]={0};
        for(char c:word1)f[c-'a']++;
        for(char c:word2)f1[c-'a']++;
        int ff[100001]={0};
        for(int i=0;i<26;i++){
            if(f[i]){
                if(!f1[i])return 0;
                ff[f[i]]++;
            }
        }
        for(int i=0;i<26;i++){
            if(f1[i] && ff[f1[i]])ff[f1[i]]--;
            else if(f1[i])   return 0;
        }
        return 1;
    }
};