class Solution {
public:
    int helper(int n) {
        int sum = 0;
        while(n != 0) {
            int remainder = n % 10;
            int a = remainder*remainder;
            sum = a + sum;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        set<int> s;
        
        while(n != 1 && s.find(n) == s.end()) {
            s.insert(n);
            n = helper(n);
        }
        return n==1;
    }
};