class Solution {
private:
        vector<int> dp = vector<int>(101,0);
public:
    int dpp(vector<int>& nums,int ind){
        dp[0]=nums[0];
        
        for(int i=1;i<ind;i++){
            int take = nums[i];
            if(i>1)
                take+=dp[i-2];
            int not_take = dp[i-1];
            
            dp[i] = max(take,not_take);
        }
        
        return dp[ind-1];
    }
    
    int rob(vector<int>& nums) {
        return dpp(nums,nums.size());
    }
};