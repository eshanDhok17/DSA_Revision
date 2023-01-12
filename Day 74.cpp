// Question 1 - Largest subarray of 0's and 1's


// Question 2 - Longest Sub-Array with Sum K
class Solution
{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int sum = 0, res = 0;
        for(int i=0; i<n; i++)
        {
            sum += a[i];
            if(sum == k) res = i+1; // wrt to indexing
            else if(mp.count(sum - k)) 
            {
                res = max(res, i - mp[sum - k]);
            }
            if(mp.count(sum) == 0) 
            {
                mp[sum] = i;
            }
        }
        return res;
    }
};

// Question 3 - Subarray Sums Divisible by K
class Solution 
{
public:
    /* Basically 
        do same remainder ke bich ka subarray k se divisible hoga
        aur uski frequency jo hai, wo indicate karegi ki kitne aise subarrays hai jo
        divisible by k hai.
        Equation:
            S1 % k = x, S2 % k = x
            to basically,
            S1 = k*n + x (n is length of subarray, kn + 'x' (remainder))
            S2 = k*m + x (m is length of subarray, km + 'x' (remainder))
            therefore,
            S1 - S2 = k(n-m). Which means that S1 - S2 subarray is divisible by k
            to dhundo aise do subarray starting from start, jinka divisor same hai,
            unke bich ka subarray ka sum divisible hoga k se.
            
        --Edge case: Agar remainder negative ja ra ahi to:
    */
    
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        unordered_map<int,int>map; map[0]=1;
        int count = 0, sum = 0;
        for(int i=0; i<nums.size(); i++) 
        {
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0) remainder += k;
            if(map.find(remainder) != map.end())
            {
                count += map[remainder];
            }
            map[remainder]++;
        }
        return count;
    }
};
