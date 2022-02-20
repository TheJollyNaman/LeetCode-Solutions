class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size(); 
        
        sort(arr.begin(), arr.end()); 
        int maximum_left = -1, maximum_right = -1; 
        
        int ans = 0; 
        
        for(int i = 0; i < n; i++) 
        {
            if(arr[i][0] > maximum_left && arr[i][1] > maximum_right)
            {
                ans++; 
                maximum_left = arr[i][0];  
            }
            maximum_right = max(maximum_right, arr[i][1]);
        }
        
        return ans;
    }
};