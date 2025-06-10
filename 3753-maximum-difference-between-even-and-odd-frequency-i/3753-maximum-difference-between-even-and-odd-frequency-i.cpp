class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(char c: s){
            mp[c]++;
        }
        int maxOdd=INT_MIN,minEven=INT_MAX;
        for(auto it: mp){
            if(it.second%2 == 0){
                minEven = min(it.second,minEven);
            }
            else{
                maxOdd = max(it.second,maxOdd);
            }
        }
        return maxOdd - minEven;
    }
};