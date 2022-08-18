class Solution {
private:
        vector<int> dp = vector<int>(101,0);
public:
    int dpp(vector<int>& nums,int ind){
        int prev = nums[0];
        int prev2 = 0;
        int curri;
        
        for(int i=1;i<ind;i++){
            int take = nums[i];
            if(i>1)
                take+=prev2;
            int not_take = prev;
            
            curri = max(take,not_take);
            prev2 = prev;
            prev = curri;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        return dpp(nums,nums.size());
    }
};