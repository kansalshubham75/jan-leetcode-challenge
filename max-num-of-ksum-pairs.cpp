class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0,n=nums.size();
        multiset<int> s;
        for(int i:nums){
            if(s.count(k-i)){
                s.erase(s.find(k-i));
                ans++;
            }else{
                s.insert(i);
            }
        }
        return ans;
    }
};