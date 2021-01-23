class Solution {
public:
    void countSort(vector<vector<int>>& mat,int r,int c){
        int m=mat.size(),n=mat[0].size(),i=r,j=c;
        int arr[101]={0};
        while(i<m && j<n){
            arr[mat[i][j]]++;
            i++,j++;
        }
        i=r,j=c;
        for(int k=1;k<=100;k++){
            while(arr[k]){
                arr[k]--;
                mat[i][j]=k;
                i++,j++;
            }
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<n;i++)countSort(mat,0,i);
        for(int i=1;i<m;i++)countSort(mat,i,0);
        return mat;
    }
};