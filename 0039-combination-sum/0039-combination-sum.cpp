class Solution {
public:
    void function(int ind, int target, vector<vector<int>>& ans, vector<int>& arr, vector<int>& candidates) {
         if (ind == candidates.size()){ 

        if (target == 0) 
        {
            ans.push_back(arr);
        }
            return;
        
         }
       
        
        if (candidates[ind] <= target) {
            arr.push_back(candidates[ind]);
            function(ind, target - candidates[ind], ans, arr, candidates); 
              arr.pop_back();
        }
      

        
        function(ind + 1, target, ans, arr, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        function(0, target, ans, arr, candidates);
        return ans;
    }
};
