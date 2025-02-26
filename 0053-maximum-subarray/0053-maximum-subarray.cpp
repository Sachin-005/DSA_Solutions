
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int maxSum = INT_MIN; // Correct initialization
        int currMax = 0;

        for (int num : arr) {
            currMax = max(num, currMax + num);  // Kadane’s Algorithm step
            maxSum = max(maxSum, currMax);      // Track max encountered so far
        }

        return maxSum;
    }
};