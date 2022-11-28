// Daily Leetcode - Delete Node in LinkedList
class Solution {
public:
    void deleteNode(ListNode* node) { // O(1) Solution
        node->val = node->next->val; // copy value of next node in current
        node->next = node->next->next; // unlink node->nex
    }
};
// CODE 1 - Russian Doll Envelopes

// CODE 2 - Cherry Pickup II
class Solution {
int dp[71][71][101]; // memo
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        memset(dp, -1, sizeof(dp));
        return f(0,0,c-1,r,c,grid); // parent recursion call
    }
    int f(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid) {
        if(j1<0 or j2<0 or j1>=c or j2>=c) return -1e8; // edge case
        if(i==r-1){
            return j1==j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2]; // memo
        int maxi = -1e9;
        for(int dj1=-1; dj1<=1; dj1++) {
            for(int dj2=-1; dj2<=1; dj2++) {
                int val = 0;
                val = j1==j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                val += f(i+1, j1+dj1, j2+dj2, r, c, grid);
                maxi = max(val, maxi);
            }
        }
        return dp[i][j1][j2] = maxi; // return current state answer
    }
};