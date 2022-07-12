#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int>>ans;
        sort(nums.begin(), nums.end());
        
        ll n = nums.size();
        ll i=0, j=0, left, right;
        
        while(i<n){
            j=i+1;
            while(j<n){
                ll sum=(ll)target-nums[i]-nums[j];
                left=j+1; right=n-1;
                while(left<right){
                    ll x = (ll) (nums[left] + nums[right]);
                    ll y = nums[left], z= nums[right] ;
                    
                    if(x>sum)
                        right--;
                    else if(x<sum)
                        left++;
                    else{
                        ans.insert({nums[i],nums[j],nums[left],nums[right]});
                        
                        while(left<right && nums[right]==z)
                            right--;
                        while(left<right && nums[left]==y)
                            left++;
                    }
                    
                }
                j++;
               
            }
            i++;
        }
        vector<vector<int>>res(ans.begin(),ans.end());
        return res;
    }
};