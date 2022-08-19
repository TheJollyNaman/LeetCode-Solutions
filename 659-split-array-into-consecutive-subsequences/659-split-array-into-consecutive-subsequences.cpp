class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> dict, temp;
        
        for (auto& ele: nums) 
            dict[ele]++;
        
        for (auto& ele: nums){
            if (dict[ele]==0)   
                continue;
            else if (temp[ele]>0){  
                dict[ele]--;
                temp[ele]--;
                temp[ele+1]++;
                
            }
            else if (dict[ele+1]>0 && dict[ele+2]>0){ 
                dict[ele]--;
                dict[ele+1]--;
                dict[ele+2]--;
                temp[ele+3]++;
            }
            else
                return false;
        }
        
        return true;
    }
};