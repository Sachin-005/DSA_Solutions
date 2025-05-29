class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long exp = n;
        if(n<0){
            exp = -1*exp;
        }
        while(exp){
            if(exp%2==0){
                x = x*x;
                exp = exp/2;
            }
            else{
                ans=ans*x;
                exp = exp-1;
            }
        }
        if(n<0)
        return 1/ans;
        return ans;
    }
};