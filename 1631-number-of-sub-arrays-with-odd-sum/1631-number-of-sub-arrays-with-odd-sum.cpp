class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count = 0;
        int oddcount = 0, evencount = 1, prefixSum = 0;

        for(int num : arr) {
            prefixSum += num; // Keep prefix sum as normal

            if (prefixSum % 2 == 0) { 
                count = (count + oddcount); // Only apply modulo when updating count
                evencount++;
            } else { 
                count = (count + evencount) ; 
                oddcount++;
            }
            count=count%MOD;
        }
        
        return count%MOD; // Finally return count % MOD
    }
};
