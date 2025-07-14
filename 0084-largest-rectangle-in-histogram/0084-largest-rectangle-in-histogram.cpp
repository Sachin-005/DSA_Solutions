class Solution {
private:
    void nextSmall(vector<int>& heights, vector<int>& nse) {
        stack<int> st;
        int n = heights.size();
        nse.resize(n, n);  

        for (int i = n - 1; i >= 0; i--) {
           
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }

           
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }
    }

    void previousSmall(vector<int>& heights, vector<int>& pse) {
        stack<int> st;
        int n = heights.size();
        pse.resize(n, -1);  

        for (int i = 0; i < n; i++) {
           
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
           st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> nse; 
        vector<int> pse;  
        nextSmall(heights, nse);
        previousSmall(heights, pse);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};