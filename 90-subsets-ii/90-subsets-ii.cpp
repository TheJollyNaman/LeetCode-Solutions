class Solution {

    void helper(int ind,vector<vector<int>> &ans, vector<int> &ds, vector<int>& arr){
        
        ans.push_back(ds);
        
        for(int i = ind;i<arr.size();i++){
            if(i!=ind && arr[i]==arr[i-1])
                continue;
            
            ds.push_back(arr[i]);
            helper(i+1,ans,ds,arr);
            ds.pop_back();
        }
    }
    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        helper(0,ans,ds,nums);
        return ans;
    }
};