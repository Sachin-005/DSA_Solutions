class Solution {
public:
    void solve(int index, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        solve(index + 1, nums, ds, ans);
        ds.pop_back();
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index]) {
            next++;
        }
        solve(next, nums, ds, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, nums, ds, ans);
        return ans;
    }
};
