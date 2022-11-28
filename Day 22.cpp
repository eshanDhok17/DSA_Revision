// Daily - Minimum Window Substring
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cMp;
        for(char &ch : t) cMp[ch]++;
        int len = cMp.size(), strtWin = 0, endWin = 1e9;
        for(int i = 0, j = 0; j < s.size(); j++) {
            if(cMp.find(s[j]) != cMp.end()) {
                cMp[s[j]]--;
                if(cMp[s[j]] == 0) len--;
            }
            if(len == 0) {
                while(len == 0) {
                    if(endWin > j-i+1) strtWin = i, endWin = j-i+1;
                    if(cMp.find(s[i]) != cMp.end()) {
                        if(cMp[s[i]] == 0) len++;
                        cMp[s[i]]++;
                    }
                    i++;
                }
            }
        }
        return endWin == 1e9 ? "" : s.substr(strtWin, endWin);
    }
};


// Q1 - K distance from root
vector<int> Kdistance(struct Node *root, int k) {
    queue <Node*> q({ root });
    vector<int> res;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            auto node = q.front(); q.pop();
            res.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(k-- == 0) break;
        res.clear();
    }
    return res;
}


// Q2 - All Nodes at distance K
class Solution {
public:
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentTrack){
        queue<TreeNode*> q({root});
        while(!q.empty()){
            auto p = q.front(); q.pop();
            if(p->left) {
                parentTrack[p->left] = p;
                q.push(p->left);
            }
            if(p->right) {
                parentTrack[p->right] = p;
                q.push(p->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        findParent(root, parentTrack);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q({target});
        visited[target] = true;
        while(!q.empty())
        {
            int size = q.size();
            if(k-- == 0) break;
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front(); q.pop();
              
                if(node->left and !visited[node->left])
                    q.push(node->left); visited[node->left] = true;
                
                if(node->right and !visited[node->right])
                    q.push(node->right); visited[node->right] = true;
              
                if(parentTrack[node] and !visited[parentTrack[target]])
                    q.push(parentTrack[node]); visited[parentTrack[node]] = true;
            }
        }
        vector<int> res;
        while(!q.empty()) {
            TreeNode* current = q.front(); q.pop();
            res.push_back(current->val);
        } root->left = root->right = target = nullptr; // Optimised
        return res;
    }
};


// Q3 - Root to Leaf Path Sum
class Solution {
public:
    bool hasPathSum(Nt, int S) {
        if(!root) n 0;
        else if(S == root->data && root->left == root->right) return 1;
        return hasPm(root->left, S-root->data) | hS-root->data);
    }
};