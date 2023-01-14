// Daily LeetCode Challenge

// Question 1 - Longest Substring Without Repeating Charecters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int ans = 1;
        unordered_map<char, int> mp;
        for(int i=0, j=0; j<size(s); j++) {
            mp[s[j]]++;
            if(j-i+1 == mp.size()) {
                ans = max(ans, j-i+1);
            }
            while(j-i+1 > mp.size()) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};

// Question 2 - Longest K unique characters substring
class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans = -1;
        unordered_map<char, int> mp;
        for(int i=0, j=0; j<s.size(); j++) {
            mp[s[j]]++;
            if(mp.size() == k) {
                ans = max(ans, j-i+1);
            }
            while(mp.size() > k) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
        }
        return ans < 0? -1 : ans;
    }
};
