class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=-1;
        int premin = nums[0];
        for(int i=1;i<nums.size();i++){
            cout<<premin<<endl;
            if(nums[i] > premin){
                maxi = max(maxi, nums[i] - premin);
                cout<<maxi<<endl;
            }
          premin = min(premin,nums[i]);
        }
        return maxi;
    }
};