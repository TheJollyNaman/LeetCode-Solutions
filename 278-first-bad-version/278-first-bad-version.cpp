// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int mid=0;
        int l=1,r=n;
        while(l<r){
            mid=l+(r-l)/2;
    
            if(!isBadVersion(mid))
                l=mid+1;
            else if(isBadVersion(mid) && !isBadVersion(mid-1))
                return mid;
            else
                r=mid-1;
        }
        
        return l;
    }
};