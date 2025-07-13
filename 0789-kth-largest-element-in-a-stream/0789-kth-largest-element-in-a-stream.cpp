class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < k || minHeap.top() < val)  {// to insert the largest element and maintains k size order
            minHeap.push(val);
            if (minHeap.size() > k) { // if we add always returns the kth largest element once we defined
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};