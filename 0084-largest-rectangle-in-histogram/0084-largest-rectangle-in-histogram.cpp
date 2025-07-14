class Solution {
private:
    void nextSmall(vector<int>& heights, vector<int>& nse) {
        stack<int> st;
        int n = heights.size();
       // nse.resize(n, n);  // Initialize nse with n to indicate no smaller element

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack while the stack is not empty and the height of the element at index on the stack is greater than or equal to heights[i]
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            // If stack is not empty, the next smaller element index is the top of the stack
            if (!st.empty()) {
                nse[i] = st.top();
            }

            // Push current index to stack
            st.push(i);
        }
    }

    void previousSmall(vector<int>& heights, vector<int>& pse) {
        stack<int> st;
        int n = heights.size();
     //  pse.resize(n, -1);  // Initialize pse with -1 to indicate no smaller element

        for (int i = 0; i < n; i++) {
            // Pop elements from stack while the stack is not empty and the height of the element at index on the stack is greater than or equal to heights[i]
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

            // If stack is not empty, the previous smaller element index is the top of the stack
            if (!st.empty()) {
                pse[i] = st.top();
            }

            // Push current index to stack
           st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> nse(n,n);  // Next smaller elements indices
        vector<int> pse(n,-1);  // Previous smaller elements indices

        // Find next smaller elements
        nextSmall(heights, nse);

        // Find previous smaller elements
        previousSmall(heights, pse);

        int maxArea = 0;

        // Calculate the area for each bar in the histogram
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};