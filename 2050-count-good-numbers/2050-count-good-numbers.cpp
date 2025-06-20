class Solution {
public:
    const int MOD = 1e9 + 7;

    long long fun(long long base, long long pow) {
        long long ans = 1;
        base %= MOD;
        while (pow) {
            if (pow % 2 == 1) {
                ans = (ans * base) % MOD;
                pow--;
            } else {
                base = (base * base) % MOD;
                pow /= 2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long part1 = fun(5, even);
        long long part2 = fun(4, odd);

        return (part1 * part2) % MOD;
    }
};
