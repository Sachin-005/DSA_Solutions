class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        vector<int> ans(2, -1);

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
        
                int left = mid;
                while (left > 0 && nums[left - 1] == target) {
                    left--;
                }

             
                int right = mid;
                while (right < n - 1 && nums[right + 1] == target) {
                    right++;
                }

                ans[0] = left;
                ans[1] = right;
                return ans;
            }
        }
        return ans;
    }
};
