class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int len = heights.size();
        stack<int>st;
        stack<int>st1;
        
        st.push(-1);
        st1.push(len);
        
        vector<int>left(len, 0);
        vector<int>right(len, 0);
		
        for(int i=0; i<len; ++i) {
            while(st.top()!=-1 && heights[i] <= heights[st.top()]) {
                st.pop();
            }
            left[i] = st.top();
            st.push(i);
        }
        
        for(int i=len-1; i>=0; i--) {
            while(st1.top()!=len && heights[i] <= heights[st1.top()]) {
                st1 .pop();
            }
            right[i] = st1.top();
            st1.push(i);
        }
		
        int ans = INT_MIN;
        for(int i=0; i<len; ++i) {
            ans = max(ans, ( right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};