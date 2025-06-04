class Solution {
public:
    int findDays(vector<int>& ans, int days, int capacity){
        int load=0;
        int day=1;
        for(int i=0;i<ans.size();i++){
            if(load+ans[i] > capacity){
                day++;
                load=0;
            }
           
            load+=ans[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi =*max_element(weights.begin(),weights.end());
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int low = maxi;
        int high = sum;
        int ans=-1;
        while(low<=high){
            int mid =(low+high)/2;
            int dayds = findDays(weights,days,mid);
            if(dayds<=days){
                ans =mid;
                high = mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};