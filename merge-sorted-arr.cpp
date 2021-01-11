class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(k>=0){
            // cout<<k;
            if(i<0 || (j>=0 && nums1[i]<nums2[j])){
                // cout<<j;
                nums1[k]=nums2[j];
                j--;
            }else{
                // cout<<i;
                nums1[k]=nums1[i];
                i--;
            }
            k--;
            // cout<<endl;
        }
    }
};