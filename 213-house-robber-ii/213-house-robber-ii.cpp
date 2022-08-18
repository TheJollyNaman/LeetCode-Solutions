class Solution {
public:
    
    int solve(vector<int>& nums,int ind){
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
        vector<int> arr1;
        vector<int> arr2;

        if(nums.size()==1)
           return nums[0];

        for(int i=0; i<nums.size(); i++){

            if(i!=0) 
                arr1.push_back(nums[i]);
            if(i!=nums.size()-1) 
                arr2.push_back(nums[i]);
        }

        int ans1 = solve(arr1,nums.size()-1);
        int ans2 = solve(arr2,nums.size()-1);

        return max(ans1,ans2);
    }
};