class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count = 0;
        int oddcount = 0, evencount = 1, prefixSum = 0;

        for(int num : arr) {
            prefixSum += num; // Keep prefix sum as normal

            if (prefixSum % 2 == 0) { 
                count = (count + oddcount) % MOD; // Only apply modulo when updating count
                evencount++;
            } else { 
                count = (count + evencount) % MOD; 
                oddcount++;
            }
        }
        
        return count; // Finally return count % MOD
    }
};
