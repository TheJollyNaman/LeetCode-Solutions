class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=2;
        int i = 0;
        for (int n : nums)
            if (i < k || n > nums[i-k])
                nums[i++] = n;
        return i;
    }
};