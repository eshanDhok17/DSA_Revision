// Leetcode Daily - Minimum Average Difference

class Solution {
public:
  /*
   * Intuition was to use somesort of prefix sum so did just that
   * TC-> O(N) SC-> O(N)
   */
    typedef long long ll;
    int minimumAverageDifference(vector<int>& nums) {
        ll avg = 0, n = size(nums), minn = 1e9,
        sum = accumulate(begin(nums), end(nums), 0LL);
        vector<ll> prefix(n);
        for(int i=0; i<n; ++i) {
            avg += nums[i];
            sum -= nums[i];
            ll prevSum = avg/(i+1);
            ll nextSum = n-(i+1) > 0? sum/(n-(i+1)) : 0;
            prefix[i] = abs(prevSum - nextSum);
            if(minn >= prefix[i]) minn = prefix[i];
        }
        for(int i=0; i<n; ++i) {
            if(prefix[i] == minn) {
                return i;
            }
        }
        return -1;
    }
};

// Solution 2 - Altering actual array TC-> O(N) SC-> O(1)

class Solution {
public:
    typedef long long ll;
    int minimumAverageDifference(vector<int>& nums) {
        ll avg = 0, n = size(nums), minn = 1e9,
           sum = accumulate(begin(nums), end(nums), 0LL);
        
        for(int i=0; i<n; ++i) {
            avg += nums[i];
            sum -= nums[i];
            ll prevSum = avg/(i+1);
            ll nextSum = n-(i+1) > 0? sum/(n-(i+1)) : 0;
            nums[i] = abs(prevSum - nextSum);
            if(minn >= nums[i]) minn = nums[i];
        }
        for(int i=0; i<n; ++i) {
            if(nums[i] == minn) {
                return i;
            }
        }
        return -1;
    }
};

// Code 1 - Merge K sorted Lists

class Solution {
public:
  /*
   * Put into priority queue which will sort it and then create new LinkedList
   * TC-> O(N * Log(N)) SC-> O(N)
   */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<lists.size(); i++) {
            ListNode* head = lists[i];
            while(head) {
                pq.push(head->val);
                head = head->next;
            }
        }
        ListNode* root = new ListNode(0), *cur = root;
        for(; !pq.empty(); root=root->next){
            auto node = pq.top(); pq.pop();
            root->next = new ListNode(node);
        }
        return cur->next;
    }
};

// Code 2 - LRU Cache



// Code 3 - Reorder List

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode* half = head, *temp = head->next, *prev=nullptr;
        while(temp and temp->next) {
            half = half->next, temp = temp->next->next;
        }
        if(temp) half = half->next;
        
        while(half){
            temp = half->next;
            half->next = prev;
            prev = half;
            half = temp;
        }
        // ulat pulat
        half = prev;
        while (head && half) {
            temp = head->next;
            prev = half->next;
            head->next = half;
            half->next = temp;
            head = temp;
            half = prev;
        }
        
        if (head && head->next) head->next->next = NULL; // agar list even rahi to
    }
};