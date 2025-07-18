class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int na = a.length();
        int nb = b.length();
        
        string repeated = a;
        int count = 1;
        
        // Repeat until length >= length of b
        while (repeated.length() < nb) {
            repeated += a;
            count++;
        }
        
        // Check if b is now a substring
        if (repeated.find(b) != string::npos)
            return count;

        // Try one more repeat
        repeated += a;
        count++;

        if (repeated.find(b) != string::npos)
            return count;

        return -1;
    }
};
