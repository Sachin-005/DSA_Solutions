class Solution {
public:
    vector<string> function(vector<string>& ans, int n,int open, int close,string bracket){
        if(bracket.length() == 2*n){
            ans.push_back(bracket);
        }
        if(open < n){
            function(ans,n,open+1,close,bracket+'(');
        }
        if(close<open){
            function(ans,n,open,close+1,bracket+')');
        }
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
       return function(ans,n,0,0,"");
    }

};