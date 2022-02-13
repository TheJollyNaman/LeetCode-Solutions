class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> ds;
        subsets(nums, 0, ds, subs);
        return subs;
    }

    void subsets(vector<int>& nums, int i, vector<int>& ds, vector<vector<int>>& subs) {
        subs.push_back(ds);
        for (int j = i; j < nums.size(); j++) {
            ds.push_back(nums[j]);
            subsets(nums, j + 1, ds, subs);
            ds.pop_back();
        }
    }
};