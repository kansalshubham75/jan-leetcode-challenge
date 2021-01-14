class Solution {
public:
    int bSearch(int sum,int lo,int hi,vector<int>& arr){
        while(lo<hi){
            int mid=(lo+hi)>>1;
            if(arr[mid]<sum)lo=mid+1;
            else hi=mid;
        }
        return lo;
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        // cout<<n;
        vector<int> pre(n,0),suff(n,0);
        int curr=0,ans=n+1;
        for(int i=0;i<n;i++){
            curr=nums[i]+curr;
            pre[i]=curr;
            if(curr==x)ans=min(ans,i+1);
        }
        curr=0;
        for(int i=n-1;i>=0;i--){
            curr+=nums[i];
            suff[i]=curr;
            if(curr==x)ans=min(ans,n-i);
        }
        for(int i=n-1;i>0;i--){
            int idx=bSearch(x-suff[i],0,i-1,pre);
            if(pre[idx]==x-suff[i])ans=min(ans,idx+1+n-i);
        }
        if(ans<=n)return ans;
        return -1;
    }
};