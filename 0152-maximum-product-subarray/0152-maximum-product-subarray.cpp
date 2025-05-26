class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int result = nums[0];
    for(int i=0;i<nums.size();i++) {
        int p = nums[i];
         result = max(result,p);
        for(int j=i+1;j<nums.size();j++) {
            p *= nums[j];
           result = max(result,p);
        }
    }
    return result;
    }
};