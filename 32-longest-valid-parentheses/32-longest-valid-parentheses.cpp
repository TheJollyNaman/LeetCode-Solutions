class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() <= 1) 
            return 0;
        
        int res = 0;
        vector<int> dp(s.length(),0);
        
        for(int i=1; i<s.length(); i++){
            if(s[i] == ')' && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                
                if(i-dp[i-1]-2 >=0) 
                    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                else 
                    dp[i] = dp[i-1] + 2;
                
                res = max(dp[i],res);
            }
        }
        return res;
    }
};