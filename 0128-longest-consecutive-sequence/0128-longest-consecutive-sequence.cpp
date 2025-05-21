class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxCount = 0,x;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(int num: st){
           if(st.find(num-1) == st.end()){
             x = num;
           int cnt = 1;
            while(st.find(x+1)!=st.end()){
                x+=1;
                cnt+=1;   
            }
             maxCount = max(cnt,maxCount);
        }
        }
        return maxCount;
    }
};