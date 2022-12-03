// Code 1 - Number of Students Unable to Eat Lunch

class Solution {
public:
  /*
   * Idea is to handle cases where no student wants the above plate. When handled normally gives tle so we keep track of number of rotations students peform.
   * if rotations is equal or greater than size of students, we know for a fact that no student wants that plate hence return answer = size of students.
   * Other code is self-explainatory.
   */
    int countStudents(vector<int>& stud, vector<int>& sand) {
        queue<int> q;
        for(int &s : stud) q.push(s);
        int rotations = 0, i = 0; // i is index for plates.
        while(!q.empty() and i < size(sand) and rotations < size(stud)) {
            int student = q.front(); q.pop();
            if(student == sand[i]) {
                i++;
                rotations = 0;
            }
            else {
                rotations += 1;
                q.push(student);
            }
        }
        return q.size();
    }
};

// Code 2 - Product of the Last K Numbers

// Approach 1
class ProductOfNumbers {
public:
/*
 * my Intution suggests implimentation of stack 
 * but this solution gives TLE 30/33 test cases
 */
    stack<int> s1, s2;
  
    ProductOfNumbers() { }
    
    void add(int num) {
        s1.push(num);
    }
    
    int getProduct(int k) {
        int product = 1;
        while(!s1.empty() and k--) {
            int num = s1.top();
            s2.push(num); s1.pop();
            product *= num;
        }
      
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
      
        return product;
    }
};
  
// Approach 2 - To be Written (Queue)
class ProductOfNumbers {
public:
  /*
   * We reinitialize our elements to 1 when encountered 0 due to fact that it will make
   * our answer zero, and one because it is the least number to make answer.
   */
    vector<int> elements = {1};
    ProductOfNumbers() {  }
    
    void add(int num) {
        if(num != 0) {
            elements.push_back(elements.back() * num);
        } else elements = {1};
    }
    
    int getProduct(int k) {
        int n = size(elements);
        return k < n ? (elements.back()/elements[n-k-1]) : 0;
    }
};

// Code 3 - Sliding Window Maximum
/*
 * Typical Sliding window with catch to remove elements from front,
 * Implimented that using deque data structure.
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int &k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0, j = 0; j < size(nums); ++j) {
            while(!dq.empty() and nums[j] > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(nums[j]);
            if (j - i + 1 == k) {
                res.push_back(dq.front());
                if(nums[i] == dq.front()) {
                    dq.pop_front();
                }
                i++;
            }
        }
        return res;
    }
};
