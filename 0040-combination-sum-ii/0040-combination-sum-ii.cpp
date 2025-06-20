class Solution {
public:
    void solve(int ind, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (ind == candidates.size() || target < 0) return;
        ds.push_back(candidates[ind]);
        solve(ind + 1, target - candidates[ind], candidates, ds, ans);
        ds.pop_back();

        int next = ind + 1;
        while (next < candidates.size() && candidates[next] == candidates[ind]) {
            next++;
        }
        solve(next, target, candidates, ds, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};
 + 1, target, candidates, ds, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};
