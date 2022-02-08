class Solution {
public:
    
    void helper(int ind,vector<vector<int>>& ans,vector<int>& arr){
        if(ind==arr.size()){
            ans.push_back(arr);
            return;
        }
        
        for(int i=ind;i<arr.size();i++){
            swap(arr[ind],arr[i]);
            helper(ind+1,ans,arr);
            swap(arr[ind],arr[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;        
        helper(0,ans,nums);
        return ans;
    }
};