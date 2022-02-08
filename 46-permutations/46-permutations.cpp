class Solution {
public:
    
    void helper(vector<int>& arr, vector<vector<int>>& ans,vector<int>& ds, int freq[]){
        if(ds.size()==arr.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<arr.size();i++){
            if(!freq[i]){
                ds.push_back(arr[i]);
                freq[i]=1;
                helper(arr,ans,ds,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        
        for(int i=0;i<nums.size();i++)
            freq[i]=0;
        
        helper(nums,ans,ds,freq);
        return ans;
    }
};