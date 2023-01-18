// Code 1 - Kth Largest Element in an Array
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

// Code 2 - Merge K Sorted Lists


// Code 3 - Merge K Sorted Arrays
