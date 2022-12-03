// Leetcode Daily - Sort Charecters by Frequency

class Solution {
public:
  /*
   * Put charecters in a frequency map,
   * ex:- tree ==> [t : 1], [r : 1], [e : 2]
   * then put them into priority queue to sort charecters by frequency
   * create string while popping charecters
   */
    string frequencySort(string &s) {
        priority_queue<pair<int, int>> pq;
        unordered_map<char, int> mp;
        for(char &c : s) mp[c]++;
        for(auto [a, b] : mp) pq.push({b, a});
        s = ""; // reuse s
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            while(--top.first) {
                s += top.second;
            }
        }
        return s;
    }
};

// Code 1 - Reverse nodes in K-group

class Solution {
public:
  /*
   * Basic Intution is to call reverse function for every k Nodes recursively by passing xth and (x+k)th node
   * time - O(n), space - O(n/k) recursive stack space
   */
    ListNode* reverseList(ListNode* &head, ListNode* &tail) {
        ListNode *cur = head, *prev = nullptr, *next = nullptr;
        while(cur != tail) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* &head, int &k) {
        auto cur = head;
        for(int i=0; i<k; i++) {
            if(!cur) return head;
            cur = cur->next;
        }
        auto newHead = reverseList(head, cur);
        head->next = reverseKGroup(cur, k);
        return newHead;
    }
};

// Code 2 - LinkList Cycle II

// Approach 1 - Slow and fast pointers

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto hare = head, tortoise = head;
        while(hare and hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(hare == tortoise) {
                tortoise = head;
                while(tortoise != hare) {
                    tortoise = tortoise->next, hare = hare->next;
                }
                return tortoise;
            }      
        }
        return nullptr;
    }
};

// Approach 2 - Set (only valid for unique elements)

class Solution {
public:
    // O(n)-Time and Space
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        auto t = head;
        
        while(t and t->next) {
            if(s.find(t)!= s.end()) return t;
            s.insert(t);
            t = t->next;
        }
        return nullptr;
    }
};

// Code 3 - Add Two Numbers

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int CurrSum = 0;
        while (l1 or l2 or CurrSum) {
            //Summing values and moving links to next
            if (l1) CurrSum += l1->val, l1 = l1->next;
            if (l2) CurrSum += l2->val, l2 = l2->next;
            p->next = new ListNode(CurrSum % 10); // new node created with sum
            CurrSum /= 10; // Makes CurrSum 0
            p = p->next;
        }
        return preHead.next; // because we initialized it with 0 and then made links.
    }
};
