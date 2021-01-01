class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> m;
        int n=arr.size(),x=pieces.size();
        for(int i=0;i<x;i++){
            int s=pieces[i].size();
            for(int j=0;j<s;j++)m[pieces[i][j]]=i;
        }
        int i=0;
        while(i<n){
            if(m.find(arr[i])==m.end())return 0;
            int j=m[arr[i]];
            for(int k=0;k<pieces[j].size();k++){
                if(arr[i]!=pieces[j][k])return 0;
                i++;
            }
        }
        return 1;
    }
};