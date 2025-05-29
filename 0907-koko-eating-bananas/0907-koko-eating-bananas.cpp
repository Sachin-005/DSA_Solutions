class Solution {
public:
    long calculateAns(vector<int>& piles, int hours) {
        long totalhours = 0;
        for (int i = 0; i < piles.size(); i++) {
            totalhours += ceil((double)piles[i] / (double)hours);
        }
        return totalhours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi, ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;
            long val = calculateAns(piles, mid);
            cout << "val " << val << " mid " << mid << endl;

            if (val <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << low << " low" << endl;
        return ans;
    }
};
