class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string temp="";
        int j=0;
        for(int i=0;i<s.size();i++){
             if (j < spaces.size() && spaces[j] == i) {
                temp += " "; 
                j++; 
            }
            temp+=s[i];
           
        }
        return temp;
    }
};