class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false;
        
        unordered_set<string>us;
        int l = 0, r = k-1;
        
        while(r++ < s.size())
            us.insert(s.substr(l++, k));
        
        return us.size() == 1<<k;
    }
};