class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int na = a.length();
        int nb = b.length();
        
        string repeated = a;
        int count = 1;
    
        while (repeated.length() < nb) {
            repeated += a;
            count++;
        }
        if (repeated.find(b) != string::npos)
            return count;
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos)
            return count;

        return -1;
    }
};
