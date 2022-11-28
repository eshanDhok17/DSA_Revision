// Code 1 - Daily Temperatures

class Solution {
public:
    /* 
     * next greater element to right
     * difference of indexes to be stored in array
    */
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n = size(temp);
        vector<int> res(n);
        for(int i = n-1; i >= 0; --i) {
            if(st.empty()) res[i] = 0;
            while(!st.empty() and st.top().first <= temp[i]){
                st.pop();
            }
            if(!st.empty()) res[i] = (st.top().second - i);
            else res[i] = 0;
            st.push({temp[i], i});
        }
        return res;
    }
};

// Code 2 - Final Prices with a Special Discount

class Solution {
public:
    /* 
     * next smaller element to right
     * difference of values (where i < j and arr[i] > arr[j]) to be stored in array
    */
    vector<int> finalPrices(vector<int>& p) {
       stack<int> st;
        int n = size(p);
        vector<int> res(n);
        for(int i = n-1; i >= 0; --i) {
            if(!st.size()) res[i]=p[i];
            while(st.size() and st.top() > p[i]) st.pop();
            if(st.size()) res[i] = (p[i] - st.top());
            else res[i] = p[i];
            st.push(p[i]);
        }
        return res;
    }
};

// Code 3 - Next greater Element IV


// Code 4 - Replace Elements with Greatest Element on Right Side
class Solution {
public:
  /*
   * Stack can be used but also O(1) space.
   */
    vector<int> replaceElements(vector<int>& arr) {
        int n = size(arr), curMx=-1;
        vector<int> res(n, -1);
        for(int i=n-1; i>=0; --i) {
            res[i] = curMx;
            curMx = max(curMx, arr[i]);
        }
        return res;
    }
};