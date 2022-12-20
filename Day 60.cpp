// Leetcode Daily - Leaf-Similar Trees

class Solution {
public:
    vector<int> r1, r2;
    void dfs(TreeNode* &root, vector<int> &r) {
        if(!root) return ;
        if(!root->left and !root->right) {
            r.push_back(root->val);
            return ;
        }
        dfs(root->left, r);
        dfs(root->right, r);
    }
    bool leafSimilar(TreeNode* &root1, TreeNode* &root2) {
        dfs(root1, r1);
        dfs(root2, r2);
        int n = size(r1), m = size(r2);
        if(n != m) return false;
        for(int i=0; i<n; i++) {
            if(r1[i] != r2[i]) return false;
        }
        return true;
    }
};

// Code 1 - Number of Islands (Leetcode)

class Solution {
public:
    void bfs(int row, int col, int &n, int &m, vector<vector<char>> &grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++) {
                for(int j=-1; j<=1; j++) {
                    if(abs(i) == abs(j)) continue; // reduction of diagonals
                    int nr = row+i, nc = col+j;
                    if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]=='1') {
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int n = size(grid), m = size(grid[0]);
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]=='1') {
                    res += 1;
                    grid[i][j]='0';
                    bfs(i, j, n, m, grid); // after this is executed, we get one island
                }
            }
        }
        return res;
    }
};

// Code 2 - Knight Tour Official (GFG)

