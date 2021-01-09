class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(string& st:wordList)s.insert(st);
        
        if(s.count(endWord)==0)return 0;
        queue<string> q;
        q.push(beginWord);
        int l=1;
        while(!q.empty()){
            l++;
            int sz=q.size();
            while(sz--){
                auto st=q.front();
                q.pop();
                int x=st.size();
                for(int i=0;i<x;i++){
                    char orig=st[i];
                    for(int c=0;c<26;c++){
                        st[i]=(char)('a'+c);
                        if(s.count(st)){
                            if(endWord==st)return l;
                            q.push(st);
                            s.erase(st);
                        }
                    }
                    st[i]=orig;
                }
            }
        }
        return 0;
    }
};