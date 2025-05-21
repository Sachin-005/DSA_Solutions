class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int m = matrix.size();
       int n = matrix[0].size();
       vector<int> rows(m,0);
       vector<int> col (n,0);
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j] == 0){
                rows[i] = 1;
                col[j] =1;
            }
        }
       }
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(rows[i]|| col[j]){
                matrix[i][j] =0;
            }
        }
       }
    }

};