class Solution {
public:
    int call(vector<int>&arr, int ind, vector<int>& dp){
        if(ind == 0) return arr[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
       int pick = arr[ind]+call(arr,ind-2,dp);
       int notpick = 0+call(arr,ind-1,dp);
       return dp[ind]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        int size = nums.size()-1;
       return call(nums,size,dp);
    }
};