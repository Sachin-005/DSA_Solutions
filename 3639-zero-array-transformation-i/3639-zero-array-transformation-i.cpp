class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size()+1,0);
        vector<int> maxOp;
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right= queries[i][1];
            diff[left]++;
            diff[right+1]--;
        }
        int currOp=0;
        for(int i=0;i<nums.size();i++){
            currOp = currOp+diff[i];
            maxOp.push_back(currOp);
        }
        for(int i=0;i<nums.size();i++){
            if(maxOp[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};