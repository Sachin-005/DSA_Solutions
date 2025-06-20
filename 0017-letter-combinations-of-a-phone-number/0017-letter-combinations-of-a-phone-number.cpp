class Solution {
public:
    void backtrack(string digits, int index, string comb,vector<string>& res, string phone_map[]){
        if(index==digits.size()){
            res.push_back(comb);
            return;
        }
        string letter = phone_map[digits[index] - '2'];
        for(char let: letter){
            backtrack(digits,index+1,comb+let,res,phone_map);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        string phone_map[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        backtrack(digits, 0, "", res, phone_map);
        
        return res;        
    }
};