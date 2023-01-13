// Problem 1 - Equal 0, 1 and 2
// Ratio or number method - Third varition
typedef long long ll;
class Solution {
  public:
    ll getSubstringWithEqual012(string s) {
        ll cnt = 0;
        unordered_map<string, ll> mp;
        mp["0/0"] = 1;
        string key;
        ll c0 = 0, c1 = 0, c2 = 0;
        /*
            Approach:-
                we use it as ratios
                we increment ans where we get same ratio string
        */
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '0') {
                c0++;
            }
            else if(s[i] == '1') {
                c1++;
            }
            else {
                c2++;
            }
            key = to_string(c1-c0) + '/' + to_string(c2-c1);
            if(mp.find(key) != mp.end()) {
                cnt += mp[key];
            }
            mp[key]++;
        }
        return cnt;
    }
};

// Problem 2 - Minimum Window Substring
class Solution
{
public:
    string minWindow(string s, string t)
    {
        if(size(s) < size(t)) return ""; // edge case - O(1)
        
        unordered_map<char, int> mp;
        for(char &ch : t) mp[ch]++;
        
        int len = size(mp), startWin = 0, endWin = 1e9;
        
        for(int i=0, j=0; j<size(s); j++)
        {
            if(mp.find(s[j]) != mp.end()) 
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                {
                    len--;
                }
            }
            if(len == 0)
            {
                while(len == 0)
                {
                    if(endWin > j-i+1)
                    {
                        startWin = i, endWin = j-i+1;
                    }
                    if(mp.find(s[i]) != mp.end())
                    {
                        if(mp[s[i]] == 0)
                        {
                            len++;
                        }
                        mp[s[i]]++;
                    }
                    i++;
                }
            }
        }
        return (endWin == 1e9) ? ("") : (s.substr(startWin, endWin));
    }
};
