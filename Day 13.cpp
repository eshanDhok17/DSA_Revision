// Todays Daily Challenge - Largest Perimeter Triangle
class Solution {
public:
    int isValid(int &a, int &b, int &c) {
        return (a + b <= c || a + c <= b || b + c <= a) ? 0 : a+b+c;
    }
    int largestPerimeter(vector<int>& nums) {
        int res = 0;
        sort(begin(nums), end(nums));
        for(int i=2; i<size(nums); i++)
            res = max(res, isValid(nums[i-2], nums[i-1], nums[i]));
        return res;
    }
};

// code 1 - 


// code 2 - 

// Code 3 - Best Time to Buy and Sell Stock with Transaction Fee
class Solution {
    int f(int i, int n, int buy, int &fees, vector<int>&prices, vector<vector<int>>&dp) {
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy == 1) {
            profit = max(-prices[i] + f(i+1, n, 0, fees, prices, dp),
                                      f(i+1, n, 1, fees, prices, dp));
        }
        else {
            profit = max(prices[i] - fees + f(i+1, n, 1, fees, prices, dp),
                                     f(i+1, n, 0, fees, prices, dp));
        }
        return dp[i][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int &fees) {
        int n = prices.size(), buy = 1;
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return f(0, n, buy, fees, prices, dp);
    }
};