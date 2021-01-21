class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && st.back()>nums[i] && st.size()+n-i>k){
                st.pop_back();
            }
            st.push_back(nums[i]);
        }
        while(st.size()>k)st.pop_back();
        return st;
    }
};