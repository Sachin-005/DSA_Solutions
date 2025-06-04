class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0, high = cols - 1;

        while (low <= high) {
            int midCol = (low + high) / 2;
            int maxRow = 0;

            for (int row = 1; row < rows; row++) {
                if (mat[row][midCol] > mat[maxRow][midCol]) {
                    maxRow = row;
                }
            }

            int current = mat[maxRow][midCol];
            int left = (midCol > 0) ? mat[maxRow][midCol - 1] : INT_MIN;
            int right = (midCol < cols - 1) ? mat[maxRow][midCol + 1] : INT_MIN;

            if (current > left && current > right) {
                return {maxRow, midCol};
            }

            if (right > current) {
                low = midCol + 1;
            } else {
                high = midCol - 1;
            }
        }

        return {-1, -1};
    }
};
