class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //running sum x, running sum y and target sum concept from cracking coding interviews 
        int sum=0; 
        map<int,int> rec; 
        int cnt = 0; 
        rec[0]++; 
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cnt += rec[sum-k];
            rec[sum]++;
        }
        
        return cnt;
    }
};