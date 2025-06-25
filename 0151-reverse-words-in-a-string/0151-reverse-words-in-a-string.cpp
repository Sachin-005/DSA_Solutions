class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        string temp="";
        string ans = "";
        for(int i=0;i<size;i++){
            cout<<"temp"<<temp<<endl;
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i] == ' '){
                if(ans.empty() && temp!="") ans = temp;
                else if(!ans.empty()&& temp!="")  ans = temp+" "+ans;
                temp="";
            }
           
        }
        if(!temp.empty()){
            if(ans!="")
         ans = temp+" "+ans;
         else
         ans=temp;
        }
        return ans;
    }
};