//Question 1 nlogn
class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(begin(s), end(s));
        return (s[1] - 48)*10 + (s[2] - 48) + (s[0] - 48)*10 + (s[3] - 48);
    }
};

//Question 2 n
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd, even;
        for(int &i : nums) (i & 1) ? odd.push_back(i) : even.push_back(i);
        for(int &i : odd) even.push_back(i);
        odd.clear(); nums.clear();
        return even;
    }
};

//Question 3 nlogn
class Solution {
public:
    string sortSentence(string rs) {
        vector<string> temp;
        map<int, string> mp;
        int i = 0, j = 0;
        for(; j < rs.size(); j++) {
            if(rs[j] != ' ') continue;
            else {
                temp.push_back(rs.substr(i, j-i));
                i=j+1;
            }
        }
        temp.push_back(rs.substr(i,j));
        for(string &s : temp) {
            int temp = s.back(); s.pop_back();
            mp[temp] = s;
        }
        rs.clear();
        for(auto i : mp) rs += i.second + ' ';
        rs.pop_back(); temp.clear(); mp.clear();
        return rs;
    }
};

//Question 4 nlogn
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        int n = size(names)-1;
        vector<string> res(n+1);
        for(int i = 0; i < names.size(); i++) mp[heights[i]] = names[i];
        for(auto i : mp) res[n--] = i.second;
        mp.clear();
        return res;
    }
};

//Question 5 n
class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        int i =0, j= n-1;
        while(i < j) {
            if(arr[i]) swap(arr[i], arr[j--]);
            else i++;
        }
    }
};