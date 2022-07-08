class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int n=nums.size();
        vector<int> prefixSum(n,0),suffixSum(n,0);
        
        prefixSum[0]=nums[0];
        suffixSum[nums.size()-1]=nums[nums.size()-1];
        
        for(int i=1;i<nums.size();i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
        for(int i=nums.size()-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+nums[i];
        }
        
        if(suffixSum[1]==0){
            return 0;
        }
        for(int i=1;i<nums.size()-1;i++){
            if(prefixSum[i-1]==suffixSum[i+1])
                return i;
        }
        if(prefixSum[n-2]==0){
            return n-1;
        }
        return -1;
    }
};