class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res += (nums[i][i] == '0') ? '1' : '0'; // Flip diagonal elements
        }
        return res;
    }
};
