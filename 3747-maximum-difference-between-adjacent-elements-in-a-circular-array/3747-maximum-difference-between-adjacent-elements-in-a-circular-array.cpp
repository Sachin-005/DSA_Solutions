class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int size = nums.size();
        int maxi = INT_MIN;
        int diff;
        for(int i=0;i<size-1;i++){
            diff = abs(nums[i]-nums[i+1]);
            maxi = max(diff,maxi);
        }
        maxi = max(maxi,abs(nums[0]-nums[size-1]));
        return maxi;
    }
};