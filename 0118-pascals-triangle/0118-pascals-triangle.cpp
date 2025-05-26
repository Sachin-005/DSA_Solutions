class Solution {
public:
vector<int> generateRows(int row){
    long res=1;
    vector<int> ans;
    ans.push_back(1);
    for(int col =0;col<row;col++){
        res = res*(row-col);
        res = res/(col+1);
        ans.push_back(res);
    }
    return ans;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            ans.push_back(generateRows(i));

        }
        return ans;
    }
};