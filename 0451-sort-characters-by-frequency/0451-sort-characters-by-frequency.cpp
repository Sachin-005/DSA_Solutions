class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : mp) {
            pq.push({it.second,it.first});
        }
        string result = "";
        while (!pq.empty()) {
            int freq    = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            result += string(freq, ch); 
        }

        return result;
    }
};
