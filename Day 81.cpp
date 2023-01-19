// Code 1 - Minimum Cost to Connect Sticks- O(NlogN)

class Solution {
public:
    /**
     * @param sticks: the length of sticks
     * @return: Minimum Cost to Connect Sticks
     */
    int minimumCost(vector<int> &sticks) {
        // write your code here
        int sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto &stick : sticks) {
            pq.push(stick);
        }
        while(pq.size() > 1) {
            int stick1 = pq.top(); pq.pop();
            int stick2 = pq.top(); pq.pop();
          	int bigStick = (stick1 + stick2);
            sum += bigStick;
            pq.push(bigStick);
        }
        return sum;
    }
};

// Code 2 - K Closest Points to Origin - O(NlogK)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, pair<int, int>>> pq;
        for(auto &point : points) {
            int x = point[0], y = point[1];
            pq.push({(pow(x,2) + pow(y, 2)), {x, y}});
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) {
            auto top = pq.top(); pq.pop();
            res.push_back({top.second.first, top.second.second});
        }
        return res;
    }
};
