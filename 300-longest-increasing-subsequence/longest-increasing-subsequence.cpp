class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int n:nums){
            auto it=lower_bound(dp.begin(),dp.end(),n);
            if(it==dp.end()) dp.push_back(n);
            else *it=n;
        }
        return dp.size();
    }
};