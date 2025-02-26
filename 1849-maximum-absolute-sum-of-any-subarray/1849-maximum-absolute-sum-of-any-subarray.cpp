class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
       int n = nums.size();
       int maxi =0;
       int mini =0;
       int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mini = min(mini,sum);
            maxi = max(maxi,sum);
        }
       return maxi-mini;
    }
};