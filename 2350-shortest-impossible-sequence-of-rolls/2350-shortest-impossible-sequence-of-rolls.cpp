class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans = 1;
        unordered_set<int> s;
        for (int& a : rolls) {
            s.insert(a);
            if (s.size() == k) {
                ans++;
                s.clear();
            }
        }
        return ans;
    }
};