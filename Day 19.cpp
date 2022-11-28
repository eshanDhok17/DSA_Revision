// Top K Frequent Words
class Solution {
public:
    static bool comp(pair<int, string> &a, pair<int, string> &b) {
        // return a.first == b.first ? a.second < b.second : a.first > b.first; one liner
        if(a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int &k) {
        unordered_map<string, int> map;
        vector<pair<int, string>> pq;
        vector<string> res;
        for(string &word : words) map[word]++;
        for(auto &[a, b] : map) pq.push_back({b, a}); //nlogn
        sort(pq.begin(), pq.end(), comp);
        for(int i=0; i<k; i++) res.push_back(pq[i].second);
        pq.clear(); map.clear(); // explicit space cleared.
        return res;
    }
};

// Largest element in an N-ary Tree
class Solution {
public:
    void dfs(Node* root, int &maxVal) {
        if(!root) return;
        maxVal = max(root->val, maxVal);
        for(auto &child : root->children) {
            dfs(child, maxVal);
        }
    }
    int maxDepth(Node* &root) {
        if(!root) return 0;
        int maxVal = root->val;
        dfs(root, maxVal);
        return maxVal;
    }
};

// Maximum Depth of N-ary Tree
class Solution {
public:
    void dfs(Node* root, int height, int &maxHeight) {
        if(!root) return;
        maxHeight = max(height, maxHeight);
        for(auto &child : root->children) {
            dfs(child, height+1, maxHeight);
        }
    }
    int maxDepth(Node* &root) {
        if(!root) return 0;
        int maxHeight = -1;
        dfs(root, 1, maxHeight);
        return maxHeight;
    }
};

// N-ary Tree Preorder Traversal
class Solution {
vector<int> res;
public:
    void dfs(TreeNode* &root) {
        if(!root) return;
        res.push_back(root->val);
        for(auto &child : root->children) dfs(child);
    }
    vector<int> preorder(Node* root) {
        if(!root) return {};
        dfs(root);
        return res;
    }
};

// N-ary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(Node* &root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<Node*> q({root});
        while(!q.empty()) {
            int size = q.size();
            vector<int> lvl;
            for(int i=0; i<size; i++) {
                auto node = q.front(); q.pop();
                lvl.push_back(node->val);
                for(auto &child : node->children)
                    q.push(child);
            }
            res.push_back(lvl);
        }
        return res;
    }
};