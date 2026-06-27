class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int ans=0;
        for(int i=0; i<=n; i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int h=heights[st.top()];
                st.pop();
                int right=i;
                int left=st.empty()? -1:st.top();
                ans=max(ans,h*(right-left-1));

            }
            st.push(i);
        }
        return ans;
    }
};