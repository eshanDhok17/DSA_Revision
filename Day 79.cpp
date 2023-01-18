// Code - 1 Max Consecutive Ones III

class Solution {
public:
/*
	O(1) space, O(N) time.
	basically find out ans for condition.
	we can have atmost k zeros so the subarray consists of max 1's.
	so sum of 1's = window size.
	hence, (Sum + k >= window size) is our answer.
*/
    int longestOnes(vector<int>& A, int k) {
        long long sum = 0;
		int ans = 0;
        for(int i=0, j=0; j<size(A); j++) {
            sum += A[j];
            if(sum + k >= j-i+1)
                ans = max((ans, j-i+1);
            while(sum + k < j-i+1) sum -= A[i++];
        }
        return ans;
    }
};
                          
// Code - 2 Substring With At Least K Distinct Characters
