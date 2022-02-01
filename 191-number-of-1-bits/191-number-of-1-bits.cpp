class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        
        for(int bit = 0 ; bit < 32 ; bit++){
            cnt += n & 1;
            n = n >> 1;    
        }
        
        return cnt;
    }
};