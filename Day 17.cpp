// Leetcode Daily - Check if the Sentence Is Pangram
class Solution {
public:
    bool checkIfPangram(string &sent) {
        unordered_set<char> charMap;
        for(char &ch : sent)
            if(charMap.find(ch) == charMap.end())
                charMap.insert(ch);
        
        return charMap.size() == 26;
    }
};

// Question 1 - Kadane's Algorithm
class Solution {
    //Function to find the sum of contiguous subarray with maximum sum.
    long maxSubarraySum(int arr[], int n){
        long sum = 0, res = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            res = Math.max(res, sum);
            if(sum < 0) sum = 0;
        }
        return res;
    }
    
}

// Question 2 - Largest Sum Subarray of Size at least K
typedef long long int lli;
lli dp[100001];
lli f(lli i, lli t, vector<lli> &v, lli &k) {
    if(i == 0) return v[0];
    int take = v[i], notTake = f(i-1, t, v, k);
    // choices ?
    take += f(i-1, t+1, v, k);
    if(t >= k) return dp[i] = max(take, notTake);
    return dp[i]
}

lli maxSumWithK(long long int a[], long long int n, long long int k) {
    vector<lli> v;
    memset(dp, -1e9, sizeof(dp));
    for(lli i=0; i<n; i++) v.push_back(a[i]);
    return f(n-1, 0, v, k);
}