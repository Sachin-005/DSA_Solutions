class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long total = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int mini = nums[i], maxi = nums[i];
            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
                maxi = max(maxi, nums[j]);
                total += (maxi - mini);
            }
        }

        return total;
    }
};
