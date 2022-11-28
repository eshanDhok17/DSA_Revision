// code 1 - Longest Common Subsequences
class Solution {
int dp[1001][1001];
int dfs(int i, int j, string &s1, string &s2) {
    if(i < 0 or j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(i < 0 and j < 0) return 0;
    if(s1[i] == s2[j]) {
        return dp[i][j] = 1 + dfs(i-1, j-1, s1, s2);
    }
    return dp[i][j] = max(dfs(i, j-1, s1, s2), dfs(i-1, j, s1, s2));
}
public:
    int lcs(int x, int y, string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return dfs(x-1, y-1, s1, s2);
    }
};

// code 2 - Shortest Uncommon Subsequences
class Solution {
    int dp[1001][1001];
    int shortestSeq(string &s1, string &s2, int i, int j) {
        if(i >= s1.size()) return 1e9;
        if(j >= s2.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int k = j;
        for( ; k < s2.size(); k++) {
            if(s1[i] == s2[k]) break;
        }
        if(k == s2.size()) return 1;
        return dp[i][j] = min(shortestSeq(s1, s2, i+1, j), 1 + shortestSeq(s1, s2, i+1, k+1));
    }
  public:
    int shortestUnSub(string s, string t) {
        memset(dp, -1, sizeof(dp));
        int m = s.size(), n = t.size(), ans = shortestSeq(s, t, 0, 0);
        return ans >= 1e9 ? -1 : ans;
    }
};

// code 3 - Minimum Ascii Delete Sum For Two Strings