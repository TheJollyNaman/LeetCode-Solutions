class Solution {
private:
        vector<int> dp = vector<int>(101,-1);
public:
    int dpp(vector<int>& nums,int ind){
        if(ind==0)
            return nums[0];
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        
        int pick = nums[ind] + dpp(nums,ind-2);
        int not_pick = 0 + dpp(nums,ind-1);
        
        dp[ind] = max(pick,not_pick);
        return dp[ind];
    }
    
    int rob(vector<int>& nums) {
        return dpp(nums,nums.size()-1);
    }
};