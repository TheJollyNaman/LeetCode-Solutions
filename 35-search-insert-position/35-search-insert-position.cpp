class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        int mid=0;
          while(i<j)
               {
                   mid=(i)+(j-i)/2;
                   if(nums[mid]>=target)
                   {
                       j=mid;
                   }
                   else
                   {
                        i=mid+1;
                   }
               }
        if(i==nums.size()-1 && nums[i]<target)
        {
            i=i+1;
        }
        return i;
    }
};