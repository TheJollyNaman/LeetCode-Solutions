class Solution {
public:
    void helper(int target, int ind, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds){
        
            if(target == 0){
                ans.push_back(ds);
                return;
            }
        
        
        for(int i=ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1])
                continue;
            if(arr[i]>target)
                break;
            ds.push_back(arr[i]);
            helper(target-arr[i],i+1,arr,ans,ds);
            ds.pop_back();
        }
        
        
    }
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(target,0,candidates,ans,ds);
        
        return ans;
    }
};