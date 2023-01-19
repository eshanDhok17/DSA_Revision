// Code 1 - Kth Largest Element in an Array (nLogK)
class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int, vector<int>, greater<>> pq;
        for(int i=0; i<size(A); ++i) {
            if(pq.size() == k) {
                if(pq.top() >= A[i]) continue;
                pq.pop();
                pq.push(A[i]);
            }
            else pq.push(A[i]);
        }
        return pq.top();
    }
};

// Code 2 - Merge K Sorted Lists (NlogK)
class Solution {
public:
    typedef pair<int, ListNode*> pair;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        priority_queue<pair, vector<pair>, greater<pair>> pq;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode dummy(0), *head = &dummy;
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            auto node = top.second;
            head->next = node;
            head=head->next;
            if(node->next)
                pq.push({node->next->val, node->next});
        }
        return dummy.next;
    }
};

// Code 3 - Merge K Sorted Arrays
class Solution {
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k) {
        vector<int> res;
        int n = arr.size();
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<arr.size(); i++) {
            pq.push({arr[i].back(), i});
            arr[i].pop_back(); // remove after inserting
        }
        
        while(pq.size() > 0) {
            auto p = pq.top(); pq.pop();
            int val = p.first, i = p.second;
            res.push_back(val);
            if(arr[i].size()) {
                // insert next smaller values
                pq.push({arr[i].back(), i});
                // remove after inserting
                arr[i].pop_back();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
