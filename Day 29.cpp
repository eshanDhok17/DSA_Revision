// Convert Sorted array to BST
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return nullptr; // edge case
        if(nums.size() == 1) return new TreeNode(nums[0]); // edge case
        
        int middle = nums.size()/2;
        auto root = new TreeNode(nums[middle]);
        vector<int> leftTree(begin(nums), begin(nums) + middle);
        vector<int> rightTree(begin(nums) + middle + 1, end(nums));
        root->left = sortedArrayToBST(leftTree);
        root->right = sortedArrayToBST(rightTree);
        return root;

    }
};

// Minimum Distance Between BST Nodes
class Solution {
public:
    vector<int>in;
    void dfs(TreeNode* &root){
        if(!root) return;
        dfs(root->left);
        in.push_back(root->val);
        dfs(root->right);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int res = 1e9;
        for(int i = 0; i < size(in); i++){
            for(int j = i + 1; j < size(in); j++){
                int t = abs(in[i] - in[j]);
                if(t < res) res = t;
            }
        }
        return res;
    }
};

// Kth Smallest in BST
class Solution {
public:
    void dfs(TreeNode* root, int &k, int &kth) {
        if(!root) return ;
        dfs(root->left, k, kth);
        if(--k == 0) {
            kth = root->val;
            return ;
        }
        dfs(root->right, k, kth);
    }
    int kthSmallest(TreeNode* &root, int &k) {
        int kth = -1;
        dfs(root, k, kth);
        root->left = nullptr;
        root->right = nullptr;
        return kth;
    }
};

// Binary Search Tree to Greater Sum Tree
class Solution {
public:
    void dfs(TreeNode* root, int &sum) {
        if(!root) return ;
        dfs(root->right, sum);
        root->val += sum;
        sum = root->val;
        dfs(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return root;
    }
};