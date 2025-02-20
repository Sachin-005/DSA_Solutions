class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        if(k>n) k = k%n;
        for(int i=0;i<k;i++){
            temp[i]=nums[n-k+i];
            cout<<temp[i]<<endl;

        }
        for(int i=0;i<n-k;i++){
            temp[k+i] = nums[i];
        }
        nums=temp;
    }
};