class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0;
        int required=0;
        for(char c: s){
            if ( c == '('){
                open++;
            }
            else{
                if(open>0) open--;
                else
                required++;
            }
        }
        return open+required;
    }
};