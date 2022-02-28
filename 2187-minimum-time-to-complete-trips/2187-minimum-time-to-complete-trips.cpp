class Solution {
public:
    
    bool check(vector<int>& time, int totalTrips, long long mid){
        long long temp = 0;
        for(auto x : time)
        {
            long long val = x;
            temp += (mid / val);
        }
        return temp>=totalTrips;
       
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long l=0,r=1e14;
        long long mid;
        long long ans;
    
            while(l<=r){
                mid = l+(r-l)/2;  
                
                if(check(time,totalTrips,mid)){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        
            return ans;    
    }
};