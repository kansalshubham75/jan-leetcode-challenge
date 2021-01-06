class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int prev=0,n=arr.size(),missing=0;
        for(int i=0;i<n;i++){
            int extra=arr[i]-prev-1;
            if(extra+missing>=k){
                return prev+k-missing;
            }
            prev=arr[i];
            missing+=extra;
        }
        return prev+k-missing;
    }
};