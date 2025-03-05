class Solution {
public:
    long long coloredCells(int n) {
        long long bluecells = 1;
        int added=4;
        while(--n){
            bluecells+=added;
            added+=4;
        }
        return bluecells;

    }
};