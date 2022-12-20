

class Solution {
public:
  	/*
  	 * Simple BFS traversal and check if visited rooms are equal to rooms.size()
     */
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = size(rooms);
        vector<bool> vis(n, false);
        queue<int> q({0});
        vis[0] = true;
        while(!q.empty()) {
            int sz = size(q);
            for(int i=0; i<sz; ++i) {
                int room = q.front(); q.pop();
                vis[room] = true;
                for(int &ele : rooms[room]) {
                    if(!vis[ele]) q.push(ele);
                }
            }
        }
        return count(begin(vis), end(vis), true) == n;
    }
};