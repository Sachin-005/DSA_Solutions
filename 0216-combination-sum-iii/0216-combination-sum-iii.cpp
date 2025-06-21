class Solution {
public:
    void solve(int num, int k, int n, vector<int>& ds, vector<vector<int>>& ans){
        if(n==0 && ds.size()==k){
            ans.push_back(ds);
            return;
        }
        if(n<0 || num>9) return;
        ds.push_back(num);
        solve(num+1,k,n-num,ds,ans);
        ds.pop_back();
        solve(num+1,k,n,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
};