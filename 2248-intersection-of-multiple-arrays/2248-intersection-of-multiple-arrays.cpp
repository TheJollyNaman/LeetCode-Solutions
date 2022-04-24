class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        vector<int> num(1001,0);
        
        int total_size=nums.size();
        for(int i=0;i<total_size;i++){
            for(int j=0;j<nums[i].size();j++){
                num[nums[i][j]]++;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<1001;i++){
            if(num[i]==total_size){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};