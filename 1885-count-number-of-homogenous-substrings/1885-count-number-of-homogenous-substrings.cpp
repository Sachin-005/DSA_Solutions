class Solution {
public:
    int countHomogenous(string s) {
        long long count = 0;
        long long currLen = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currLen++;
            } else {
                count = (count + (currLen * (currLen + 1)) / 2) % MOD;
                currLen = 1;
            }
        }
        count = (count + (currLen * (currLen + 1)) / 2) % MOD;

        return count;
    }
};
