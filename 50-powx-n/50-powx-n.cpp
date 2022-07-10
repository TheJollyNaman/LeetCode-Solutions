class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        double xx = x;
        long long nn = n;
        if(n<0)
            nn = -1 * nn;
        while(nn){
            if(nn % 2){
                ans = ans * xx;
                nn = nn - 1;
            }
            else{
                xx = xx * xx;
                nn = nn / 2;
            }
        }
        if(n<0)
            ans = (double) 1.0 / (double) ans;
        
        return ans;
    }
};