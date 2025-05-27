class Solution {
public:
    int search(vector<int>& arr, int target) {
       int left = 0;
       int right = arr.size()-1;
       while(left<=right){
        int mid = (left+right)/2;
        if(target < arr[mid]){
            right = mid-1;
        }
        else if(arr[mid] == target){
            return mid;
        }
        else{
            left = mid+1;
        }
       }
       return -1;
    }
};