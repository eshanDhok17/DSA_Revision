// LC Daily: Count and Say


// Code 1: Paint House III


// Code 2: Longest palindromic Subsequence
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() < 3) return s.size() == 1 ? 1 : s[0] == s[1] ? 2 : 1;
        string revs = s;
        reverse(s.begin(), s.end());
        int n = size(s), maxi(0);
        vector<int> prev(n+1, 0), cur = prev;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == revs[j-1]) {
                    cur[j] = 1 + prev[j-1];
                    maxi = max(maxi, cur[j]);
                }
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return maxi;
    }
};

// Code 3: Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),l,h;
        if(n==1)return s;
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int gap = 0; gap < n; gap++){
            for(int i = 0, j = gap; j < n; i++, j++){
                if(gap == 0)
                    dp[i][j] = 1;
                
                else if(gap == 1 && s[i] == s[j])
                    dp[i][j] = 1;
                
                else if(s[i] == s[j] && dp[i+1][j-1] == 1)
                    dp[i][j] = 1;
                
                if(dp[i][j] == 1){
                    l = i;
                    h = gap + 1;
                }
            }
        }
        return s.substr(l, h);
    }
};


// Other problems which i did

// Transition Point
int transitionPoint(int arr[], int n) {
    int trans = -1, s = 0, e = n-1, m;
    while(s <= e) {
        m = s + (e - s) / 2;
        if(arr[m] == 1) e = m - 1;
        else {
            s = m + 1;
            trans = s;
        }
    }
    return trans > n - 1 ? -1 : trans < 0 ? 0 : trans;
}

// Floor In Sorted Array
int findFloor(vector<long long> v, long long n, long long x) {
    long long s = 0, e = n-1, res = -1;
    while(s <= e) {
        long long m = s+ (e-s)/2;
        if(v[m] == x) return m;
        else if(v[m] < x) {
            res = m;
            s = m + 1;
        } else e = m-1;
    }
    return (int)res;
}

// Find Duplicates in Arrays
  public:
    vector<int> duplicates(int arr[], int n) {
        unordered_map<int, int> m;
        vector<int> v;
        for(int i=0; i<n; i++){
            m[arr[i]]++;
        }
        for(auto i:m){
            if(i.second>1){
                v.push_back(i.first);
            }
        }
        if(v.empty()){
             v.push_back(-1);
         }
         sort(v.begin(),v.end());
         return v;

    }
};

// Subarray With Given Sum
public:
    vector<int> subarraySum(int arr[], int n, long long s) {
     int i=0, j=0;
     long long int sum=0;
     while(j < n) {
         sum += arr[j++];
         while(sum > s) {
             sum -= arr[i++];
             if(sum == s)
             return {i+1, j};
         }
         return {-1};
     }
};

// Index of an Extra Element
class Solution{
  public:
    int findExtra(int a[], int b[], int n) {
        int res = n-1, s=0, e=n-1, m;
        while(s <= e) {
            m = s + (e-s)/2;
            if(a[m] == b[m]) s = m+1;
            else {
                res = m;
                e = m - 1;
            }
        }
        return res;
    }
};
