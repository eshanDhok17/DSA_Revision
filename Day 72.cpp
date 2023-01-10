// Question 1 - Employee Importance
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        // vector<vector<int>> adj;
        map<int, pair<int, vector<int>>> mp;
        for(auto &e : employees) {
            mp[e->id] = {e->importance, e->subordinates};
        }
        int sum = 0;
        queue<int> q;
        q.push(id);
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int imp = mp[it].first;
            vector<int> children = mp[it].second;
            sum += imp;
            for(int &val : children) {
                q.push(val);
            }
        }
        return sum;
    }
};

// Question 2 - Check If Array Pairs Are Divisible by k
// O(n) space
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int &num : arr) {
            int rem = num % k;
            int a = -rem;
            int b = rem > 0 ? k - rem : -(k+rem);
            
            /* 
               map isliye kyuki, map me aisa koi value remainder
               hai kya jo complimentary hai to e to be divisible by k
               for ex-
               mp [3, 1] pada hai when 3 was iterated
               e = 7, k = 5
               rem = 7 % 5 = 2
               we have two options, two compliments,
               either we add or substract. what? -rem or k-rem for rem > 0 or -(k+rem);
               -> is there -k in map? to add to get divisiblity? - No
               -> is there k-rem or -(k+rem) in map? yes, 5-2 = 3. we have one number
               which can compliment
               the current number which is e
               we decrease the unknown compliment number's frequency.
               if it is zero we have two pairs and 0 non pair numbers
               if we still have any frequency left, we have a pair and some unpair numbers
               
           */
            if(mp[a]) {
                mp[a]--;;
            }
            else if(mp[b]) {
                mp[b]--;
            }
            else {
                mp[rem] += 1;
            }
        }
        for(auto &[a, b] : mp) {
            if(b != 0) return false;
        }
        return true;
    }
};

// O(1) space - not for all test cases
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // if we have 1 pair that is sum of two numbers,
        // divisible by k then it is valid
        // so if we have sum of all numbers and it is divisible by k it is valid
        int n = arr.size();
        long sum = accumulate(begin(arr), end(arr), 0LL);
        return (sum % k == 0 and sum >= k * (n/2));
    }
};

// Question 3 - Count distinct elements in every window

class Solution {
  public:
    vector <int> countDistinct (int arr[], int n, int k) {
        vector<int> res;
        unordered_map<int, int> mp;
        int i=0, j=0;
        while(j < n) {
            mp[arr[j]]++;
            if(j-i+1 == k) {
                int uniq = mp.size();
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
                res.push_back(uniq);
            }
            j++;
        }
        return res;
    }
};