class Solution {
public:
    int sumD(vector<int> &arr, int div) {
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(sumD(nums,mid)<=threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }   
        return ans;
     }
};