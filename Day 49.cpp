// Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<pair<int, int>> st;
        
        for (int i = 0; i < n; i++) {
            if (st.empty()) left[i] = -1;
            else if (st.top().first < heights[i]) left[i] = st.top().second;
            else if (st.top().first >= heights[i]) {
                while (!st.empty() && st.top().first >= heights[i]) st.pop();
                left[i] = !st.empty() ? st.top().second : -1;
            }
            st.push({heights[i], i});
        }
        //clearing stack
        while(!st.empty()) st.pop();
        
        for (int i = n-1; i >= 0; i--) {
            if (st.empty()) right[i] = n;
            else if (st.top().first < heights[i]) right[i] = st.top().second;
            else if (st.top().first >= heights[i]) {
                while (!st.empty() && st.top().first >= heights[i]) st.pop();
                right[i] = !st.empty() ? st.top().second : n;
            }
            st.push({heights[i], i});
        }
        
        for(int i=0; i<n; i++) heights[i] = heights[i] * (right[i] - left[i] - 1);
        return *max_element(heights.begin(), heights.end());
    }
};

// Sum of Subarray Minimums
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        long long sum = 0;
        int n = size(nums), mod = (1e9 + 7);
        for(int i=0; i<n; i++) {
            int minn=nums[i];
            for(int j=i; j<n; j++) {
                minn = min(minn, nums[j]);
                sum += minn;
                sum %= mod;
            }
        }
        return (int)sum;
    }
};