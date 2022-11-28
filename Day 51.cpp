// Code 1 - Number of recent calls

class RecentCounter {
public:
  /*
   * elements are inserted and have a time span. Output number of elements in between that time span.
   * [1, 100, 3001, 3002] here, 1 & 100 lie in single time span so we don't pop elements.
   * when we ping 3001, we observe we have elements in queue which are outdated or not in timespan when compared to recent inserted element so we pop.
   * return q size.
   */
    queue<int> q;
    RecentCounter() {
        while(!q.empty()) q.pop();
    }
    
    int ping(int t) {
        q.push(t);
        while(q.front() < t-3000) { // less than range? pop
            q.pop();
        }
        return q.size();
    }
};


// Code 2 - Time Needed to Buy Tickets

class Solution {
public:
  /*
   * Reduce array elements whileincrementing time and when k'th person buys all tickets, return total time required.
   * implimented in pair of {total tickets, person}
   */
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        queue<pair<int, int>> q;
        for(int i=0; i<size(tickets); ++i) {
            q.push({tickets[i], i});
        }
        while(!q.empty()) {
            auto val = q.front(); q.pop();
            val.first -= 1, time++;
            if(val.first == 0 and val.second == k) break;
            if(val.first > 0) q.push(val);
        }
        return time;
    }
};


// Code 3 - Reveal Cards In Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int ind = 0, n = size(deck);
        vector<int> res(n);
        queue<int> q;
        for(int i=0; i<size(deck); ++i) q.push(i);
        sort(begin(deck), end(deck));
        while(!q.empty()) {
            res[q.front()] = deck[ind++];
            q.pop(); // card and it's index revealed and removed
            q.push(q.front()); // smaller card's index sent back in order to reveal it later
            q.pop();
        }
        return res;
    }
};