class Solution {
public:
    string removeKdigits(string num, int k) {
        string st; 

        for (char digit : num) {
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();  // remove larger digit
                k--;
            }
            st.push_back(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

      
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        string result = st.substr(i);

        return result.empty() ? "0" : result;
    }
};
