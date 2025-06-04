class Solution {
public:
int partiton(vector<int>& nums, int sum){
    int subarraySum =0;
    int partition=1;

    for(int i=0;i<nums.size();i++){
        if(nums[i]+subarraySum > sum){
            partition++;
            subarraySum = nums[i];
        }
        else{
            subarraySum+=nums[i];
        }
    }
    return partition;
}
    int splitArray(vector<int>& nums, int k) {
        int ans=0;
        int low = *max_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int high = sum;
        while(low<=high){
            int mid = (low+high)/2;
            int count = partiton(nums,mid);
            if(count<=k){
              ans=mid;
              high = mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }

};