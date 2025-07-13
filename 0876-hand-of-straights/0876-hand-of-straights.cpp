class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        // Min-heap to always get the smallest card
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& [num, _] : freq) {
            minHeap.push(num);
        }

        while (!minHeap.empty()) {
            int first = minHeap.top();

            // Try to build a group starting from 'first'
            for (int i = 0; i < groupSize; ++i) {
                int card = first + i;
                if (freq[card] == 0) return false;

                freq[card]--;
                if (freq[card] == 0) {
                    // If this card was in heap, remove it
                    if (card == minHeap.top()) {
                        minHeap.pop();
                    }
                }
            }
        }

        return true;
    }
};
