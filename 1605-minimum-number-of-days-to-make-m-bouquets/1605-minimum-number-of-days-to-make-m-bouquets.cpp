class Solution {
public:
    int possible(vector<int>& arr, int m, int k, int day){
        int cnt =0;
        int bq=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day)
            cnt++;
            else{
                bq+=(cnt/k);
                cnt=0;
            }
        }
        bq+=(cnt/k);
        return bq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

         if ((long long)m * k > n) return -1;

       int mini = *min_element(bloomDay.begin(),bloomDay.end());
       int maxi = *max_element(bloomDay.begin(),bloomDay.end());

       int low = mini;
       int high = maxi;
    int res=-1;
       while(low<=high){
        int mid = (low+high)/2;
        int ans = possible(bloomDay,m,k,mid);
        if(ans >= m){
            res=mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
       }
       return res;
    }
};