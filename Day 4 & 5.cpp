// Code 1
class Solution{
    public:
    int searchInsertK(vector<int>&arr, int &n, int &k) {
        int s = 0, e = n - 1, res = -1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (arr[m] == k) {
                res = m;
                e = m-1;
            }
            else if (arr[m] < k) s = m + 1;
            else {
                e = m - 1;
            }
        }
        return res == -1 ? s : res;
    }
};

// Code 2
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int l=0,h=x;
        long long m,ans = 0;
        while(l<=h){
            m=l+(h-l)/2;
            if(m*m==x)return m;
            else if(m*m<x) {
                ans=m;
                l=m+1;
            }
            else {
                h=m-1;
            }
        }
        return (int)ans;
    }
};

// Code 3
// O(K) & O(N)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> s(begin(arr), end(arr));
        int i=1, res = -1;
        while(k) {
            if(s.find(i) != s.end()) {
                i++;
            }
            else {
                res = i;
                i++;
                k--;
            }
        }
        return res;
    }
};

// O(LogN)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (arr[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};