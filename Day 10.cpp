// Leetcode Daily - Path Sum - DFS - O(N) overall
class Solution {
vector<int> inorder;
public:
    bool findTarget(TreeNode* &root, int &k) {
        auto cur = root;
        while(cur) {
            if(cur->left == nullptr) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                auto prev = cur->left;
                while(prev->right && prev->right != cur) prev = prev->right;
                if(prev->right) {
                    prev->right = nullptr;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
                else {
                    prev->right = cur;
                    cur = cur->left;
                }
            }
        } root->left = root->right = nullptr;
        int n = size(inorder), i = 0, j = n-1;
        while(i < j) {
            if(inorder[i] + inorder[j] == k) return true;
            else if(inorder[i] + inorder[j] > k) j--;
            else if(inorder[i] + inorder[j] < k) i++;
        }
        return false;
    }
};

// Code 1 - Knapsack without duplicate

class Solution {
int dp[1001][1001];
public:
    int f(int n, int W, int wt[], int val[]) {
        if(dp[n][W] != -1) return dp[n][W]; // Memo
        if(n < 0) return 0;
        if(n == 0) {
            if(W >= wt[0]) return val[0];
            if(W == 0 and wt[0] == 0) return val[0];
            if(W < wt[0]) return 0;
            return 0;
        }
        int notTake = f(n-1, W, wt, val), take = 0;
        if(W >= wt[n]) take = val[n] + f(n-1, W-wt[n], wt, val);
        return dp[n][W] = max(take, notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        memset(dp, -1, sizeof(dp));
        return f(n-1, W, wt, val);
    }
};

// Code 2 - Knapsack with duplicate items

class Solution {
public:
int dp[1001][1001];
public:
    int f(int n, int W, int wt[], int val[]) {
        if(dp[n][W] != -1) return dp[n][W]; // Memo
        if(n < 0) return 0;
        if(n == 0) {
            if(W >= wt[0]) return (W/wt[0]) * val[0];
            if(W == 0 and wt[0] == 0) return val[0];
            if(W < wt[0]) return 0;
            return 0;
        }
        int notTake = f(n-1, W, wt, val), take = 0;
        if(W >= wt[n]) take = max(val[n] + f(n, W-wt[n], wt, val),
                                  val[n] + f(n-1, W-wt[n], wt, val));
        return dp[n][W] = max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(dp, -1, sizeof(dp));
        return f(N-1, W, wt, val);
    }
};

// Code 3 Ones and Zeroes -

// Code 4 Reducing Dishes -