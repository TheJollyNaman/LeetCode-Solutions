class Solution {
public:
    int minOperations(string s) {
        
        int res1 = 0, res2 = 0, n = s.size();
        
        for (int i = 0; i < n; ++i) {
            
            if (s[i] - '0' != i % 2)   
                res1++;  
            else  
                res2++;  
            
        }
        
        return min(res1, res2);
    }
};